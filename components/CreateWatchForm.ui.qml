import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.0
import org.trainwatch.data 1.0
import "../guiItems"

Item {
    width: 400
    height: 400
    property alias txtTitle: txtTitle
    property alias swActive: swActive
    property alias txtCountry: txtCountry
    property alias txtStation: txtStation
    property alias lblTime: lblTime
    property alias txtLine: txtLine
    property alias spOffset: spOffset
    property alias btnPickUpTime: btnPickUpTime
    property WatchItem watchItem

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
            text: watchItem.title
        }

        Switch {
            id: swActive
            text: qsTr("Active")
            Layout.fillWidth: true
            Layout.preferredHeight: 40
            Layout.preferredWidth: 200
            checked: watchItem.active
        }

        TextField {
            id: txtCountry
            placeholderText: qsTr("Country")
            Layout.fillWidth: true
            Layout.fillHeight: false
            text: watchItem.country
        }

        TextField {
            id: txtStation
            Layout.fillWidth: true
            placeholderText: qsTr("Station")
            text: watchItem.station.name
        }

        RowLayout {
            id: rowLayout2
            width: 100
            height: 100
            Layout.fillWidth: true

            Label {
                id: lblTime
                text: watchItem.pickUpTime
            }

            ButtonIconActive {
                id: btnPickUpTime
                visible: true
                imageName: "time.png"
            }
        }

        TextField {
            id: txtLine
            placeholderText: qsTr("Line")
            Layout.fillWidth: true
            text: watchItem.line
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
                value: watchItem.offset
                editable: false
            }

        }
    }
}
