import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    property var weekDayArray
    property var rightPadding

    implicitHeight: weekDayPresentationLabel.implicitHeight

    Label {
        id: weekDayPresentationLabel
        rightPadding: rightPadding
        text: computedText()
        font.pixelSize: fontSizeSubheading
        opacity: opacitySubheading
    }

    function computedText() {
        if(weekDayArray.length === 7) {
            return 'Every day';
        }
        else if(weekDayArray.length === 0) {
            return "Tomorrow";
        }
        else {
            var weekDayNames = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'];
            return weekDayArray.map(function(weekDay) {
                return weekDayNames[weekDay];
            }, this).join(', ');
        }
    }
}
