TEMPLATE = app
# TARGET = train_watch
QT += qml quick quickcontrols2

CONFIG += c++11

SOURCES += main.cpp \
    fileio.cpp \
    dataModels/jsondatamodel.cpp \
    data/jsondata.cpp

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
    data/jsondata.h
