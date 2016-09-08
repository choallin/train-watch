import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    id: item1
    width: 380
    height: 250
    property alias buttonRow: buttonRow

    property alias infoContainer: infoContainer
    property alias more: more

    property alias wendnesday: wendnesday
    property alias thursday: thursday
    property alias friday: friday
    property alias saturday: saturday
    property alias sunday: sunday
    property alias tuesday: tuesday
    property alias monday: monday

    property alias trainLine: trainLine
    property alias direction: direction
    property alias station: station
    property alias offset: offset
    property alias alarm: alarm

    Text {
        id: alarmText
        x: 21
        y: 19
        width: 80
        height: 39
        text: qsTr("Alarm:")
        font.bold: true
        font.pixelSize: 20
    }

    Text {
        id: alarm
        x: 122
        y: 19
        width: 71
        height: 28
        text: qsTr("06:00")
        font.bold: true
        font.pixelSize: 20
    }

    Text {
        id: departureText
        x: 21
        y: 54
        text: qsTr("Abfahrt:")
        font.pixelSize: 16
    }

    Text {
        id: depature
        x: 122
        y: 54
        text: qsTr("06:45")
        font.pixelSize: 16
    }

    Text {
        id: offsetText
        x: 21
        y: 79
        text: qsTr("Offset")
        font.pixelSize: 16
    }

    Text {
        id: offset
        x: 122
        y: 79
        text: "00:30"
        font.pixelSize: 16
    }

    Rectangle {
        id: infoContainer
        anchors.top: offset.bottom
//        anchors.topMargin: -98
        visible: false
        Text {
            id: stationText
            x: 21
            y: 104
            text: qsTr("Bahnhof")
            font.pixelSize: 16
        }

        Text {
            id: station
            x: 122
            y: 104
            text: qsTr("Gratwein")
            font.pixelSize: 16
        }

        Text {
            id: trainLinieText
            x: 21
            y: 129
            text: qsTr("Linie")
            font.pixelSize: 16
        }

        Text {
            id: trainLine
            x: 122
            y: 129
            text: qsTr("S1")
            font.pixelSize: 16

        }
        Text {
            id: directionText
            x: 21
            y: 154
            text: qsTr("Richtung")
            font.pixelSize: 16
        }

        Text {
            id: direction
            x: 122
            y: 154
            text: qsTr("Graz")
            font.pixelSize: 16
        }
    }

    RowLayout {
        id: buttonRow
        x: 21
        anchors.top: offset.bottom
        anchors.topMargin: 10
        spacing: 20

        Button {
            id: monday
            text: qsTr("Mo")
            checked: false
            highlighted: true
            autoRepeat: true
            checkable: true
            flat: true
            background: Rectangle {
                radius: 100
                antialiasing: true
            }
        }

        Button {
            id: tuesday
            text: qsTr("Tu")
            checked: false
            highlighted: true
            autoRepeat: true
            checkable: true
            flat: true
            background: Rectangle {
                radius: 100
                antialiasing: true
            }
        }

        Button {
            id: wendnesday
            text: qsTr("We")
            highlighted: true
            autoRepeat: true
            checkable: true
            flat: true
            background: Rectangle {
                radius: 100
                antialiasing: true
            }
        }

        Button {
            id: thursday
            text: qsTr("Th")
            highlighted: true
            autoRepeat: true
            checkable: true
            flat: true
            background: Rectangle {
                radius: 100
                antialiasing: true
            }
        }

        Button {
            id: friday
            text: qsTr("Fr")
            highlighted: true
            autoRepeat: true
            checkable: true
            flat: true
            background: Rectangle {
                radius: 100
                antialiasing: true
            }
        }

        Button {
            id: saturday
            text: qsTr("Sa")
            highlighted: true
            autoRepeat: true
            checkable: true
            flat: true
            background: Rectangle {
                radius: 100
                antialiasing: true
            }
        }

        Button {
            id: sunday
            text: qsTr("Su")
            highlighted: true
            autoRepeat: true
            checkable: true
            flat: true
            background: Rectangle {
                radius: 100
                antialiasing: true
            }

        }
    }

    ToolButton {
        id: more
        x: 283
        y: 13
        highlighted: true
        contentItem: Image {
            fillMode: Image.Pad
            horizontalAlignment: Image.AlignHCenter
            verticalAlignment: Image.AlignVCenter
            source: "qrc:/images/menu.png"
        }
    }
}
