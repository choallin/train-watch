import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    width: 400
    height: 200
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
        id: text1
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
        id: text2
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
        id: text3
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

    Text {
        id: text4
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
        id: line
        x: 223
        y: 79
        text: qsTr("Linie")
        font.pixelSize: 16
    }

    Text {
        id: trainLine
        x: 324
        y: 79
        text: qsTr("S1")
        font.pixelSize: 16

    }
    Text {
        id: text5
        x: 223
        y: 104
        text: qsTr("Richtung")
        font.pixelSize: 16
    }

    Text {
        id: direction
        x: 324
        y: 104
        text: qsTr("Graz")
        font.pixelSize: 16
    }

    RowLayout {
        x: 21
        y: 152
        spacing: 25

        Button {
            id: monday
            text: qsTr("Mo")
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
            autoRepeat: true
            checkable: true
            flat: true
            background: Rectangle {
                radius: 100
                antialiasing: true
            }
        }
    }
}
