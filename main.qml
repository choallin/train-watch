import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.3
import FileIO 1.0
import AppDataDir 1.0
import "components" as TwComponents
import "guiItems"
import "popups"

ApplicationWindow {
    id: appWindow
    visible: true
    title: qsTr("Train Watch")

    //materialPurple{"#E1BEE7", "#9C27B0", "#7B1FA2", "#000000", "#FFFFFF", "#FFFFFF", "black", "white", "white"};
    //lightPalette{"#000000", "#FFFFFF", "0.87", "0.54", "0.12", "0.54", "0.26", "black", "0", "#424242", "#424242", "1.0", "0.7", "#323232", "0.75"};

    property bool isLandscape: width > height

    //set some constants
    property color primaryColor: "#E1BEE7"
    property color primaryDarkColor: "#9C27B0"
    property color accentColor: "#9C27B0"
    property color textOnPrimaryDark: "#FFFFFF"
    property color textOnPrimaryLight: "#000000"
    property color textOnPrimary: "#FFFFFF"
    property color cardAndDialogBackground: "#FFFFFF"
    property real iconActiveOpacity: 0.54
    property string iconFolder: "black"
    property alias contextButton: contextButton

    Material.theme: Material.Light
    Material.accent: Material.Purple
    Material.primary: Material.Purple

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
                onClicked: {
                    createWatchFormLoader.item.saveWatchItem();
                }
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
        id: rootView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        onCurrentIndexChanged: function() {
            if(currentIndex === 0) {
                contextButton.contentItem.source = "qrc:/images/drawer.png"
            }
            else {
                contextButton.contentItem.source = "qrc:/images/arrow_back.png"
                createWatchFormLoader.setSource("../components/CreateWatch.qml", { watchItem: dataManager.createWatchItem() })
            }

        }

        TwComponents.Page1 {
        }

        Page {
            Loader {
                id: createWatchFormLoader
            }
        }
    }

    footer: TabBar {
        Material.foreground: white
        id: tabBar
        currentIndex: rootView.currentIndex
        TabButton {
            text: qsTr("Overview")
        }
        TabButton {
            text: qsTr("Add")
        }
    }

    Component.onCompleted: {
        dataManager.initialize();
    }

    //ApplicationWindow functions
    function resetFocus() {
        rootView.focus = true;
    }

    function showInfo(info) {
        popupInfo.text = info;
        popupInfo.buttonText = qsTr("OK");
        popupInfo.open();
    }

    //ApplicationWindow popups
    PopupInfo {
        id: popupInfo
        onAboutToHide: {
            popupInfo.stopTimer();
            resetFocus();
        }
    } // popupInfo
}
