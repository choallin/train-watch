#ifndef COUNTRY_H
#define COUNTRY_H

#include <QObject>
#include <QVariantMap>

class Country: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString uuid READ uuid WRITE setUuid NOTIFY uuidChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)

private:
    QString m_uuid;
    QString m_name;

public:
    Country(QObject *parent = 0);
    Country(const QString& uuid, const QString& name, QObject *parent = 0);
    ~Country();

    inline QString uuid() const { return m_uuid; }
    void setUuid(const QString& uuid);

    inline QString name() const { return m_name; }
    void setName(const QString& name);

    Q_INVOKABLE
    QString toS() const;

    void fillFromCacheMap(const QVariantMap& map);
    QVariantMap toCacheMap() const;

Q_SIGNALS:
    void uuidChanged(QString);
    void nameChanged(QString);

public:
    Q_DISABLE_COPY (Country)
};
Q_DECLARE_METATYPE(Country*)

#endif // COUNTRY_H
