#include <QDebug>

#include "station.h"

Station::Station(QObject* parent) :
    QObject(parent),
    m_uuid(QString()),
    m_name(QString())
{
}

Station::Station(const QString& uuid, const QString& name, QObject *parent) :
    QObject(parent),
    m_uuid(uuid),
    m_name(name)
{
}


Station::~Station()
{

}

QString Station::toS() const
{
    return QString("Station(%1, %2)")
            .arg(m_uuid)
            .arg(m_name);
}

void Station::fillFromCacheMap(const QVariantMap& map)
{
    m_uuid = map.value("uuid").toString();
    m_name = map.value("name").toString();
}

QVariantMap Station::toCacheMap() const
{
    QVariantMap map;
    map.insert("uuid", uuid());
    map.insert("name", name());
    return map;
}
