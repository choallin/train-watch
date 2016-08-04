import QtQuick 2.4

Item {
    anchors.fill: parent
    Timer {
        interval: 500
        running: true
        repeat: true
        onTriggered: mainClock.time = Date().toString()
    }

    MainClockForm {
        id: mainClock

        trains: ListModel{
            id: model
            ListElement {
                trainData: qsTr("Test")
            }
        }
    }
}

