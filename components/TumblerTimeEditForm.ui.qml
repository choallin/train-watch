import QtQuick 2.4
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

Rectangle {
    id: item1

    property alias hourList: hourList
    property alias minuteList: minuteList
    color: "#00000000"
    border.color: "#00000000"
    border.width: 0

    Row {
        id: row1
        anchors.fill: parent
        Tumbler {
            id: tumblerTime
            anchors.centerIn: parent
            visible: true

            TumblerColumn {
                id: hourColumn
                width: 70
                model: ListModel {
                    id: hourList
                }
            }

            TumblerColumn {
                id: minuteColumn
                width: 70
                model: ListModel {
                    id: minuteList
                }
            }
        }
    }

}

