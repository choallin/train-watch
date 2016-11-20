#include <QtQml>

#include "datamanager.h"

static const QString ENV = "prod";

DataManager::DataManager(QObject* parent):
    QObject(parent)
{
    m_dataRoot = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).value(0);
    m_dataPath = m_dataRoot+"/data/";

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

void DataManager::initializeWatchItemsFromCache()
{
    m_watchItems.clear();
    QVariantList cacheList = readfromCache("watchItems");

    QListIterator<QVariant> lit(cacheList);
    while(lit.hasNext()) {
        QVariantMap cacheMap = lit.next().toMap();
        WatchItem* watchItem = new WatchItem();
        // Important: DataManager must be parent of all root DTOs
        watchItem->setParent(this);
        watchItem->fillFromCacheMap(cacheMap);
        m_watchItems.append(watchItem);
    }

    qDebug() << "created WatchItem* #" << m_watchItems.size();
}

WatchItem* DataManager::createWatchItem()
{
    WatchItem* watchItem = new WatchItem(this);
    return watchItem;
}

void DataManager::appendWatchItem(WatchItem* watchItem)
{
    watchItem->setParent(this);
    m_watchItems.append(watchItem);
    emit addedToWatchItems(watchItem);
    emit watchItemPropertyListChanged();
}

QQmlListProperty<WatchItem> DataManager::watchItemPropertyList()
{
    return QQmlListProperty<WatchItem>(this, 0,&DataManager::appendToWatchItemProperty, &DataManager::watchItemPropertyCount, &DataManager::atWatchItemProperty, &DataManager::clearWatchItemProperty);
}

void DataManager::appendToWatchItemProperty(QQmlListProperty<WatchItem>* watchItemList, WatchItem* watchItem)
{
    DataManager* dataManager = qobject_cast<DataManager*>(watchItemList->object);
    if(dataManager){
        watchItem->setParent(dataManager);
        dataManager->m_watchItems.append(watchItem);
        emit dataManager->addedToWatchItems(watchItem);
    }
    else {
        qWarning() << "cannot append WatchItem to WatchItems";
    }
}

int DataManager::watchItemPropertyCount(QQmlListProperty<WatchItem>* watchItemList)
{
    DataManager* dataManager = qobject_cast<DataManager*>(watchItemList->object);
    if(dataManager){
        return dataManager->m_watchItems.size();
    }
    else{
        qWarning() << "cannot get count of WatchItems";
    }
    return 0;
}

WatchItem* DataManager::atWatchItemProperty(QQmlListProperty<WatchItem>* watchItemList, int pos)
{
    DataManager* dataManager = qobject_cast<DataManager*>(watchItemList->object);
    if (dataManager){
        if(dataManager->m_watchItems.size() > pos){
            return static_cast<WatchItem*>(dataManager->m_watchItems.at(pos));
        }
        qWarning() << "cannot get WatchItem* at pos " << pos << " size is " << dataManager->m_watchItems.size();
    }
    else{
        qWarning() << "cannot get WatchItem* at pos %s" << pos;
    }
    return 0;
}
void DataManager::clearWatchItemProperty(QQmlListProperty<WatchItem>* watchItemList)
{
    DataManager* dataManager = qobject_cast<DataManager*>(watchItemList->object);
    if(dataManager){
        for(int i = 0; i < dataManager->m_watchItems.size(); ++i) {
            WatchItem* watchItem;
            watchItem = static_cast<WatchItem*>(dataManager->m_watchItems.at(i));
            emit dataManager->deletedFromWatchItems(watchItem);
            watchItem->deleteLater();
            watchItem = 0;
        }
        dataManager->m_watchItems.clear();
    }
    else{
        qWarning() << "cannot clear WatchItems";
    }
}
