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

    Connections {
        target: timePickerLoader.item
        onClosed: timePickerClosed()
    }

    function timePickerClosed() {
        if(timePickerLoader.item.isOK) {
            console.log("timePicker OK");
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
        console.log("saveWatchItem");
    }
}
