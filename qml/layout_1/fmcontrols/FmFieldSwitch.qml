import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import ViewModelsFramework 1.0


FmFieldBase {

    id: ctrlRoot

    property SwitchFieldBackend backend: null

    __backendBase: backend
    implicitHeight: internalField.implicitHeight
    implicitWidth: internalField.implicitWidth

    Item {
        implicitHeight: internalField.implicitHeight
        implicitWidth: internalField.implicitWidth

        Switch {
            id: internalField

            anchors.fill: parent
            activeFocusOnPress: true
            checked: (backend !== null) ? backend.value : false

            onCheckedChanged: {
                if (backend !== null) {
                    backend.setValue(internalField.checked)
                }
            }
        }
    }
}
