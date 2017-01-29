#ifndef WATCHITEMSMODEL_H
#define WATCHITEMSMODEL_H

#include <QAbstractListModel>

#include "../dataClasses/watchitem.h"

class WatchItemsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum WatchItemRoles {
        TitleRole = Qt::UserRole + 1,
        ActiveRole = Qt::UserRole + 2,
        StationRole = Qt::UserRole + 3,
        LineRole = Qt::UserRole + 4,
        DepartureRole = Qt::UserRole + 5,
        WeekDaysRole = Qt::UserRole + 6
    };

private:
    QList<WatchItem*>* m_watchItems;

public:
    WatchItemsModel(QObject *parent, QList<WatchItem*>*watchItems = 0);
    ~WatchItemsModel();

    void setWatchItems(QList<WatchItem*>* watchItems);
    inline QList<WatchItem*>* watchItems() { return m_watchItems; }
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    void appendWatchItem(WatchItem* watchItem);
};

#endif // WATCHITEMSMODEL_H
