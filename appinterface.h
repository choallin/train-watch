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
    static const QStringList materialDeepPurple;
    static const QStringList materialGreen;
    static const QStringList lightPalette;

public:
     AppInterface(QObject *parent = 0);

     void addContextProperty(QQmlContext* context);

     Q_INVOKABLE
     QStringList defaultPrimaryPalette() const;

     Q_INVOKABLE
     QStringList defaultAccentPalette() const;

     Q_INVOKABLE
     QStringList defaultThemePalette() const;

private:
     DataManager* mDataManager;
     TrainWatchApi* mTrainWatchApi;
};

#endif // APPINTERFACE_H
