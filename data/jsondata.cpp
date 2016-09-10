#include <QDebug>
#include <QFile>
#include <QJsonObject>

#include "jsondata.h"

JsonData::JsonData(QObject *parent, const QString &filePath) :
    QObject(parent)
{
    QFile jsonFile(filePath);
    if(!jsonFile.open(QFile::ReadOnly)) {
        qFatal("File Error(%s)", qPrintable(jsonFile.errorString()));
    }
    QJsonParseError jsonError;
    doc = QJsonDocument().fromJson(jsonFile.readAll(), &jsonError);
    if(jsonError.error != QJsonParseError::NoError) {
        qFatal("Json Parse Error(%s)", qPrintable(jsonError.errorString()));
    }
}

JsonData::~JsonData()
{
}

QJsonValue JsonData::modelItems()
{
    return doc.object().value("watches");
}
