import QtQuick 2.7

Item {
    property var weekDayArray
    Row {
        spacing: 3
        Repeater {
            model: modelFromWeekDayArray()
            WeekdayButton {
                id: btnWeekDay
                checked: modelData.checked
                text: qsTr(modelData.day)

                onClicked: toggle()

                function toggle() {
                    var tmpWeekDayArray = deepCopy(weekDayArray);
                    if(btnWeekDay.checked) {
                        modelData.checked = false;
                        tmpWeekDayArray.push(modelData.idx);
                    }
                    else {
                        modelData.checked = true;
                        var index = tmpWeekDayArray.indexOf(modelData.idx);
                        tmpWeekDayArray.splice(index, 1);
                    }
                    weekDayArray = tmpWeekDayArray.sort();
                }
            }
        }
    }

    function modelFromWeekDayArray() {
        var weekDays = [
                        {"idx": "0", "day": "M", "checked": false},
                        {"idx": "1", "day": "D", "checked": false},
                        {"idx": "2", "day": "M", "checked": false},
                        {"idx": "3", "day": "D", "checked": false},
                        {"idx": "4", "day": "F", "checked": false},
                        {"idx": "5", "day": "S", "checked": false},
                        {"idx": "6", "day": "S", "checked": false}
                       ];
        weekDayArray.forEach(function(weekDay) {
            weekDays[weekDay].checked = true;
        }, this);
        return weekDays;
    }

    function deepCopy(p) {
        var c = [];
        for(var i in p) {
            c[i] = p[i];
        }
        return c;
    }
}
