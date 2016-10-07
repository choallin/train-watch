import QtQuick 2.7

Item {

    AlarmClockForm {
        id: alarmOverview
        more.onClicked: toggleAdditionalInformation()
    }

    function toggleAdditionalInformation() {
        console.log("bin in der action");
        console.log(alarmOverview.infoContainer);
        console.log(alarmOverview.infoContainer.visible);
        if (!alarmOverview.infoContainer.visible) {
            console.log("versuche auf true zu setzen")
            alarmOverview.infoContainer.visible = true
        } else {
            alarmOverview.infoContainer.visible = false
        }

    }
}

