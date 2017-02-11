import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import "../guiItems"

Page {
    id: itemList
    focus: true
    property string name: "ItemList"
    property alias listItemDelegate : listView.delegate

    bottomPadding: 6
    topPadding: 6

    signal itemSelected(var data)

    // list row delegate
    Component {
        id: itemListRowComponent
        ColumnLayout {
            id: itemRow
            implicitWidth: appWindow.width
            RowLayout {
                spacing: 20
                Layout.leftMargin: 10
                Layout.rightMargin: 6
                Layout.topMargin: 6
                IconInactive {
                    imageName: "flag.png"
                    fillMode: Image.Pad
                }
                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 0
                    LabelSubheading {
                        rightPadding: 12
                        text: model.modelData.uuid
                        font.bold: true
                        wrapMode: Label.WordWrap
                    }

                    Label {
                        rightPadding: 12
                        text: model.modelData.name
                        Layout.fillWidth: true
                        opacity: opacityBodyAndButton
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        itemList.itemSelected(model.modelData);
                    }
                }
            }
            HorizontalListDivider{}
        }
    }

    ColumnLayout {
        spacing: 2
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height
        focus: true

        ListView {
            id: listView
            clip: true
            focus: true
            anchors.fill: parent
            height: parent.height

            currentIndex: -1

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }

    function setModel(model) {
        listView.model = model;
    }
}
