import QtQuick 2.7

Item {

    AlarmClockForm {
        id: alarmOverview
        more.onClicked: toggleAdditionalInformation()
    }

    function toggleAdditionalInformation() {
        if (!alarmOverview.infoContainer.visible) {
            alarmOverview.infoContainer.visible = true
        } else {
            alarmOverview.infoContainer.visible = false
        }

    }
}

