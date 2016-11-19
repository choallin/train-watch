import QtQuick 2.4

CreateWatchForm {

    btnPickUpTime.onClicked: function() {
        pickTime();
    }

    Loader {
        id: timePickerLoader
        active: false
        visible: false
        source: "../popups/TimePicker.qml"
        onLoaded: {
            item.modal = true
            item.titleText = qsTr("Pick-Up Time")
            item.open()
            item.setDisplay("10:00", false, true)
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
        target: watchItem.station
        property: "name"
        value: txtStation.text
    }
    Binding {
        target: watchItem
        property: "pickUpTime"
        value: lblTime.text
    }
    Binding {
        target: watchItem
        property: "line"
        value: txtLine.text
    }
    Binding {
        target: watchItem
        property: "offset"
        value: spOffset.value
    }

    Connections {
        target: timePickerLoader.item
        onClosed: timePickerClosed()
    }

    function init() {
    }

    function timePickerClosed() {
        if(timePickerLoader.item.isOK) {
            lblTime.text = timePickerLoader.item.hrsDisplay+":"+timePickerLoader.item.minutesDisplay
        }
    }

    function pickTime() {
        if(timePickerLoader.active) {
            timePickerLoader.item.open()
            timePickerLoader.item.onHoursButtonClicked()
        } else {
            timePickerLoader.active = true
        }
    }

    function saveWatchItem() {
        if(!watchItem.isValid()) {
            showInfo(qsTr("The Watch-Item could not be created.\nPlease check your inputs."));
        }
        else {
            dataManager.appendWatchItem(watchItem);
        }
    }
}
