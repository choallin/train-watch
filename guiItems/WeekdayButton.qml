import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

// Weekday Button
Button {
    id: weekdayButton
    highlighted: false
    autoRepeat: false
    checkable: true
    flat: true
    background: Rectangle {
        implicitWidth: 32
        implicitHeight: 32
        radius: implicitWidth / 2
        border.color: weekdayButton.checked ? "black" : "white"
        border.width: 1
        antialiasing: true
    }
} // Weekday Button
