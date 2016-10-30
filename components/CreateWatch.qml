import QtQuick 2.4

CreateWatchForm {

    lblTimeArea.onClicked: function() {
        pickTime();
    }

    Loader {
        id: timePickerLoader
        active: false
        visible: false
        source: "../popups/TimePicker.qml"
        onLoaded: {
            item.modal = true
            item.titleText = qsTr("Pickup Time")
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
}
