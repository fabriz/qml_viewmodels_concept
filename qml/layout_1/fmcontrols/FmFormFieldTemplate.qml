import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import ViewModelsFramework 1.0

import "."


Item {

    id: ctrlRoot

    property var field: null

    signal statusIndicatorClicked(FieldMessages messages)

    width: 200
    height: innerColumn.height
    visible: ((field !== null) && (field.backend !== null)) ? field.backend.visible : true

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
            text: (field !== null) ? field.label : ""
            anchors.left: parent.left
            anchors.right: parent.right
            enabled: (field !== null) ? field.enabled : false
            visible: (field !== null) ? field.showLabel : true
        }

        RowLayout {

            Item {
                id: placeholderCtrl
                height: childrenRect.height
                Layout.fillWidth: true
                children: field
            }

            FmFormFieldStatusIndicator {
                id: statusIndicator
                width: FmMetrics.textFieldHeight
                height: FmMetrics.textFieldHeight
                enabled: (field !== null) ? field.enabled : false
                messageStatus: ((field !== null) && (field.backend !== null)) ? field.backend.statusMessages.messageStatus : FieldMessage.NONE
                enableClick: true

                onClicked: {
                    if ((field !== null) && (field.backend !== null)) {
                        statusIndicatorClicked(field.backend.statusMessages)
                    }
                }
            }
        }
    }
}
