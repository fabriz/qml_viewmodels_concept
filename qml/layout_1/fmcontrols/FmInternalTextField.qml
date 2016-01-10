import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import "."

TextField {

    id: ctrlRoot

    property int defaultPadding: Math.round(FmMetrics.textFieldHeight / 3)

    property int leftPadding: ctrlRoot.defaultPadding
    property int rightPadding: ctrlRoot.defaultPadding

    property bool updateBackendValueOnLostFocus: true
    property bool updateBackendValueOnTextChange: false

    signal updateBackendValue

    onActiveFocusChanged: {
        if (activeFocus === true) {
            selectAll()
        } else {
            if (updateBackendValueOnLostFocus && !readOnly) {
                updateBackendValue()
            }
        }
    }

    onTextChanged: {
        if (updateBackendValueOnTextChange && !readOnly) {
            updateBackendValue()
        }
    }

    style: TextFieldStyle {

        padding {
            top: 4
            bottom: 4
            left: ctrlRoot.leftPadding
            right: ctrlRoot.rightPadding
        }
    }

}
