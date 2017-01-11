#ifndef SCHEDULE_H
#define SCHEDULE_H


#include <QObject>
#include <QVariantMap>
#include <QTime>

class Schedule: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString line READ line WRITE setLine NOTIFY lineChanged FINAL)
    Q_PROPERTY(QTime departure READ departure WRITE setDeparture NOTIFY departureChanged FINAL)
    Q_PROPERTY(QString direction READ direction WRITE setDirection NOTIFY directionChanged FINAL)

private:
    QString m_line;
    QTime m_departure;
    QString m_direction;

public:
    Schedule(QObject *parent = 0);
    Schedule(const QString& line, const QTime& departure, const QString& direction, QObject *parent = 0);
    ~Schedule();

    inline QString line() const { return m_line; }
    void setLine(const QString& line);

    inline QTime departure() const { return m_departure; }
    void setDeparture(const QTime& departure);

    inline QString direction() const { return m_direction; }
    void setDirection(const QString& direction);

    Q_INVOKABLE
    QString toS() const;

    void fillFromCacheMap(const QVariantMap& map);
    QVariantMap toCacheMap() const;

Q_SIGNALS:
    void lineChanged(QString);
    void departureChanged(QTime);
    void directionChanged(QString);

public:
    Q_DISABLE_COPY (Schedule)
};
Q_DECLARE_METATYPE(Schedule*)

#endif // SCHEDULE_H
