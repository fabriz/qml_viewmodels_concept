import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import ViewModelsFramework 1.0


FmFieldBase {

    id: ctrlRoot

    property DropDownFieldBackend backend: null

    __backendBase: backend
    implicitHeight: internalField.implicitHeight
    implicitWidth: internalField.implicitWidth

    ComboBox {

        id: internalField

        anchors.fill: parent
        activeFocusOnPress: true
        currentIndex: (backend !== null) ? backend.value : -1
        editable: false
        model: (backend !== null) ? backend.model : null
        textRole: "text"

        onCurrentIndexChanged: {
            if (backend !== null) {
                backend.setValue(internalField.currentIndex)
            }
        }
    }
}
