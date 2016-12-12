#include "appinterface.h"

// material constants
const QStringList AppInterface::materialDeepPurple{"#D1C4E9", "#673AB7", "#512DA8", "#000000", "#FFFFFF", "#FFFFFF", "black", "white", "white"};
const QStringList AppInterface::materialGreen{"#C8E6C9", "#4CAF50", "#388E3C", "#000000", "#FFFFFF", "#FFFFFF", "black", "white", "white"};
const QStringList AppInterface::lightPalette{"#000000", "#FFFFFF", "0.87", "0.54", "0.12", "0.54", "0.26", "black", "0", "#424242", "#424242", "1.0", "0.7", "#323232", "0.75"};

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

QStringList AppInterface::defaultPrimaryPalette() const
{
    return AppInterface::materialDeepPurple;
}

QStringList AppInterface::defaultAccentPalette() const
{
    return AppInterface::materialGreen;
}

QStringList AppInterface::defaultThemePalette() const
{
    return AppInterface::lightPalette;
}
