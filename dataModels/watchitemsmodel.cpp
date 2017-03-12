#include <QDebug>

#include "watchitemsmodel.h"

WatchItemsModel::WatchItemsModel(QObject* parent, QList<WatchItem*>* watchItems) :
    QAbstractListModel(parent),
    m_watchItems(watchItems)
{
}

WatchItemsModel::~WatchItemsModel()
{
}

void WatchItemsModel::setWatchItems(QList<WatchItem*>* watchItems)
{
    m_watchItems = watchItems;
}

int WatchItemsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    if(!m_watchItems){
        return 0;
    }

    return m_watchItems->size();
}

QVariant WatchItemsModel::data(const QModelIndex &index, int role) const
{
    if(!m_watchItems){
        return QVariant();
    }
    if (index.row() < 0 || index.row() >= rowCount())
        return QVariant();

    WatchItem const * const watchItem = m_watchItems->at(index.row());

    if(role == UuidRole){
        return watchItem->uuid();
    }
    else if(role == TitleRole){
        return watchItem->title();
    }
    else if(role == ActiveRole){
        return watchItem->active();
    }
    else if(role == StationRole){
        return watchItem->station()->name();
    }
    else if(role == LineRole){
        return watchItem->schedule()->line();
    }
    else if(role == DepartureRole){
        return watchItem->schedule()->departure();
    }
    else if(role == WeekDaysRole){
        return watchItem->weekDays();
    }
    else{
        return QVariant();
    }
}

QHash<int, QByteArray> WatchItemsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[UuidRole]      = "uuid";
    roles[TitleRole]     = "title";
    roles[ActiveRole]    = "active";
    roles[StationRole]   = "station";
    roles[LineRole]      = "line";
    roles[DepartureRole] = "departure";
    roles[WeekDaysRole]  = "weekdays";

    return roles;
}

void WatchItemsModel::appendWatchItem(WatchItem* watchItem)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_watchItems->append(watchItem);
    endInsertRows();
}

WatchItem* WatchItemsModel::findWatchItem(const QString& uuid)
{
    return m_watchItems->at(indexForData(UuidRole, uuid).row());
}

void WatchItemsModel::watchItemSaved(WatchItem* watchItem)
{
    QModelIndex matchIndex = indexForData(UuidRole, watchItem->uuid());
    emit dataChanged(matchIndex, matchIndex);
}

QModelIndex WatchItemsModel::indexForData(const int role, const QString& data)
{
    QModelIndexList matches = match(this->index(0, 0), role, data, 1, Qt::MatchExactly);
    if(matches.count() != 1){
        qFatal("more than one matches at indexForData role: %s,  data: %s", qPrintable(QString::number(role)), qPrintable(data));
    }
    return matches.first();
}

