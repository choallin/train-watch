import QtQuick 2.7

Item {

    AlarmClockForm {
        id: alarmOverview
        more.onClicked: showAdditionalInformation()
    }

    function showAdditionalInformation() {
        if (!alarmOverview.infoContainer.visible) {
            alarmOverview.buttonRow.anchors.top = alarmOverview.infoContainer.bottom
            alarmOverview.infoContainer.visible = true
        } else {
            alarmOverview.buttonRow.anchors.top = alarmOverview.offset.bottom
            alarmOverview.buttonRow.anchors.topMargin = 10

            alarmOverview.infoContainer.visible = false
        }

    }
}

