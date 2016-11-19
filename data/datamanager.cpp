#include <QtQml>

#include "datamanager.h"

DataManager::DataManager(QObject* parent):
    QObject(parent)
{
    qmlRegisterType<WatchItem>("org.trainwatch.data", 1, 0, "WatchItem");
    qmlRegisterType<Station>("org.trainwatch.data", 1, 0, "Station");
}

DataManager::~DataManager()
{

}

WatchItem* DataManager::createWatchItem()
{
    WatchItem* watchItem = new WatchItem(this);
    return watchItem;
}

void DataManager::appendWatchItem(WatchItem* watchItem)
{
    watchItem->setParent(this);
    mWatchItems.append(watchItem);
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
        dataManager->mWatchItems.append(watchItem);
        emit dataManager->addedToWatchItems(watchItem);
    } else {
        qWarning() << "cannot append WatchItem to WatchItems";
    }
}

int DataManager::watchItemPropertyCount(QQmlListProperty<WatchItem>* watchItemList)
{
    DataManager* dataManager = qobject_cast<DataManager*>(watchItemList->object);
    if(dataManager){
        return dataManager->mWatchItems.size();
    }
    else {
        qWarning() << "cannot get count of WatchItems";
    }
    return 0;
}

WatchItem* DataManager::atWatchItemProperty(QQmlListProperty<WatchItem>* watchItemList, int pos)
{
    DataManager* dataManager = qobject_cast<DataManager*>(watchItemList->object);
    if (dataManager){
        if(dataManager->mWatchItems.size() > pos){
            return static_cast<WatchItem*>(dataManager->mWatchItems.at(pos));
        }
        qWarning() << "cannot get WatchItem* at pos " << pos << " size is " << dataManager->mWatchItems.size();
    }
    else{
        qWarning() << "cannot get WatchItem* at pos " << pos;
    }
    return 0;
}
void DataManager::clearWatchItemProperty(QQmlListProperty<WatchItem>* watchItemList)
{
    DataManager* dataManager = qobject_cast<DataManager*>(watchItemList->object);
    if(dataManager){
        for(int i = 0; i < dataManager->mWatchItems.size(); ++i) {
            WatchItem* watchItem;
            watchItem = static_cast<WatchItem*>(dataManager->mWatchItems.at(i));
            emit dataManager->deletedFromWatchItems(watchItem);
            watchItem->deleteLater();
            watchItem = 0;
        }
        dataManager->mWatchItems.clear();
    }else{
        qWarning() << "cannot clear WatchItems";
    }
}
