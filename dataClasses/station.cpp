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

QString Station::toString() const
{
    return QString("Station(%1, %2)")
            .arg(m_uuid)
            .arg(m_name);
}
