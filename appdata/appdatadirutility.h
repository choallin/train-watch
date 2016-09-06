#ifndef APPDATADIRUTILITY_H
#define APPDATADIRUTILITY_H

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStandardPaths>
#include <QQmlComponent>

class AppDataDirUtility : public QObject
{
    Q_OBJECT
public:
    enum StandardLocation
    {
        AppDataLocation = QStandardPaths::AppDataLocation
    };
    Q_ENUMS(StandardLocation)

public:
    AppDataDirUtility(QObject *parent) :
        QObject(parent)
    {
    }

    Q_INVOKABLE QString getPath(StandardLocation location)
    {
        QStandardPaths::StandardLocation loc = static_cast<QStandardPaths::StandardLocation>(location);
        return QStandardPaths::writableLocation(loc) + "/";
    }
};

#endif // APPDATADIRUTILITY_H
