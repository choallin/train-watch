#ifndef WATCHITEM_H
#define WATCHITEM_H

#include <QObject>
#include <QTime>

class WatchItem: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QString country READ country WRITE setCountry)
    Q_PROPERTY(QString station READ station WRITE setStation)
    Q_PROPERTY(QString line READ line WRITE setLine)
    Q_PROPERTY(QTime pickUpTime READ pickUpTime WRITE setPickUpTime)
    Q_PROPERTY(int offset READ offset WRITE setOffset)

private:
    QString m_title;
    QString m_country;
    QString m_station;
    QString m_line;
    QTime m_pickUpTime;
    int m_offset;

public:
    WatchItem(QObject *parent = 0);
    ~WatchItem();

    inline QString title() const { return m_title; }
    inline void setTitle(const QString& title) { m_title = title; }

    inline QString country() const { return m_country; }
    inline void setCountry(const QString& country) { m_country = country; }

    inline QString station() const { return m_station; }
    inline void setStation(const QString& station) { m_station = station; }

    inline QString line() const { return m_line; }
    inline void setLine(const QString& line) { m_line = line; }

    inline QTime pickUpTime() const { return m_pickUpTime; }
    inline void setPickUpTime(const QTime& pickUpTime) { m_pickUpTime = pickUpTime; }

    inline int offset() const { return m_offset; }
    inline void setOffset(const int offset) { m_offset = offset; }

    Q_DISABLE_COPY (WatchItem)
};
Q_DECLARE_METATYPE(WatchItem*)
#endif // WATCHITEM_H
