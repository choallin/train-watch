#include "country.h"

Country::Country(QObject* parent) :
    QObject(parent),
    m_uuid(QString()),
    m_name(QString())
{
}

Country::Country(const QString& uuid, const QString& name, QObject *parent) :
    QObject(parent),
    m_uuid(uuid),
    m_name(name)
{
}


Country::~Country()
{
}

QString Country::toS() const
{
    return QString("Country(%1, %2)")
            .arg(m_uuid)
            .arg(m_name);
}

void Country::setUuid(const QString &uuid)
{
    m_uuid = uuid;
    emit uuidChanged(m_uuid);
}

void Country::setName(const QString &name)
{
    m_name = name;
    emit nameChanged(m_name);
}

void Country::fillFromCacheMap(const QVariantMap& map)
{
    m_uuid = map.value("uuid").toString();
    m_name = map.value("name").toString();
}

QVariantMap Country::toCacheMap() const
{
    QVariantMap map;
    map.insert("uuid", uuid());
    map.insert("name", name());
    return map;
}
