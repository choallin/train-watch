import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.3
import FileIO 1.0
import AppDataDir 1.0
import "components" as TwComponents

ApplicationWindow {
    visible: true
    //title: qsTr("Train Watch")

    id: root
    //static const QStringList materialPurple{"#E1BEE7", "#9C27B0", "#7B1FA2", "#000000", "#FFFFFF", "#FFFFFF", "black", "white", "white"};
    //return QStringList{thePalette.at(1), thePalette.at(4), thePalette.at(7)};

    property bool isLandscape: width > height

    property color primaryColor: "#E1BEE7"
    property color primaryDarkColor: "#9C27B0"
    property color accentColor: "#9C27B0"

    Material.theme: Material.Light
    Material.accent: accentColor
    Material.primary: primaryColor

    FileIO {
        id: settings
        source: AppDataDir.getPath(AppDataDir.AppDataLocation) + "test.json"
    }

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
            ListView {
                width: 200; height: 250

                model: jsonDataModel
                delegate: Text { text: model.display.title + " " + model.display.offset }
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
