import QtQuick 2.7
import "../components"

Item {
    property int myIndex: addWatchItemIndex
    property string name: "CreateWatch"

    WatchItemForm {
        id: watchItemForm
    }

    function cancel() {
        dataManager.undoCreateWatchItem(watchItemForm.watchItem);
        return true;
    }

    function init(parameters) {
        var watchItem = dataManager.createWatchItem();
        watchItemForm.init(watchItem);
    }

    function goBack() {
        if(!watchItemForm.watchItem.isValid()) {
            showInfo(qsTr("The Watch-Item could not be created.\nPlease check your inputs."));
            return false;
        }
        dataManager.appendWatchItem(watchItemForm.watchItem);
        return true;
    }
}

