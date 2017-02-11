import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.1

// Weekday Button
Button {
    id: weekdayButton
    highlighted: false
    autoRepeat: false
    checkable: true
    flat: true
    contentItem: Text {
        id: buttonText
        text: weekdayButton.text
        color: weekdayButton.checked ? textOnPrimary : primaryDarkColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }
    background: Rectangle {
        implicitHeight: 40
        implicitWidth: 40
        radius: width/2
        border.color: Material.background
        color: weekdayButton.checked ? primaryColor : Material.background
        border.width: 0
        antialiasing: true
    }
} // Weekday Button
