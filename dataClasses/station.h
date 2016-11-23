#ifndef STATION_H
#define STATION_H

#include <QDebug>
#include <QObject>
#include <QTime>

class Station: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString uuid READ uuid WRITE setUuid NOTIFY uuidChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)

private:
    QString m_uuid;
    QString m_name;

public:
    Station(QObject *parent = 0);
    Station(const QString& uuid, const QString& name, QObject *parent = 0);
    ~Station();

    inline QString uuid() const { return m_uuid; }
    inline void setUuid(const QString& uuid) { m_uuid = uuid; }

    inline QString name() const { return m_name; }
    inline void setName(const QString& name) { m_name = name; }

    Q_INVOKABLE
    QString toS() const;

    void fillFromCacheMap(const QVariantMap& map);
    QVariantMap toCacheMap() const;

Q_SIGNALS:
    void uuidChanged(QString);
    void nameChanged(QString);

public:
    Q_DISABLE_COPY (Station)
};
Q_DECLARE_METATYPE(Station*)

#endif // STATION_H
