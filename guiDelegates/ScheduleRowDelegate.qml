import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import "../guiItems"

ColumnLayout {
    id: itemRow

    signal itemClicked(var data)

    implicitWidth: appWindow.width
    RowLayout {
        spacing: 20
        Layout.leftMargin: 10
        Layout.rightMargin: 6
        Layout.topMargin: 6
        IconInactive {
            imageName: "subway.png"
            fillMode: Image.Pad
        }
        ColumnLayout {
            Layout.fillWidth: true
            spacing: 0
            LabelSubheading {
                rightPadding: 12
                text: model.modelData.line
                font.bold: true
                wrapMode: Label.WordWrap
            }

            Label {
                rightPadding: 12
                text: Qt.formatDateTime(model.modelData.departure, "hh:mm") + " " + model.modelData.direction
                Layout.fillWidth: true
                opacity: opacityBodyAndButton
            }
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                itemClicked(model.modelData);
            }
        }
    }
    HorizontalListDivider{}
}
