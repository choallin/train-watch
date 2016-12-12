#ifndef WATCHITEM_H
#define WATCHITEM_H

#include <QDebug>
#include <QObject>
#include <QTime>

#include "station.h"

class WatchItem: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged FINAL)
    Q_PROPERTY(Station* station READ station WRITE setStation NOTIFY stationChanged FINAL)
    Q_PROPERTY(QString line READ line WRITE setLine NOTIFY lineChanged FINAL)
    Q_PROPERTY(QTime pickUpTime READ pickUpTime WRITE setPickUpTime NOTIFY pickUpTimeChanged FINAL)
    Q_PROPERTY(int offset READ offset WRITE setOffset NOTIFY offsetChanged FINAL)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged FINAL)

private:
    QString m_title;
    QString m_country;
    Station* m_station;
    QString m_line;
    QTime m_pickUpTime;
    int m_offset;
    bool m_active;

public:
    WatchItem(QObject *parent = 0);
    ~WatchItem();

    inline QString title() const { return m_title; }
    inline void setTitle(const QString& title) { m_title = title; }

    inline QString country() const { return m_country; }
    inline void setCountry(const QString& country) { m_country = country; }

    inline Station* station() const { return m_station; }
    void setStation(Station* station);

    inline QString line() const { return m_line; }
    inline void setLine(const QString& line) { m_line = line; }

    inline QTime pickUpTime() const { return m_pickUpTime; }
    void setPickUpTime(const QTime& pickUpTime);

    inline int offset() const { return m_offset; }
    inline void setOffset(const int offset) { m_offset = offset; }

    inline int active() const { return m_active; }
    inline void setActive(const int active) { m_active = active; }

    Q_INVOKABLE
    QString toS() const;

    void fillFromCacheMap(const QVariantMap& map);
    QVariantMap toCacheMap() const;

    Q_INVOKABLE
    bool isValid() const;

Q_SIGNALS:
    void titleChanged(QString);
    void countryChanged(QString);
    void stationChanged();
    void lineChanged(QString);
    void pickUpTimeChanged();
    void offsetChanged(int);
    void activeChanged(bool);

public:
    Q_DISABLE_COPY (WatchItem)
};
Q_DECLARE_METATYPE(WatchItem*)
#endif // WATCHITEM_H
