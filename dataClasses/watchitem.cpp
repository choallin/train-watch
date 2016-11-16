#include <QDebug>

#include "watchitem.h"

WatchItem::WatchItem(QObject* parent) :
    QObject(parent),
    m_title(QString("Hello World")),
    m_country(QString()),
    m_station(QString()),
    m_line(QString()),
    m_pickUpTime(QTime()),
    m_offset(20),
    m_active(true)

{
}

WatchItem::~WatchItem()
{

}
