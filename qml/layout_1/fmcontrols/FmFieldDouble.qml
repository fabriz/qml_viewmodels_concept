import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import ViewModelsFramework 1.0


FmFieldBase {

    id: ctrlRoot

    property DoubleFieldBackend backend: null

    __backendBase: backend
    implicitHeight: internalField.implicitHeight
    implicitWidth: internalField.implicitWidth

    FmInternalTextField {

        id: internalField

        anchors.fill: parent
        horizontalAlignment: TextInput.AlignRight
        inputMethodHints: Qt.ImhFormattedNumbersOnly
        readOnly: (backend !== null) ? backend.readOnly : false
        text: (backend !== null) ? backend.value.toFixed(backend.decimals) : "## NOT BOUND ##"

        validator: DoubleValidator {
            bottom: (backend !== null) ? backend.minValue : 0
            top: (backend !== null) ? backend.maxValue : 0
            decimals: (backend !== null) ? backend.decimals : 0
            notation: DoubleValidator.StandardNotation
        }

        onUpdateBackendValue: {
            if (backend !== null) {
                backend.setValue(internalField.text)
            }
        }
    }
}
