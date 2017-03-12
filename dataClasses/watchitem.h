#ifndef WATCHITEM_H
#define WATCHITEM_H

#include <QDebug>
#include <QObject>
#include <QTime>

#include "station.h"
#include "country.h"
#include "schedule.h"

class WatchItem: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString uuid READ uuid WRITE setUuid  NOTIFY uuidChanged FINAL)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
    Q_PROPERTY(Country* country READ country WRITE setCountry NOTIFY countryChanged FINAL)
    Q_PROPERTY(Station* station READ station WRITE setStation NOTIFY stationChanged FINAL)
    Q_PROPERTY(Schedule* schedule READ schedule WRITE setSchedule NOTIFY scheduleChanged FINAL)
    Q_PROPERTY(QTime pickUpTime READ pickUpTime WRITE setPickUpTime NOTIFY pickUpTimeChanged FINAL)
    Q_PROPERTY(QStringList weekDays READ weekDays WRITE setWeekDays NOTIFY weekDaysChanged FINAL)
    Q_PROPERTY(int offset READ offset WRITE setOffset NOTIFY offsetChanged FINAL)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged FINAL)

private:
    QString m_uuid;
    QString m_title;
    Country* m_country;
    Station* m_station;
    Schedule* m_schedule;
    QTime m_pickUpTime;
    QStringList m_weekDays;
    int m_offset;
    bool m_active;

public:
    WatchItem(QObject *parent = 0);
    ~WatchItem();

    inline QString uuid() const { return m_uuid; }
    void setUuid(const QString& uuid);

    inline QString title() const { return m_title; }
    void setTitle(const QString& title);

    inline Country* country() const { return m_country; }
    void setCountry(Country* country);

    inline Station* station() const { return m_station; }
    void setStation(Station* station);

    inline Schedule* schedule() const { return m_schedule; }
    void setSchedule(Schedule* schedule);

    inline QTime pickUpTime() const { return m_pickUpTime; }
    void setPickUpTime(const QTime& pickUpTime);

    inline QStringList weekDays() const { return m_weekDays; }
    void setWeekDays(const QStringList& weekDays);

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

    static bool watchItemLessThan(QObject* v1, QObject* v2);

Q_SIGNALS:
    void uuidChanged();
    void titleChanged();
    void countryChanged();
    void stationChanged();
    void scheduleChanged();
    void pickUpTimeChanged();
    void weekDaysChanged();
    void offsetChanged(int);
    void activeChanged(bool);

public:
    Q_DISABLE_COPY (WatchItem)
};
Q_DECLARE_METATYPE(WatchItem*)
#endif // WATCHITEM_H
