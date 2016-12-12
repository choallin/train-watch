#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QQmlListProperty>

#include "../dataClasses/watchitem.h"

class DataManager: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<WatchItem> watchItemPropertyList READ watchItemPropertyList NOTIFY watchItemPropertyListChanged)

private:
    QString m_dataRoot;
    QString m_dataPath;

public:
    DataManager(QObject *parent = 0);
    ~DataManager();

    Q_INVOKABLE
    void initialize();

    QQmlListProperty<WatchItem> watchItemPropertyList();

    Q_INVOKABLE
    WatchItem* createWatchItem();

    Q_INVOKABLE
    void undoCreateWatchItem(WatchItem* watchItem);

    Q_INVOKABLE
    void appendWatchItem(WatchItem* watchItem);

signals:
    void watchItemPropertyListChanged();
    void addedToWatchItems(WatchItem* watchItem);
    void deletedFromWatchItems(WatchItem* watchItem);

private:
    bool createPathsIfNotExists();
    QString dataPath(const QString& filename);
    QVariantList readfromCache(const QString& filename);
    void writeToCache(const QString& filename, QVariantList& data);

    QList<QObject*> m_watchItems;

    void initializeWatchItemsFromCache();
    void saveWatchItemsToCache();

    static void appendToWatchItemProperty(QQmlListProperty<WatchItem>* watchItemList, WatchItem* watchItem);
    static int watchItemPropertyCount(QQmlListProperty<WatchItem>* watchItemList);
    static WatchItem* atWatchItemProperty(QQmlListProperty<WatchItem>* watchItemList, int pos);
    static void clearWatchItemProperty(QQmlListProperty<WatchItem>* WatchItemList);
};

#endif // DATAMANAGER_H
