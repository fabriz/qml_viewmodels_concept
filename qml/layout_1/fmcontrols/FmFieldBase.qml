import QtQuick 2.5

import ViewModelsFramework 1.0


Item {

    property FieldBackendBase __backendBase: null

    property string label: (__backendBase !== null) ? __backendBase.label : ""
    property int messageStatus: (__backendBase !== null) ? __backendBase.statusMessages.messageStatus : FieldMessage.NONE
    enabled: (__backendBase !== null) ? __backendBase.enabled : false
    visible: (__backendBase !== null) ? __backendBase.visible : true

    // These properties should not be part of fields.
    // They could be attached properties of the FmForm,
    // to be used as FmForm.label and FmForm.span or something like that
    // or be exposed from the backends so that they can be manipulated from the C++ side
    property bool formFieldShowLabel: true
    property int formFieldSpan: 1
}
