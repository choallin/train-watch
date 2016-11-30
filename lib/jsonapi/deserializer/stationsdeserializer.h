#ifndef JSONAPI_STATIONSDESERIALIZER_H
#define JSONAPI_STATIONSDESERIALIZER_H

#include "deserializer.h"

namespace JSONAPI {

    class StationsDeserializer : public Deserializer
    {
    public:
        StationsDeserializer();
        ~StationsDeserializer();

        QObject* deserialize(const QJsonValue &json);
    };
}

#endif // JSONAPI_STATIONSDESERIALIZER_H
