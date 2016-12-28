#include "countriesdeserializer.h"
#include "../../../dataClasses/country.h"

using namespace JSONAPI;

CountriesDeserializer::CountriesDeserializer()
{

}

CountriesDeserializer::~CountriesDeserializer()
{

}

QObject* CountriesDeserializer::deserialize(const QJsonValue &json)
{
    QJsonObject attributes = json.toObject().value("attributes").toObject();
    QString uuid = attributes.value("uuid").toString();
    QString name = attributes.value("name").toString();

    return new Country(uuid, name);
}
