TEMPLATE = app
# TARGET = train_watch
QT += qml quick quickcontrols2

CONFIG += c++11

SOURCES += main.cpp \
    fileio.cpp \
    dataModels/jsondatamodel.cpp \
    data/jsondata.cpp \
    dataClasses/watchitem.cpp \
    appinterface.cpp \
    data/datamanager.cpp \
    dataClasses/station.cpp \
    api/trainwatchapi.cpp \
    lib/jsonapi/manager.cpp \
    lib/jsonapi/deserializer/deserializer.cpp \
    lib/jsonapi/deserializer/stationsdeserializer.cpp \
    dataClasses/country.cpp \
    lib/jsonapi/deserializer/countriesdeserializer.cpp \
    dataClasses/schedule.cpp

OTHER_FILES += \
    main.qml \
    components/*.qml

RESOURCES += qml.qrc \
    ressources.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    components/AlarmClock.qml \
    components/AlarmClockForm.ui.qml \
    components/Clock.qml

HEADERS += \
    fileio.h \
    appdata/appdatadirutility.h \
    appdata/appdatadir.h \
    dataModels/jsondatamodel.h \
    data/jsondata.h \
    dataClasses/watchitem.h \
    appinterface.h \
    data/datamanager.h \
    dataClasses/station.h \
    api/trainwatchapi.h \
    lib/jsonapi/manager.h \
    lib/jsonapi/deserializer/deserializer.h \
    lib/jsonapi/deserializer/stationsdeserializer.h \
    dataClasses/country.h \
    lib/jsonapi/deserializer/countriesdeserializer.h \
    dataClasses/schedule.h
