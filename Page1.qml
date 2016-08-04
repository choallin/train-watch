import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.3

Page {
    id: overview

    Label {
        text: qsTr("Overview")
    }
    GridLayout {
        id: grid
        columns: 3
        anchors.fill: parent
        MainClock {
            Layout.column: 3
        }
        Repeater {
            model: 2

            AlarmClock {
                Layout.column: 1
            }
        }

        AddAlarm {
            Layout.column: 1
        }
    }


    Page1Form {
        button1.onClicked: {
            console.log("Button 1 clicked.");
        }
        button2.onClicked: {
            console.log("Button 2 clicked.");
        }
    }
}
