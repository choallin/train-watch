#include "schedulesdeserializer.h"
#include "../../../dataClasses/schedule.h"

using namespace JSONAPI;

SchedulesDeserializer::SchedulesDeserializer()
{

}

SchedulesDeserializer::~SchedulesDeserializer()
{

}

QObject* SchedulesDeserializer::deserialize(const QJsonValue &json)
{
    QString id = json.toObject().value("id").toString();
    QJsonObject attributes = json.toObject().value("attributes").toObject();
    QString line = attributes.value("line").toString();
    QTime departure = attributes.value("departure").toVariant().toTime();
    QString direction = attributes.value("direction").toString();

    return new Schedule(id, line, departure, direction);
}
