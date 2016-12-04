#include "appinterface.h"

AppInterface::AppInterface(QObject *parent):
    QObject(parent),
    mDataManager(new DataManager(this)),
    mTrainWatchApi(new TrainWatchApi(this))
{
}

void AppInterface::addContextProperty(QQmlContext *context)
{
    context->setContextProperty("dataManager", mDataManager);
    context->setContextProperty("trainWatchApi", mTrainWatchApi);
}
