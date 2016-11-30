#ifndef JSONAPI_MANAGER_H
#define JSONAPI_MANAGER_H

#include <QObject>
#include <QHash>

#include "deserializer/deserializer.h"

namespace JSONAPI {

    class Manager : public QObject
    {
        Q_OBJECT

    public:
        static Manager& instance(QObject* parent = 0);
        ~Manager();

    private:
        Manager(QObject* parent);
        static Manager *s_instance;
        QHash<QString, Deserializer*> m_deserializerHash;

    private:
        void registerDeserializer(const QString& type, Deserializer* deserializer);
    };
}


#endif // JSONAPI_MANAGER_H
