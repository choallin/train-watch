#ifndef TRAINWATCHAPI_H
#define TRAINWATCHAPI_H

#include <QObject>
#include <QJsonArray>
#include <QNetworkReply>

#include "dataClasses/watchitem.h"

class TrainWatchApi: public QObject
{
    Q_OBJECT

private:
    QString m_endPoint;
    QString m_version;

public:
    TrainWatchApi(QObject *parent = 0);
    ~TrainWatchApi();

    Q_INVOKABLE
    void getCountries();
    Q_INVOKABLE
    void getStations(const QString& searchString);
    Q_INVOKABLE
    void getSchedules(WatchItem* watchItem);

private:
    QString api();
    QNetworkAccessManager* getNetworkAccessManager();
    bool isSuccessFull(QNetworkReply* reply);

signals:
    void stationsFinished(QVariant stations);
    void countriesFinished(QVariant countries);
    void schedulesFinished(QVariant schedules);

private slots:
    void stationSearchRequestFinished(QNetworkReply* reply);
    void countriesSearchRequestFinished(QNetworkReply* reply);
    void schedulesSearchRequestFinished(QNetworkReply* reply);
};

#endif // TRAINWATCHAPI_H
