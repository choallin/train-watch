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
    QJsonObject jsonObject = json.toObject();
    QString uuid = jsonObject.value("uuid").toString();
    QString name = jsonObject.value("name").toString();

    return new Station(uuid, name);
}
