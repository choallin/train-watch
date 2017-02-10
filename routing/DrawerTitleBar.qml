import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import "../guiItems"

ToolBar {
    id: myTitleBar

    RowLayout {
        focus: false
        spacing: 6
        anchors.fill: parent
        Item {
            width: 0
        }

        ToolButton {
            visible: false
            focusPolicy: Qt.NoFocus
            Image {
                anchors.centerIn: parent
                source: "qrc:/images/"+iconOnPrimaryFolder+"/menu.png"
            }
            onClicked: {
            }
        }

        // fake button to avoid flicker and repositioning of titleLabel
        ToolButton {
            visible: !backButton.visible
            enabled: false
            focusPolicy: Qt.NoFocus
        } // fake button
        ToolButton {
            id: backButton
            focusPolicy: Qt.NoFocus
            visible: navigationModel[navigationIndex].canGoBack
            Image {
                anchors.centerIn: parent
                source: "qrc:/images/"+iconOnPrimaryFolder+"/arrow_back.png"
            }
            onClicked: {
                if(destinations.itemAt(navigationIndex).item.goBack()) {
                    rootView.goBack();
                }
            }
        }
        LabelTitle {
            id: titleLabel
            text: currentTitle
            leftPadding: 6
            rightPadding: 6
            elide: Label.ElideRight
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            color: textOnPrimary
        }
        ToolButton {
            id: cancelButton
            visible: navigationModel[navigationIndex].canCancel
            focusPolicy: Qt.NoFocus
            Image {
                anchors.centerIn: parent
                source: "qrc:/images/"+iconOnPrimaryFolder+"/clear.png"
            }
            onClicked: {
                if(destinations.itemAt(navigationIndex).item.cancel()) {
                    rootView.goBack();
                }
            }
        }
        ToolButton {
            id: homeOptionsButton
            visible: navigationIndex == homeNavigationIndex
            focusPolicy: Qt.NoFocus
            Image {
                anchors.centerIn: parent
                source: "qrc:/images/"+iconOnPrimaryFolder+"/more_vert.png"
            }
            onClicked: {
                homeOptionsMenu.open()
            }
            Menu {
                id: homeOptionsMenu
                x: parent.width - width
                transformOrigin: Menu.TopRight
                MenuItem {
                    text: qsTr("Add Watch Item")
                    onTriggered: {
                        rootView.activateDestination(addWatchItemIndex);
                    }
                }
                onAboutToHide: {
                    appWindow.resetFocus()
                }
            }
        }
        // fake button to avoid flicker and repositioning of titleLabel
        ToolButton {
            visible: !homeOptionsButton.visible && !cancelButton.visible
            enabled: false
            focusPolicy: Qt.NoFocus
        }
    }
}


