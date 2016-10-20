import QtQuick 2.7
// import "MainClockForm"

Item {
    width: parent.width
    MainClockForm {
        id: mainClock
        width: parent.width

        trains: ListModel{
            id: model
            ListElement {
                trainData: qsTr("Test")
            }
            ListElement {
                trainData: qsTr("multiple trains")
            }
            ListElement {
                trainData: qsTr("multiple trains more")
            }
            ListElement {
                trainData: qsTr("multiple trains still more")
            }
        }
    }
}

