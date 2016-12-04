#include "stationsdeserializer.h"
#include "../../../dataClasses/station.h"

using namespace JSONAPI;

StationsDeserializer::StationsDeserializer()
{

}

StationsDeserializer::~StationsDeserializer()
{

}

QObject* StationsDeserializer::deserialize(const QJsonValue &json)
{
    QJsonObject attributes = json.toObject().value("attributes").toObject();
    QString uuid = attributes.value("uuid").toString();
    QString name = attributes.value("name").toString();

    return new Station(uuid, name);
}
