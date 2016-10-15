import QtQuick 2.4

CreateWatchForm {

    txtPickupTime.onFocusChanged: state = 'State1'

    function changeState() {
        state = 'basestate'
    }
}
