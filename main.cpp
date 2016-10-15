#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQuickView>
#include <QStandardPaths>

#include "appdata/appdatadir.h"
#include "fileio.h"
#include "data/jsondata.h"
#include "dataModels/jsondatamodel.h"

void createExampleJsonFile(const QString& filePath)
{
    //open and read example file
    QFile exampleFile(":/misc/exampleJsonData.json");
    exampleFile.open(QIODevice::ReadOnly);
    QJsonDocument exampleDoc = QJsonDocument::fromJson(exampleFile.readAll());
    exampleFile.close();

    //open and write to train watch json file
    QFile jsonFile(filePath);
    jsonFile.open(QFile::WriteOnly);
    QTextStream out(&jsonFile);
    out << exampleDoc.toJson();

    jsonFile.close();
}

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterUncreatableType<AppDataDir>("AppDataDir", 1, 0, "AppDataDir", "Static");
    qmlRegisterType<FileIO>("FileIO", 1, 0, "FileIO");
    qputenv("QT_QUICK_CONTROLS_STYLE", "material");
    QGuiApplication app(argc, argv);

    QString trainWatchJsonPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/trainWatch.json";

    //remove this in production
    if(!QFile::exists(trainWatchJsonPath)) {
        createExampleJsonFile(trainWatchJsonPath);
    }

    JsonData* jsonData = new JsonData(&app,trainWatchJsonPath);
    JsonDataModel* jsonDataModel = new JsonDataModel(&app, jsonData);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("jsonDataModel", jsonDataModel);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}

