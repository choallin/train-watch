#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "appdata/appdatadir.h"
#include "fileio.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qmlRegisterUncreatableType<AppDataDir>("AppDataDir", 1, 0, "AppDataDir", "Static");
    qmlRegisterType<FileIO>("FileIO", 1, 0, "FileIO");
    qputenv("QT_QUICK_CONTROLS_STYLE", "material");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
