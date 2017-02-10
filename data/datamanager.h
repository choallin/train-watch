#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QDebug>
#include <QObject>

#include "../dataClasses/watchitem.h"
#include "../dataModels/watchitemsmodel.h"

class DataManager: public QObject
{
    Q_OBJECT

    Q_PROPERTY(WatchItemsModel* watchItemsModel READ watchItemsModel)

private:
    QString m_dataRoot;
    QString m_dataPath;
    WatchItemsModel* m_watchItemsModel;
    QList<WatchItem*>* m_watchItemList;

public:
    DataManager(QObject *parent = 0);
    ~DataManager();

    inline WatchItemsModel* watchItemsModel() { return m_watchItemsModel; }

    Q_INVOKABLE
    void initialize();

    Q_INVOKABLE
    WatchItem* createWatchItem();

    Q_INVOKABLE
    WatchItem* watchItemAt(const int index);

    Q_INVOKABLE
    void undoCreateWatchItem(WatchItem* watchItem);

    Q_INVOKABLE
    void appendWatchItem(WatchItem* watchItem);

    Q_INVOKABLE
    void saveWatchItem(const int index, WatchItem* watchItem);

signals:
    void watchItemPropertyListChanged();
    void addedToWatchItems(WatchItem* watchItem);
    void deletedFromWatchItems(WatchItem* watchItem);

private:
    bool createPathsIfNotExists();
    QString dataPath(const QString& filename);
    QVariantList readfromCache(const QString& filename);
    void writeToCache(const QString& filename, QVariantList& data);

    void initializeWatchItemsFromCache();
    void saveWatchItemsToCache();
};

#endif // DATAMANAGER_H
