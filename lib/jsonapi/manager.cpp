#include <QDebug>

#include "manager.h"

//deserializers
#include "deserializer/stationsdeserializer.h"

using namespace JSONAPI;

Manager* Manager::s_instance = 0;

Manager::Manager(QObject *parent) :
    QObject(parent)
{
    registerDeserializer("stations", new StationsDeserializer());
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
