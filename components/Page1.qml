import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Pane {
    id: overview
    property int myIndex: 0

    ColumnLayout {
        id: column

        spacing: 3
        anchors.fill: parent

        MainClock {
            id: mainclock
            Layout.fillWidth: true
            Layout.fillHeight: true
            anchors.fill: parent
        }

        ListView {
            id: alarmView
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            model: ListModel {
                ListElement { type: "AlarmClock"; text: "AlarmClock" }
                ListElement { type: "AlarmClock"; text: "AlarmClock" }
            }

            delegate: AlarmClock {
                id: delegateAlarmClock
                width: alarmView.width

            }
        }
    }

    function init() {

    }
}
