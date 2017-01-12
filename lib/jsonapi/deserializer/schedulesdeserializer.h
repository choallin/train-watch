#ifndef SCHEDULESDESERIALIZER_H
#define SCHEDULESDESERIALIZER_H

#include "deserializer.h"

namespace JSONAPI {

    class SchedulesDeserializer : public Deserializer
    {
    public:
        SchedulesDeserializer();
        ~SchedulesDeserializer();

        QObject* deserialize(const QJsonValue &json);
    };
}

#endif // SCHEDULESDESERIALIZER_H
