import QtQuick 2.7
import "../components"

Item {
    property int myIndex: editWatchItemIndex
    property string name: "EditWatch"

    QtObject {
        id: p
        property string uuid
    }

    WatchItemForm {
        id: watchItemForm
    }

    function init(parameters) {
        p.uuid = parameters.uuid
        var watchItem = dataManager.findWatchItem(p.uuid);
        watchItemForm.init(watchItem);
    }

    function goBack() {
        if(!watchItemForm.watchItem.isValid()) {
            showInfo(qsTr("The Watch-Item could not be saved.\nPlease check your inputs."));
            return false;
        }
        dataManager.saveWatchItem(watchItemForm.watchItem);
        return true;
    }
}
