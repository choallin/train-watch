import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtGraphicalEffects 1.0
import org.trainwatch.data 1.0
import "../guiItems"

Page {
    id: suggestionList
    focus: true
    property string name: "SuggestionList"

    bottomPadding: 6
    topPadding: 6

    signal search(string searchStrng)
    signal itemSelected(var data)

    // list row delegate
    Component {
        id: suggestionRowComponent
        ColumnLayout {
            id: suggenstionRow
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
                        suggestionList.itemSelected(model.modelData);
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

        TextField {
            id: txtSearch
            focus: true
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            Layout.alignment: Qt.AlignCenter
            Layout.fillWidth: true
            placeholderText: qsTr("Station")

            onTextChanged: function() {
                suggestionList.search(this.text);
            }
        }

        ListView {
            id: listView
            clip: true
            focus: true
            anchors.left: txtSearch.left
            anchors.right: txtSearch.right
            anchors.top: txtSearch.bottom
            height: parent.height

            currentIndex: -1

            delegate: suggestionRowComponent

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }

    function addItems(items) {
        listView.model = items;
    }

}
