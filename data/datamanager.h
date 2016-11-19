#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QQmlListProperty>

#include "../dataClasses/watchitem.h"

class DataManager: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<WatchItem> watchItemPropertyList READ watchItemPropertyList NOTIFY watchItemPropertyListChanged)

public:
    DataManager(QObject *parent = 0);
    ~DataManager();

    QQmlListProperty<WatchItem> watchItemPropertyList();

    Q_INVOKABLE
    WatchItem* createWatchItem();

    Q_INVOKABLE
    void appendWatchItem(WatchItem* watchItem);

signals:
    void watchItemPropertyListChanged();
    void addedToWatchItems(WatchItem* watchItem);
    void deletedFromWatchItems(WatchItem* watchItem);

private:
    QList<QObject*> mWatchItems;

    static void appendToWatchItemProperty(QQmlListProperty<WatchItem>* watchItemList, WatchItem* watchItem);
    static int watchItemPropertyCount(QQmlListProperty<WatchItem>* watchItemList);
    static WatchItem* atWatchItemProperty(QQmlListProperty<WatchItem>* watchItemList, int pos);
    static void clearWatchItemProperty(QQmlListProperty<WatchItem>* WatchItemList);
};

#endif // DATAMANAGER_H
