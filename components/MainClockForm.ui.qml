import QtQuick 2.7
import QtQuick.Controls 2.0

Item {
    id: root
    anchors.fill: parent


    width: 400
    height: 400
    rotation: 0

    property alias trains: nextTrain.model
    property alias date: date.text
    property alias minuteRotation: clockArrowMinute.rotation
    property alias hourRotation: clockImageHour.rotation

    TextArea {
        id: date
        x: 199
        y: 60
        width: 160
        height: 40
        font.pointSize: 15
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        textFormat: Text.PlainText
        readOnly: true
    }

    Column {
        id: trainList
        anchors.top: date.bottom
        Repeater {
            id: nextTrain

            delegate: TextArea {
                id: linie
                x: 199
                y: 119
                width: 159
                height: 40
                text: qsTr(model.trainData)
                font.pointSize: 12
                readOnly: true
            }
        }
    }

    Image {
        id: clockImg
        x: 20
        y: 40
        width: 150
        height: 150
        source: "../images/clock.gif"

        Image {
            id: clockArrowMinute
            // x: 0
            // y: 8
            anchors.horizontalCenter: parent.horizontalCenter
            // anchors.baseline: parent
            width: 150
            height: 70
            anchors.bottom: parent.Center
            rotation: 0
            transformOrigin: Item.Bottom
            fillMode: Image.TileVertically
            source: "../images/line2.png"

        }
        Image {
            id: clockImageHour
            x: 37
            y: 33
            width: 75
            height: 45
            rotation: 0
            fillMode: Image.TileVertically
            transformOrigin: Item.Bottom
            source: "../images/line2.png"
        }

        Image {
            id: image1
            anchors.centerIn: parent
            width: 15
            height: 15
            fillMode: Image.Stretch
            source: "../images/point.png"
        }
    }


}
