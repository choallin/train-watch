import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.3
import "./components"

ApplicationWindow {
    visible: true
    title: qsTr("Train Watch")

    Material.theme: Material.Light
    Material.primary: Material.LightBlue
    Material.accent: Material.Purple

    id: root

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    header: TabBar {
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
