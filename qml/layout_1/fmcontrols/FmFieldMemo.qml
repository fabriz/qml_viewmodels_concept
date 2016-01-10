import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import ViewModelsFramework 1.0


FmFieldBase {

    id: ctrlRoot

    property MemoFieldBackend backend: null

    __backendBase: backend
    implicitHeight: internalField.implicitHeight
    implicitWidth: internalField.implicitWidth

    TextArea {

        id: internalField

        anchors.fill: parent
        horizontalAlignment: TextInput.AlignLeft
        readOnly: (backend !== null) ? backend.readOnly : false
        text: (backend !== null) ? backend.value : "## NOT BOUND ##"
        textFormat: TextEdit.PlainText
        horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff
        verticalScrollBarPolicy: Qt.ScrollBarAsNeeded

        onActiveFocusChanged: {
            if (activeFocus === true) {
                selectAll()
            } else {
                deselect()
                if (!readOnly) {
                    if (backend !== null) {
                        backend.setValue(internalField.text)
                    }
                }
            }
        }
    }
}
