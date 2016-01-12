import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.2
import QtQml.Models 2.2

import ViewModelsFramework 1.0

import "."


Item {

    id: ctrlRoot

    default property alias contents: objModel.children
    property int columns: 1
    property int margin: FmMetrics.standardMargin

    height: Math.round(fieldsGrid.height + (2 * ctrlRoot.margin))
    anchors.left: parent.left
    anchors.right: parent.right

    signal statusIndicatorClicked(FieldMessages messages)

    Component.onCompleted: {
        var fieldTemplate = Qt.createComponent("FmFormFieldTemplate.qml")
        for (var i = 0; i < objModel.count; i++) {
            var fld = objModel.children[i]
            if ('backend' in fld) {
                var obj = fieldTemplate.createObject(fieldsGrid, {"field": fld, "Layout.fillWidth": true,
                                                         "Layout.alignment": Qt.AlignTop, "Layout.columnSpan": fld.columnSpan})
                fld.anchors.fill = fld.parent
                obj.statusIndicatorClicked.connect(ctrlRoot.statusIndicatorClicked)
            }
        }

        emptyItem.createObject(fieldsGrid) // This seems to solve a grid layout problem!
    }

    Component {
        id: emptyItem

        Item {
            width: 0
            height: 0
        }
    }

    ObjectModel {
        id: objModel
    }

    //    Rectangle {
    //        color: "transparent"
    //        border.color: "red"
    //        border.width: 4
    //        anchors.fill: parent
    //        anchors.margins: 4
    //    }

    GridLayout {
        id: fieldsGrid

        x: ctrlRoot.margin
        y: ctrlRoot.margin
        width: Math.round(parent.width - (2 * ctrlRoot.margin))
        columns: ctrlRoot.columns
        columnSpacing: ctrlRoot.margin
        rowSpacing: ctrlRoot.margin
    }
}
