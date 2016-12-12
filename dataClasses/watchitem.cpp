#include <QDebug>

#include "watchitem.h"

WatchItem::WatchItem(QObject* parent) :
    QObject(parent),
    m_title(QString()),
    m_country(QString()),
    m_station(new Station("1", "Station1")),
    m_line(QString()),
    m_pickUpTime(QTime(10,0,0)),
    m_offset(20),
    m_active(false)
{
}

WatchItem::~WatchItem()
{

}

QString WatchItem::toS() const
{
    return QString("WatchItem(%1, %2, %3, %4, %5, %6, %7)")
            .arg(m_title)
            .arg(m_country)
            .arg(m_station ? m_station->toS() : "NULL")
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
    station->setParent(this);
    m_station = station;
    emit stationChanged();

}

void WatchItem::setPickUpTime(const QTime &pickUpTime)
{
    m_pickUpTime = pickUpTime;
    emit pickUpTimeChanged();
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

void WatchItem::fillFromCacheMap(const QVariantMap& map)
{
    m_title = map.value("title").toString();
    m_country = map.value("country").toString();
    Station* station = new Station(this);
    station->fillFromCacheMap(map.value("station").toMap());
    setStation(station);
    m_line = map.value("line").toString();
    m_pickUpTime = map.value("pickUpTime").toTime();
    m_offset = map.value("offset").toInt();
    m_active = map.value("active").toBool();
}

QVariantMap WatchItem::toCacheMap() const
{
    QVariantMap map;
    map.insert("title", title());
    map.insert("country", country());
    map.insert("station", station()->toCacheMap());
    map.insert("line", line());
    map.insert("pickUpTime", pickUpTime());
    map.insert("offset", offset());
    map.insert("active", active());
    return map;
}
