import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import ViewModelsFramework 1.0


FmFieldBase {

    id: ctrlRoot

    property TextFieldBackend backend: null
    property string placeholderText: (backend !== null) ? backend.placeholderText : ""

    __backendBase: backend
    implicitHeight: internalField.implicitHeight
    implicitWidth: internalField.implicitWidth

    FmInternalTextField {

        id: internalField

        anchors.fill: parent
        placeholderText: ctrlRoot.placeholderText
        readOnly: (backend !== null) ? backend.readOnly : false
        text: (backend !== null) ? backend.value : "## NOT BOUND ##"
        horizontalAlignment: TextInput.AlignLeft

        onUpdateBackendValue: {
            if (backend !== null) {
                backend.setValue(internalField.text)
            }
        }
    }
}
