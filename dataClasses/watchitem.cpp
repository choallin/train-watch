#include <QDebug>

#include "watchitem.h"

WatchItem::WatchItem(QObject* parent) :
    QObject(parent),
    m_title(QString()),
    m_country(QString()),
    m_station(new Station()),
    m_line(QString()),
    m_pickUpTime(QTime(0,0,0)),
    m_offset(20),
    m_active(false)

{
}

WatchItem::~WatchItem()
{

}

QString WatchItem::toString() const
{
    return QString("WatchItem(%1, %2, %3, %4, %5, %6, %7)")
            .arg(m_title)
            .arg(m_country)
            .arg(m_station ? m_station->toString() : "NULL")
            .arg(m_line)
            .arg(m_pickUpTime.toString("hh:mm:ss"))
            .arg(m_offset)
            .arg(m_active);
}

void WatchItem::setStation(Station *station)
{
    if(m_station){
        delete m_station;
    }
    m_station = station;
}

bool WatchItem::isValid() const
{
    return !m_title.isEmpty() &&
           !m_country.isEmpty() &&
           !m_station->uuid().isEmpty() &&
           !m_line.isEmpty() &&
           m_pickUpTime.isValid() &&
           m_offset >= 0;
}
