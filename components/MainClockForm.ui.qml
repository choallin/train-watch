import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    id: root

    property alias trains: nextTrain.model

    RowLayout {
        anchors.fill: parent
        spacing: 6

        Clock {
        }

        Column {
            spacing: 6
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

    }

}
