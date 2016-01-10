import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import ViewModelsFramework 1.0

import "."


Item {

    property alias fieldLabel: labelCtrl.text
    property alias showFieldLabel: labelCtrl.visible
    property alias fieldCtrl: placeholderCtrl.children
    property alias messageStatus: statusIndicator.messageStatus
    property var backend: null

    signal statusIndicatorClicked(FieldMessages messages)


    width: 200
    height: innerColumn.height

//    Rectangle {
//        color: "transparent"
//        border.color: "green"
//        border.width: 4
//        anchors.fill: innerColumn
//        anchors.margins: -4
//    }

    ColumnLayout {
        id: innerColumn
        anchors.left: parent.left
        anchors.right: parent.right

        Label {
            id: labelCtrl
            anchors.left: parent.left
            anchors.right: parent.right
            enabled: (backend !== null) ? backend.enabled : false
        }

        RowLayout {

            Item {
                id: placeholderCtrl
                height: childrenRect.height
                Layout.fillWidth: true
            }

            FmFormFieldStatusIndicator {
                id: statusIndicator
                width: FmMetrics.textFieldHeight
                height: FmMetrics.textFieldHeight
                enabled: (backend !== null) ? backend.enabled : false
                enableClick: true

                onClicked: {
                    if (backend !== null) {
                        statusIndicatorClicked(backend.statusMessages)
                    }
                }
            }
        }
    }
}
