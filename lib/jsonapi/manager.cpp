#include <QDebug>
#include <QJsonArray>

#include "manager.h"

//deserializers
#include "deserializer/stationsdeserializer.h"
#include "deserializer/countriesdeserializer.h"
#include "deserializer/schedulesdeserializer.h"

using namespace JSONAPI;

Manager* Manager::s_instance = 0;

Manager::Manager(QObject *parent) :
    QObject(parent)
{
    registerDeserializer("station", new StationsDeserializer());
    registerDeserializer("countries", new CountriesDeserializer());
    registerDeserializer("schedules", new SchedulesDeserializer());
}

Manager::~Manager()
{
    QHashIterator<QString, Deserializer*> hit(m_deserializerHash);
    while(hit.hasNext()){
        hit.next();
        delete hit.value();
    }
}

Manager& Manager::instance(QObject* parent)
{
    if(!s_instance){
        if(!parent) {
            qFatal("fatal error at initial JSONAPIDeserializer::instance call. parent is NULL");
        }
        s_instance = new Manager(parent);
    }
    return *s_instance;
}

void Manager::registerDeserializer(const QString& type, Deserializer* deserializer)
{
    if(m_deserializerHash.contains(type)){
        qWarning("multiple registrations for same type '%s' at JSONAPI::Manager::registerDeserializer", qPrintable(type));
        return;
    }
    m_deserializerHash.insert(type, deserializer);
}

QList<QObject*> Manager::deserialize(const QJsonObject& jsonApiObject)
{
    QList<QObject*> objectList;
    QJsonArray dataObjects = jsonApiObject.value("data").toArray();
    if(dataObjects.isEmpty()){
        return objectList;
    }

    QString type = dataObjects.first().toObject().value("type").toString();
    Deserializer* deserializer = m_deserializerHash.value(dataObjects.first().toObject().value("type").toString(), 0);
    if(!deserializer){
        qWarning("no deserializer found for type '%s' at JSONAPI::Manager::deserialize", qPrintable(type));
        return objectList;
    }

    foreach(const QJsonValue& value, dataObjects){
        objectList.append(deserializer->deserialize(value));
    }
    return objectList;
}
