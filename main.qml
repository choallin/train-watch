import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.3
import "components" as TwComponents

ApplicationWindow {
    visible: true
    title: qsTr("Train Watch")

    id: root

    Material.theme: Material.Light
    Material.primary: Material.LightBlue
    Material.accent: Material.Purple
    Material.primary: Material.Purple

    header: ToolBar {
        RowLayout {
            spacing: 20
            anchors.fill: parent

            ToolButton {
                id: contextButton
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "qrc:/images/drawer.png"
                }
                //onClicked:
            }

            Label {
                id: titleLabel
                text: "Train Watch"
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            ToolButton {
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "qrc:/images/menu.png"
                }
                onClicked: optionsMenu.open()

                Menu {
                    id: optionsMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight

                    MenuItem {
                        text: "Settings"
                        onTriggered: settingsPopup.open()
                    }
                    MenuItem {
                        text: "About"
                        onTriggered: aboutDialog.open()
                    }
                }
            }
        }
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        onCurrentIndexChanged: function() {
            if(currentIndex === 0) {
                contextButton.contentItem.source = "qrc:/images/drawer.png"
            }
            else {
                contextButton.contentItem.source = "qrc:/images/arrow_back.png"
            }

        }

        TwComponents.Page1 {
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        Material.foreground: white
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Overview")
        }
        TabButton {
            text: qsTr("Add")
        }
    }
}
