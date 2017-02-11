#include <QtQml>

#include "datamanager.h"

static const QString ENV = "prod";

DataManager::DataManager(QObject* parent):
    QObject(parent)
{
    m_dataRoot = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).value(0);
    m_dataPath = m_dataRoot+"/data/";
    m_watchItemsModel = new WatchItemsModel(this);

    if(!createPathsIfNotExists()){
        qFatal("FATAL error at DataManger init! App is not able to create data-paths ('%s', '%s')", qPrintable(m_dataRoot), qPrintable(m_dataPath));
        return;
    }

    qmlRegisterType<WatchItem>("org.trainwatch.data", 1, 0, "WatchItem");
    qmlRegisterType<Station>("org.trainwatch.data", 1, 0, "Station");
}

DataManager::~DataManager()
{

}

bool DataManager::createPathsIfNotExists()
{
    QDir dir;
    if(!dir.exists(m_dataRoot) && !dir.mkpath(m_dataRoot)) {
        qWarning("Path '%s' could not be created", qPrintable(m_dataRoot));
        return false;
    }

    if(!dir.exists(m_dataPath) && !dir.mkpath(m_dataPath)) {
        qWarning("Path '%s' could not be created", qPrintable(m_dataPath));
        return false;
    }

    QString environmentPath = m_dataPath + "/" + ENV + "/";
    if(!dir.exists(environmentPath) && !dir.mkpath(environmentPath)) {
        qWarning("Path '%s' could not be created", qPrintable(environmentPath));
        return false;
    }

    return true;
}

QString DataManager::dataPath(const QString& filename)
{
    return m_dataPath + ENV + "/" + filename;
}

void DataManager::initialize()
{
    initializeWatchItemsFromCache();
    m_watchItemsModel->setWatchItems(m_watchItemList);
}

QVariantList DataManager::readfromCache(const QString& filename)
{
    QVariantList cacheList;
    QString cacheFilePath = dataPath(filename);
    QFile dataFile(cacheFilePath);

    if(dataFile.exists()){
        if(!dataFile.open(QIODevice::ReadOnly)){
            qWarning("File '%s' could not be opened", qPrintable(cacheFilePath));
        }

        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument().fromJson(dataFile.readAll(), &jsonError);
        if(jsonError.error != QJsonParseError::NoError) {
            qWarning("Json Parse Error at '%s'-cache! Error: '%s'", qPrintable(filename), qPrintable(jsonError.errorString()));
            return cacheList;
        }

        cacheList = jsonDoc.toVariant().toList();
        return cacheList;
    }
    else{
        qDebug("'%s-cache does not exists yet!", qPrintable(filename));
        return cacheList;
    }
}

void DataManager::writeToCache(const QString& filename, QVariantList& data)
{
    QString cacheFilePath = dataPath(filename);
    QJsonDocument jsonDoc = QJsonDocument::fromVariant(data);

    QFile saveFile(cacheFilePath);
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open file '%s' to write", qPrintable(cacheFilePath));
        return;
    }
    qint64 bytesWritten = saveFile.write(jsonDoc.toJson(QJsonDocument::Compact));
    saveFile.close();
    qDebug("%s bytes written to %s", qPrintable(QString::number(bytesWritten)), qPrintable(cacheFilePath));
}

void DataManager::saveWatchItemsToCache()
{
    QVariantList cacheList;
    QList<WatchItem*>* watchItems = m_watchItemsModel->watchItems();
    qDebug("now saving %s WatchItems", qPrintable(QString::number(watchItems->size())));
    QListIterator<WatchItem*> lit(*watchItems);
    while(lit.hasNext()){
        const WatchItem* watchItem = lit.next();
        QVariantMap cacheMap;
        cacheMap = watchItem->toCacheMap();
        cacheList.append(cacheMap);
    }
    writeToCache("watchItems", cacheList);
}

void DataManager::initializeWatchItemsFromCache()
{
    m_watchItemList = new QList<WatchItem*>();
    QVariantList cacheList = readfromCache("watchItems");

    QListIterator<QVariant> lit(cacheList);
    while(lit.hasNext()) {
        QVariantMap cacheMap = lit.next().toMap();
        WatchItem* watchItem = new WatchItem();
        // Important: DataManager must be parent of all root DTOs
        watchItem->setParent(this);
        watchItem->fillFromCacheMap(cacheMap);
        m_watchItemList->append(watchItem);
    }

    qDebug("%s watchItems created", qPrintable(QString::number(m_watchItemList->size())));
}

WatchItem* DataManager::watchItemAt(const int index)
{
    return m_watchItemsModel->watchItemAt(index);
}

WatchItem* DataManager::createWatchItem()
{
    WatchItem* watchItem = new WatchItem(this);
    return watchItem;
}

void DataManager::undoCreateWatchItem(WatchItem* watchItem)
{
    if(watchItem) {
        watchItem->deleteLater();
        watchItem = 0;
    }
}

void DataManager::appendWatchItem(WatchItem* watchItem)
{
    watchItem->setParent(this);
    m_watchItemsModel->appendWatchItem(watchItem);
    saveWatchItemsToCache();
    emit addedToWatchItems(watchItem);
}

void DataManager::saveWatchItem(const int index, WatchItem* watchItem)
{
    saveWatchItemsToCache();
    m_watchItemsModel->watchItemSaved(index);
    emit addedToWatchItems(watchItem);
}
