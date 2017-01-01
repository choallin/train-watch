#include <QDebug>

#include "watchitem.h"

WatchItem::WatchItem(QObject* parent) :
    QObject(parent),
    m_title(QString()),
    m_country(new Country()),
    m_station(new Station("1", "Station1")),
    m_line(QString()),
    m_pickUpTime(QTime(10,0,0)),
    m_weekDays(QStringList{"1","2","3"}),
    m_offset(20),
    m_active(false)
{
}

WatchItem::~WatchItem()
{

}

QString WatchItem::toS() const
{
    return QString("WatchItem(%1, %2, %3, %4, %5, %6, %7, %8)")
            .arg(m_title)
            .arg(m_country ? m_country->toS() : "NULL")
            .arg(m_station ? m_station->toS() : "NULL")
            .arg(m_line)
            .arg(m_pickUpTime.toString("hh:mm:ss"))
            .arg(m_weekDays.join("-"))
            .arg(m_offset)
            .arg(m_active);
}

void WatchItem::setTitle(const QString& title)
{
    if(m_title != title){
        m_title = title;
        emit titleChanged();
    }
}

void WatchItem::setCountry(Country *country)
{
    if(m_country){
        delete m_country;
    }
    country->setParent(this);
    m_country = country;
    emit countryChanged();
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

void WatchItem::setWeekDays(const QStringList &weekDays)
{
    if(m_weekDays != weekDays){
        m_weekDays = weekDays;
        emit weekDaysChanged();
    }
}

bool WatchItem::isValid() const
{
    return !m_title.isEmpty() &&
           !m_country->uuid().isEmpty() &&
           !m_station->uuid().isEmpty() &&
           !m_line.isEmpty() &&
           m_pickUpTime.isValid() &&
           m_offset >= 0;
}

void WatchItem::fillFromCacheMap(const QVariantMap& map)
{
    m_title = map.value("title").toString();
    Country* country = new Country(this);
    country->fillFromCacheMap(map.value("country").toMap());
    setCountry(country);
    Station* station = new Station(this);
    station->fillFromCacheMap(map.value("station").toMap());
    setStation(station);
    m_line = map.value("line").toString();
    m_pickUpTime = map.value("pickUpTime").toTime();
    m_weekDays = map.value("weekDays").toStringList();
    m_offset = map.value("offset").toInt();
    m_active = map.value("active").toBool();
}

QVariantMap WatchItem::toCacheMap() const
{
    QVariantMap map;
    map.insert("title", title());
    map.insert("country", country()->toCacheMap());
    map.insert("station", station()->toCacheMap());
    map.insert("line", line());
    map.insert("pickUpTime", pickUpTime());
    map.insert("weekDays", weekDays());
    map.insert("offset", offset());
    map.insert("active", active());
    return map;
}
