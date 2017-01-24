import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.0
import org.trainwatch.data 1.0
import QtQml 2.2
import "../guiItems"
import "../guiDelegates"

Item {
    property int myIndex: 1
    property string name: "CreateWatch"
    property WatchItem watchItem

    StackView {
        id: createWatchStack
        anchors.fill: parent;

        Component {
            id: suggestionListComponent
            SuggestionList {
                id: suggestionList

                onSearch: function(searchString) {
                    trainWatchApi.getStations(searchString);
                }

                onItemSelected: function(data) {
                    createWatchStack.pop();
                    watchItem.station = data;
                }

                Connections {
                    target: trainWatchApi
                    onStationsFinished: {
                        suggestionList.addItems(stations);
                    }
                }
            }
        }

        Component {
            id: countriesListComponent
            ItemList {
                id: countriesList
                listItemDelegate: CountryRowDelegate {
                    id: countryRowDelegate

                    onItemClicked: function(data) {
                        createWatchStack.pop();
                        watchItem.country = data;
                    }
                }

                Connections {
                    target: trainWatchApi
                    onCountriesFinished: {
                        countriesList.setModel(countries);
                    }
                }
            }
        }

        Component {
            id: schedulesListComponent
            ItemList {
                id: schedulesList
                listItemDelegate: ScheduleRowDelegate {
                    id: scheduleRowDelegate

                    onItemClicked: function(data) {
                        createWatchStack.pop();
                        watchItem.schedule = data;
                    }
                }

                Connections {
                    target: trainWatchApi
                    onSchedulesFinished: {
                        schedulesList.setModel(schedules);
                    }
                }
            }
        }

        Component {
            id: formComponent
            Item {
                id: form
                width: parent.width
                height: 400

                GridLayout {
                    anchors.rightMargin: 20
                    anchors.leftMargin: 20
                    anchors.bottomMargin: 0
                    anchors.topMargin: 0
                    anchors.fill: parent
                    rows: 2
                    columns: 1

                    TextField {
                        id: txtTitle
                        placeholderText: qsTr("Title")
                        Layout.fillWidth: true
                        text: watchItem ? watchItem.title : ''
                    }

                    Switch {
                        id: swActive
                        text: qsTr("Active")
                        Layout.fillWidth: true
                        Layout.preferredHeight: 40
                        Layout.preferredWidth: 200
                        checked: watchItem ? watchItem.active : true
                    }

                    TextField {
                        id: txtCountry
                        placeholderText: qsTr("Country")
                        Layout.fillWidth: true
                        Layout.fillHeight: false
                        text: watchItem ? watchItem.country.name : ''
                        onActiveFocusChanged: function(active) {
                            if(active) {
                                trainWatchApi.getCountries();
                                createWatchStack.push(countriesListComponent);
                            }
                        }
                    }

                    TextField {
                        id: txtStation
                        Layout.fillWidth: true
                        placeholderText: qsTr("Station")
                        text: watchItem ? watchItem.station.name : ''
                        onActiveFocusChanged: function(active) {
                            if(active) {
                                createWatchStack.push(suggestionListComponent);
                            }
                        }
                    }

                    RowLayout {
                        id: rowLayout2
                        width: 100
                        height: 100
                        Layout.fillWidth: true

                        Label {
                            id: lblTime
                            text: watchItem ? Qt.formatDateTime(watchItem.pickUpTime, "hh:mm") : ''
                        }

                        ButtonIconActive {
                            id: btnPickUpTime
                            visible: true
                            imageName: "time.png"
                            onClicked: function() {
                                pickTime();
                            }
                        }
                    }

                    TextField {
                        id: txtLine
                        placeholderText: qsTr("Line")
                        Layout.fillWidth: true
                        text: watchItem ? watchItem.schedule.line + " " + Qt.formatDateTime(watchItem.schedule.departure, "hh:mm") : ''
                        onActiveFocusChanged: function(active) {
                            if(active) {
                                trainWatchApi.getSchedules(watchItem);
                                createWatchStack.push(schedulesListComponent);
                            }
                        }
                    }

                    RowLayout {
                        id: rowLayout1
                        x: 47
                        y: 388
                        width: 100
                        height: 100
                        Layout.fillHeight: false
                        Layout.fillWidth: true

                        Label {
                            id: lblOffset
                            text: qsTr("Offset(minutes):")
                        }

                        SpinBox {
                            id: spOffset
                            value: watchItem ? watchItem.offset : 0
                            editable: false
                        }
                    }

                    WeekdayToggle {
                        id: weekdayToggle
                        weekDayArray: watchItem ? watchItem.weekDays : []
                        Layout.fillWidth: true
                    }
                }

                Binding {
                    target: watchItem
                    property: "title"
                    value: txtTitle.text
                }
                Binding {
                    target: watchItem
                    property: "active"
                    value: swActive.checked
                }
                Binding {
                    target: watchItem
                    property: "country"
                    value: txtCountry.text
                }
                Binding {
                    target: watchItem
                    property: "station.name"
                    value: txtStation.text
                }
                Binding {
                    target: watchItem
                    property: "pickUpTime"
                    value: lblTime.text
                }
                Binding {
                    target: watchItem
                    property: "schedule.id"
                    value: txtLine.text
                }
                Binding {
                    target: watchItem
                    property: "offset"
                    value: spOffset.value
                }
                Binding {
                    target: watchItem
                    property: "weekDays"
                    value: weekdayToggle.weekDayArray
                }

                Loader {
                    id: timePickerLoader
                    active: false
                    visible: false
                    source: "../popups/TimePicker.qml"
                    onLoaded: {
                        item.modal = true;
                        item.titleText = qsTr("Pick-Up Time");
                        item.open();
                        item.setDisplay("10:00", false, true);
                    }
                }

                Connections {
                    target: timePickerLoader.item
                    onClosed: timePickerClosed()
                }

                function timePickerClosed() {
                    if(timePickerLoader.item.isOK) {
                        lblTime.text = timePickerLoader.item.hrsDisplay+":"+timePickerLoader.item.minutesDisplay
                    }
                }

                function pickTime() {
                    if(timePickerLoader.active) {
                        timePickerLoader.item.open();
                        timePickerLoader.item.onHoursButtonClicked();
                    }
                    else {
                        timePickerLoader.active = true;
                    }
                }
            }
        }
    }

    function cancel() {
        dataManager.undoCreateWatchItem(watchItem);
        return true;
    }

    function init() {
        watchItem = dataManager.createWatchItem();
        createWatchStack.push(formComponent);
    }

    function goBack() {
        if(!watchItem.isValid()) {
            showInfo(qsTr("The Watch-Item could not be created.\nPlease check your inputs."));
            return false;
        }
        dataManager.appendWatchItem(watchItem);
        return true;
    }
}

