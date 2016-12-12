import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

Loader {
    id: pageLoader
    property int pageActivationPolicy: modelData.activationPolicy
    active: pageActivationPolicy === activationPolicy.IMMEDIATELY
    visible: false

    source: modelData.source
    onLoaded: {
        item.init()
        if(pageActivationPolicy !== activationPolicy.IMMEDIATELY) {
            rootView.replaceDestination(pageLoader)
        }
    }
    Component.onCompleted: {
        console.log("CREATED DESTINATION "+index)
    }
}
