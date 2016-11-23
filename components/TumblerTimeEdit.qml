import QtQuick 2.4

TumblerTimeEditForm {
    Component.onCompleted: initializeDataModels();

    function initializeDataModels() {
        hourList.append({"value" : 12 + ""});
        for (var ih = 1; ih < 12; ++ih)
            hourList.append({"value" : ih + ""});

        for (var im = 0; im < 60; ++im) {
            minuteList.append({"value" : (im < 10 ? "0" : "") + im });
        }
    }
}
