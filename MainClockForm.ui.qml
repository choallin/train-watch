import QtQuick 2.4
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.0

Item {
    id: root
    anchors.fill: parent

    property alias time: clock.text
    property alias trains: nextTrain.model

    width: 400
    height: 400

    TextArea {
        id: clock
        x: 199
        y: 78
        width: 159
        height: 40
        font.pointSize: 20
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        textFormat: Text.PlainText
    }

    Repeater {
        id: nextTrain

        delegate: TextArea {
            console.log(model)
            id: linie
            x: 199
            y: 119
            width: 159
            height: 40
            text: qsTr(model.trainData)
            font.pointSize: 12
        }
    }

}
