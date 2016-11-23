#include "appinterface.h"

AppInterface::AppInterface(QObject *parent):
    QObject(parent),
    mDataManager(new DataManager(this))
{
}

void AppInterface::addContextProperty(QQmlContext *context)
{
    context->setContextProperty("dataManager", mDataManager);
}
