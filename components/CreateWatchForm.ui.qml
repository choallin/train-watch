import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.0

Item {
    width: 400
    height: 400
    property alias txtTitle: txtTitle
    property alias txtPickupTime: txtPickupTime

    GridLayout {
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        rows: 2
        columns: 1


        TextField {
            id: txtTitle
            placeholderText: qsTr("Title")
            Layout.fillWidth: true
        }

        Switch {
            id: swActive
            text: qsTr("Active")
            Layout.fillWidth: true
            Layout.preferredHeight: 40
            Layout.preferredWidth: 200
        }

        TextField {
            id: txtCountry
            placeholderText: qsTr("Country")
            Layout.fillWidth: true
            Layout.fillHeight: false
        }

        TumblerTimeEdit {
            id: tumblerTimeEdit1
            visible: false
        }

        TextField {
            id: txtStation
            Layout.fillWidth: true
            placeholderText: qsTr("Station")
        }

        TextField {
            id: txtPickupTime
            placeholderText: qsTr("Time")
            Layout.fillWidth: true
        }


    }
    states: [
        State {
            name: "State1"

            PropertyChanges {
                target: txtTitle
                visible: false
            }

            PropertyChanges {
                target: swActive
                visible: false
            }

            PropertyChanges {
                target: txtCountry
                visible: false
            }

            PropertyChanges {
                target: txtStation
                visible: false
            }

            PropertyChanges {
                target: txtPickupTime
                visible: false
            }

            PropertyChanges {
                target: tumblerTimeEdit1
                width: 200
                height: 142
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillWidth: true
                visible: true
            }
        }
    ]
}
