import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import ViewModelsFramework 1.0

import "."

Item {
    id: ctrlRoot

    default property alias contents: innerColumn.children
    property alias spacing: innerColumn.spacing

    property int margins: FmMetrics.standardMargin

    property var topMargin: null
    property var bottomMargin: null
    property var leftMargin: null
    property var rightMargin: null

    ScrollView {
        id: scrollView
        anchors.fill: parent
        horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff
        verticalScrollBarPolicy: Qt.ScrollBarAsNeeded

        Item {
            id: contentPane

            property int topMarginActive: (ctrlRoot.topMargin === null) ? ctrlRoot.margins : ctrlRoot.topMargin
            property int bottomMarginActive: (ctrlRoot.bottomMargin === null) ? ctrlRoot.margins : ctrlRoot.bottomMargin
            property int leftMarginActive: (ctrlRoot.leftMargin === null) ? ctrlRoot.margins : ctrlRoot.leftMargin
            property int rightMarginActive: (ctrlRoot.rightMargin === null) ? ctrlRoot.margins : ctrlRoot.rightMargin

            width: scrollView.width
            height: (innerColumn.height + (topMarginActive + bottomMarginActive))

            Column {
                id: innerColumn
                x: contentPane.leftMarginActive
                y: contentPane.topMarginActive
                spacing: 0
                width: (scrollView.width - (contentPane.leftMarginActive + contentPane.rightMarginActive))
            }
        }
    }
}
