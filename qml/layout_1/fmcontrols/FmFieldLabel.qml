import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import ViewModelsFramework 1.0


FmFieldBase {

    id: ctrlRoot

    property LabelFieldBackend backend: null

    __backendBase: backend
    implicitHeight: internalField.implicitHeight
    implicitWidth: internalField.implicitWidth

    Label {

        id: internalField

        anchors.fill: parent
        text: (backend !== null) ? backend.value : "## NOT BOUND ##"
        horizontalAlignment: TextInput.AlignLeft

    }
}
