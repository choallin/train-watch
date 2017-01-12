#include "schedule.h"

Schedule::Schedule(QObject* parent) :
    QObject(parent),
    m_id(QString()),
    m_line(QString()),
    m_departure(QTime()),
    m_direction(QString())
{
}

Schedule::Schedule(const QString &id, const QString& line, const QTime& departure, const QString& direction, QObject *parent) :
    QObject(parent),
    m_id(id),
    m_line(line),
    m_departure(departure),
    m_direction(direction)
{
}


Schedule::~Schedule()
{
}

QString Schedule::toS() const
{
    return QString("Schedule(%1, %2, %3, %4)")
            .arg(m_id)
            .arg(m_line)
            .arg(m_departure.toString("hh:mm"))
            .arg(m_direction);
}

void Schedule::setId(const QString &id)
{
    if(m_id != id){
        m_id = id;
        emit idChanged(m_id);
    }
}

void Schedule::setLine(const QString &line)
{
    if(m_line != line){
        m_line = line;
        emit lineChanged(m_line);
    }
}

void Schedule::setDeparture(const QTime &departure)
{
    if(m_departure != departure){
        m_departure = departure;
        emit departureChanged(m_departure);
    }
}

void Schedule::setDirection(const QString &direction)
{
    if(m_direction != direction){
        m_direction = direction;
        emit directionChanged(m_direction);
    }
}

void Schedule::fillFromCacheMap(const QVariantMap& map)
{
    m_id = map.value("id").toString();
    m_line = map.value("line").toString();
    m_departure = map.value("departure").toTime();
    m_direction = map.value("direction").toString();
}

QVariantMap Schedule::toCacheMap() const
{
    QVariantMap map;
    map.insert("id", id());
    map.insert("line", line());
    map.insert("departure", departure());
    map.insert("direction", direction());
    return map;
}
