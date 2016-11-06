#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "../dataClasses/watchitem.h"

class DataManager: public QObject
{
    Q_OBJECT

public:
    DataManager(QObject *parent = 0);
    ~DataManager();

    Q_INVOKABLE
    WatchItem* createWatchItem();
};

#endif // DATAMANAGER_H
