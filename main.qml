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
import "routing"

ApplicationWindow {
    id: appWindow
    visible: true
    title: qsTr("Train Watch")

    property bool isLandscape: width > height

    property variant primaryPalette: myApp.defaultPrimaryPalette()
    property variant accentPalette: myApp.defaultAccentPalette()
    property variant themePalette: myApp.defaultThemePalette()

    // set some constants(Material Design)
    property color primaryColor: primaryPalette[1]
    property color primaryDarkColor: primaryPalette[2]
    property string iconOnPrimaryFolder: primaryPalette[7]

    property color accentColor: accentPalette[0]
    property color textOnPrimaryDark: primaryPalette[5]
    property color textOnPrimaryLight: primaryPalette[3]
    property color textOnPrimary: primaryPalette[4]
    property color cardAndDialogBackground: themePalette[1]
    property color dividerColor: themePalette[0]
    property color popupTextColor: themePalette[10]
    property string iconFolder: themePalette[7]
    Material.primary: primaryColor
    Material.accent: accentColor
    property real primaryTextOpacity: themePalette[2]
    property real dividerOpacity: themePalette[4]
    property real iconActiveOpacity: themePalette[5]
    property real iconInactiveOpacity: themePalette[6]

    // font sizes - defaults from Google Material Design Guide
    property int fontSizeSubheading: 16
    property int fontSizeTitle: 20
    property int fontSizeSuperTitle: 30

    property real opacitySubheading: primaryTextOpacity
    property real opacityBodyAndButton: primaryTextOpacity
    property real opacityTitle: primaryTextOpacity

    property int homeNavigationIndex: 0
    property int addWatchItemIndex: 1
    property var navigationModel: [
        {"name": "HomeRoute", "source": "../components/Home.qml", "activationPolicy": 1, "canGoBack": false, "canCancel": false},
        {"name": "CreateWatchRoute", "source": "../components/CreateWatch.qml", "activationPolicy": 3, "canGoBack":true, "canCancel": true},
    ]

    property bool initDone: true

    property string currentTitle: navigationTitles[navigationIndex]
    property var navigationTitles: [
        qsTr("Train Watch"),
        qsTr("Create Watch Item"),
    ]

    property int firstActiveDestination: homeNavigationIndex
    property int navigationIndex: firstActiveDestination

    // StackView
    property var activationPolicy: {
        "NONE":0, "IMMEDIATELY":1, "LAZY":2, "WHILE_CURRENT":3
    }

    onNavigationIndexChanged: {
        rootView.activateDestination(navigationIndex)
    }

    Material.theme: Material.Light

    header: titleBar
    Loader {
        id: titleBar
        visible: true
        active: true
        source: "routing/DrawerTitleBar.qml"
    }

    StackView {
        id: rootView
        anchors.fill: parent

        replaceEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 300
            }
        }
        replaceExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 300
            }
        }

        Repeater {
            id: destinations
            model: navigationModel
            // Destination encapsulates Loader
            // depends from activationPolicy how to load dynamically
            Destination {
                id: destinationLoader
            }
            // Repeater creates all destinations (Loader)
            // all destinatation items with activationPolicy IMMEDIATELY are activated
        }

        function activateDestination(navigationIndex) {
            if(destinations.itemAt(navigationIndex).status === Loader.Ready) {
                replaceDestination(destinations.itemAt(navigationIndex))
            } else {
                destinations.itemAt(navigationIndex).active = true
            }
        }

        // called from activeDestination() and also from Destination.onLoaded()
        function replaceDestination(theItemLoader) {
            var previousIndex = rootView.currentItem.myIndex
            var previousItemLoader
            if(previousIndex >= 0) {
                previousItemLoader = destinations.itemAt(previousIndex)
            }

            // now replace the Page
            rootView.replace(theItemLoader.item)
            // check if previous should be unloaded

            if(previousIndex >= 0) {
                if(destinations.itemAt(previousIndex).pageActivationPolicy === activationPolicy.WHILE_CURRENT) {
                    destinations.itemAt(previousIndex).active = false
                }
            }
        }
    }

    Component.onCompleted: {
        dataManager.initialize();
        destinations.itemAt(firstActiveDestination).item.init();
        rootView.replace(destinations.itemAt(firstActiveDestination).item);
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
