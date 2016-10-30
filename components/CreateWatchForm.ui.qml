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
    property alias lblTime: lblTime
    property alias lblTimeArea: lblTimeArea

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

        TextField {
            id: txtStation
            Layout.fillWidth: true
            placeholderText: qsTr("Station")
        }

        Label {
            id: lblTime
            x: 111
            y: 378
            text: "Time"
            Layout.fillWidth: true

            MouseArea {
                id: lblTimeArea
                anchors.fill: parent
            }
        }

        TextField {
            id: txtLine
            placeholderText: qsTr("Line")
            Layout.fillWidth: true
        }

        RowLayout {
            id: rowLayout1
            x: 47
            y: 388
            width: 100
            height: 100
            Layout.fillHeight: false
            Layout.fillWidth: true

            Label {
                id: lblOffset
                text: qsTr("Offset(minutes):")
            }

            SpinBox {
                id: spOffset
                value: 20
                editable: false
            }

        }


    }
}
