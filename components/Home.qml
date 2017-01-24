import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "../guiItems"
import "../models"

Item {
    property int myIndex: 0
    property string name: "HomePage"

    Page {
        id: homePage
        focus: true
        anchors.fill: parent;

        bottomPadding: 6
        topPadding: 6

        header: MainClock {
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: childrenRect.height
        }

        // WatchItem Row-Component
        Component {
            id: watchItemRowComponent
            ColumnLayout {
                id: watchItemRow
                implicitWidth: appWindow.width

                RowLayout {
                    spacing: 20
                    Layout.leftMargin: 10
                    Layout.rightMargin: 6
                    Layout.topMargin: 6

                    ColumnLayout {
                        Layout.fillWidth: true
                        spacing: 0

                        RowLayout {
                            Layout.fillWidth: true
                            LabelSubheading {
                                rightPadding: 12
                                text: model.modelData.title
                                font.bold: true
                                wrapMode: Label.WordWrap
                            } // label

                            Switch {
                                checked: model.modelData.active
                            }
                        }

                        Label {
                            rightPadding: 12
                            text: "<b>Station:</b>&ensp; " + model.modelData.station.name
                            Layout.fillWidth: true
                            opacity: opacityBodyAndButton
                        }

                        Label {
                            rightPadding: 12
                            text: "<b>Line:</b>&ensp;&ensp; " + model.modelData.schedule.line
                            Layout.fillWidth: true
                            opacity: opacityBodyAndButton
                        }

                        Label {
                            rightPadding: 12
                            text: Qt.formatDateTime(model.modelData.schedule.departure, "hh:mm")
                            Layout.fillWidth: true
                            font.pixelSize: fontSizeSuperTitle
                            opacity: opacitySubheading
                        }

                        WeekdayPresentation {
                            id: weekdayPresentation
                            rightPadding: 12
                            weekDayArray: model.modelData.weekDays
                            Layout.fillWidth: true
                        }
                    }
                }
                HorizontalListDivider{}
            }
        } // WatchItem Row-Component

        ColumnLayout {
            spacing: 2
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.height
            focus: true

            ListView {
                id: watchItemView
                clip: true
                focus: true
                anchors.fill: parent
                delegate: watchItemRowComponent

                height: parent.height

                currentIndex: -1

                ScrollIndicator.vertical: ScrollIndicator { }
            }
        }
    }

    // called immediately after Loader.loaded
    function init() {
        watchItemView.model = dataManager.watchItemPropertyList;
    }
}
