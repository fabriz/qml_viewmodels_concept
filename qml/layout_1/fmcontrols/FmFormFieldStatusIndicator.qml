import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import ViewModelsFramework 1.0


Image {

    id: ctrlRoot

    property int messageStatus: FieldMessage.NONE
    property bool enableClick: false

    signal clicked

    property string __iconSource: {
        if (enabled) {
            switch (messageStatus)
            {
            case FieldMessage.NONE:
                "qrc:/images/empty.svg"
                break
            case FieldMessage.HELP:
                "qrc:/images/help.svg"
                break
            case FieldMessage.INFORMATION:
                "qrc:/images/information.svg"
                break
            case FieldMessage.WARNING:
                "qrc:/images/warning.svg"
                break
            case FieldMessage.ERROR:
                "qrc:/images/error.svg"
                break
            default:
                "qrc:/images/empty.svg"
            }
        }
        else {
            "qrc:/images/empty.svg"
        }
    }

    source: Qt.resolvedUrl(__iconSource)
    sourceSize.height: ctrlRoot.height

    MouseArea {
        anchors.fill: parent
        enabled: (ctrlRoot.enableClick && (ctrlRoot.messageStatus !== FieldMessage.NONE))
        cursorShape: enabled ? Qt.PointingHandCursor : Qt.ArrowCursor

        onClicked: {
            ctrlRoot.clicked()
        }
    }
}
