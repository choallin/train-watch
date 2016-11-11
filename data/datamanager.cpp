#include <QtQml>

#include "datamanager.h"

DataManager::DataManager(QObject* parent):
    QObject(parent)
{
    qmlRegisterType<WatchItem>("org.trainwatch.data", 1, 0, "WatchItem");
}

DataManager::~DataManager()
{

}

WatchItem* DataManager::createWatchItem()
{
    WatchItem* watchItem = new WatchItem(this);
    return watchItem;
}
