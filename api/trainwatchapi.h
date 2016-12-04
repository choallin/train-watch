#ifndef TRAINWATCHAPI_H
#define TRAINWATCHAPI_H

#include <QObject>
#include <QJsonArray>
#include <QNetworkReply>

#include "../dataClasses/station.h"

class TrainWatchApi: public QObject
{
    Q_OBJECT

public:
    TrainWatchApi(QObject *parent = 0);
    ~TrainWatchApi();

    Q_INVOKABLE
    void getStations(const QString& searchString);

signals:
    void stationsFinished(QVariant stations);

private slots:
    void stationSearchRequestFinished(QNetworkReply* reply);

};

#endif // TRAINWATCHAPI_H
