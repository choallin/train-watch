import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Pane {
    id: overview

    GridLayout {
        id: grid
        columns: 3
        anchors.fill: parent

        MainClock {
            Layout.column: 3
        }

        Repeater {
            model: 2

            AlarmClock {
                Layout.column: 3
            }
        }
    }
}
