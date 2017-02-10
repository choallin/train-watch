import QtQuick 2.7
import "../components"

Item {
    property int myIndex: editWatchItemIndex
    property string name: "EditWatch"

    QtObject {
        id: p
        property int watchItemIndex
    }

    WatchItemForm {
        id: watchItemForm
    }

    function init(parameters) {
        p.watchItemIndex = parameters.watchItemIndex
        var watchItem = dataManager.watchItemAt(p.watchItemIndex);
        watchItemForm.init(watchItem);
    }

    function goBack() {
        if(!watchItemForm.watchItem.isValid()) {
            showInfo(qsTr("The Watch-Item could not be saved.\nPlease check your inputs."));
            return false;
        }
        dataManager.saveWatchItem(p.watchItemIndex, watchItemForm.watchItem);
        return true;
    }
}
