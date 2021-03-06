import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

Loader {
    id: pageLoader

    property int pageActivationPolicy: modelData.activationPolicy
    property var parameters

    active: pageActivationPolicy === activationPolicy.IMMEDIATELY
    visible: false

    source: modelData.source
    onLoaded: {
        item.init(parameters)
        if(pageActivationPolicy !== activationPolicy.IMMEDIATELY) {
            rootView.replaceDestination(pageLoader)
        }
    }
    Component.onCompleted: {
        console.log("CREATED DESTINATION "+index)
    }
}
