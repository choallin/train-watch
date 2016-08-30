import QtQuick 2.4

Item {
    anchors.fill: parent
    Timer {
        interval: 500
        running: true
        repeat: true
        onTriggered: clockTrigger()
    }

    MainClockForm {
        id: mainClock

        trains: ListModel{
            id: model
            ListElement {
                trainData: qsTr("Test")
            }
            ListElement {
                trainData: qsTr("multiple trains")
            }
        }
    }
    function clockTrigger() {
        var date = new Date();
        // date representation has to be localized
        mainClock.date = date.getDate().toString() + "." + date.getMonth().toString() + "." + date.getFullYear().toString()
        mainClock.minuteRotation = 6 * date.getMinutes()
        mainClock.hourRotation = 30 * date.getHours()
    }
}

