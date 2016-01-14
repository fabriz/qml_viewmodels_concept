import QtQuick 2.5

import ViewModelsFramework 1.0


Item {

    property FieldBackendBase __backendBase: null
    property string label: (__backendBase !== null) ? __backendBase.label : ""
    property bool showLabel: true
    property int columnSpan: 1

    enabled: (__backendBase !== null) ? __backendBase.enabled : false
    visible: (__backendBase !== null) ? __backendBase.visible : true
    state: (__backendBase !== null) ? __backendBase.state : ""
}
