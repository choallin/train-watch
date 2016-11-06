#include "datamanager.h"

DataManager::DataManager(QObject* parent):
    QObject(parent)
{

}

DataManager::~DataManager()
{

}

WatchItem* DataManager::createWatchItem()
{
    WatchItem* watchItem = new WatchItem(this);
    return watchItem;
}
