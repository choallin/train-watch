#ifndef APPINTERFACE_H
#define APPINTERFACE_H

#include <QObject>
#include <QtQml>

#include "data/datamanager.h"
#include "api/trainwatchapi.h"

class AppInterface : public QObject
{
    Q_OBJECT

public:
     AppInterface(QObject *parent = 0);

     void addContextProperty(QQmlContext* context);

private:
     DataManager* mDataManager;
     TrainWatchApi* mTrainWatchApi;
};

#endif // APPINTERFACE_H
