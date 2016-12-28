#ifndef COUNTRIESDESERIALIZER_H
#define COUNTRIESDESERIALIZER_H

#include "deserializer.h"

namespace JSONAPI {

    class CountriesDeserializer : public Deserializer
    {
    public:
        CountriesDeserializer();
        ~CountriesDeserializer();

        QObject* deserialize(const QJsonValue &json);
    };
}

#endif // COUNTRIESDESERIALIZER_H
