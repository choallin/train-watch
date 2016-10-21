#ifndef JSONDATA_H
#define JSONDATA_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonValue>

class JsonData : public QObject
{
    Q_OBJECT

private:
    QJsonDocument doc;

public:
    JsonData(QObject* parent, const QString& filePath);
    ~JsonData();

    QJsonValue modelItems();
};

#endif // JSONDATA_H
