import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import ViewModelsFramework 1.0


FmFieldBase {

    id: ctrlRoot

    property QuantityFieldBackend backend: null
    property string prefixText: (backend !== null) ? backend.prefixText : ""
    property string suffixText: (backend !== null) ? backend.suffixText : ""

    __backendBase: backend
    implicitHeight: internalField.implicitHeight
    implicitWidth: internalField.implicitWidth

    FmInternalTextField {

        id: internalField

        anchors.fill: parent
        horizontalAlignment: TextInput.AlignRight
        inputMethodHints: Qt.ImhFormattedNumbersOnly
        readOnly: (backend !== null) ? backend.readOnly : false
        text: (backend !== null) ? backend.displayValue.toFixed(backend.decimals) : "## NOT BOUND ##"

        leftPadding: (prefixText === "") ? internalField.defaultPadding : (2 * internalField.defaultPadding) + labelPrefix.width
        rightPadding: (suffixText === "") ? internalField.defaultPadding : (2 * internalField.defaultPadding) + labelSuffix.width

        validator: DoubleValidator {
            bottom: (backend !== null) ? backend.minDisplayValue : 0
            top: (backend !== null) ? backend.maxDisplayValue : 0
            decimals: (backend !== null) ? backend.decimals : 0
            notation: DoubleValidator.StandardNotation
        }

        Label {
            id: labelPrefix
            text: ctrlRoot.prefixText
            anchors.verticalCenter: internalField.verticalCenter
            anchors.left: internalField.left
            anchors.leftMargin: internalField.defaultPadding
        }

        Label {
            id: labelSuffix
            text: ctrlRoot.suffixText
            anchors.verticalCenter: internalField.verticalCenter
            anchors.right: internalField.right
            anchors.rightMargin: internalField.defaultPadding
        }

        onUpdateBackendValue: {
            if (backend !== null) {
                backend.setDisplayValue(internalField.text)
            }
        }
    }
}
