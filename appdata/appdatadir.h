#ifndef APPDATADIR_H
#define APPDATADIR_H

#include <QObject>
#include <QQmlComponent>

#include "appdatadirutility.h"

class AppDataDir : public QObject
{
    Q_OBJECT
public:
    static AppDataDirUtility *qmlAttachedProperties(QObject *object)
    {
        return new AppDataDirUtility(object);
    }
};

QML_DECLARE_TYPEINFO(AppDataDir, QML_HAS_ATTACHED_PROPERTIES)

#endif // APPDATADIR_H
