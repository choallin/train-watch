#ifndef JSONAPI_DESERIALIZER_H
#define JSONAPI_DESERIALIZER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonValue>

namespace JSONAPI {

    class Deserializer
    {
    public:
        Deserializer();
        virtual ~Deserializer();

        virtual QObject* deserialize(const QJsonValue& json) = 0;
    };

}

#endif // JSONAPI_DESERIALIZER_H
