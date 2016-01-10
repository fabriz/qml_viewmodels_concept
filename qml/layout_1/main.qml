import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.2

import "fmcontrols"
import "pages"


ApplicationWindow {
    id: appWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("QML ViewModels Concept")

    Label {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: backButton.height
        text: (appStackView && appStackView.currentItem) ? appStackView.currentItem.pageTitle : qsTr("Untitled")
        font.bold: true
        font.pointSize: Math.round(FmMetrics.appFont.pointSize * 1.2)
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.fillWidth: true
            Layout.preferredHeight: backButton.height
            Layout.maximumHeight: backButton.height

            Button {
                id: backButton
                text: qsTr("Back")
                enabled: appStackView.depth > 1
                visible: appStackView.depth > 1
                onClicked: appStackView.pop()
                Layout.fillHeight: true
            }

            Item {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Button {
                id: acceptButton
                text: qsTr("Accept")
                enabled: (appStackView && appStackView.currentItem) ? appStackView.currentItem.enableAcceptButton : false
                visible: (appStackView && appStackView.currentItem) ? appStackView.currentItem.showAcceptButton : false
                onClicked: appStackView.currentItem.acceptButtonPressed()
                Layout.fillHeight: true
            }

            Button {
                id: cancelButton
                text: qsTr("Cancel")
                enabled: (appStackView && appStackView.currentItem) ? appStackView.currentItem.enableCancelButton : false
                visible: (appStackView && appStackView.currentItem) ? appStackView.currentItem.showCancelButton : false
                onClicked: appStackView.currentItem.cancelButtonPressed()
                Layout.fillHeight: true
            }
        }

        StackView {
            id: appStackView
            focus: true
            Layout.fillWidth: true
            Layout.fillHeight: true

            Keys.onReleased: {
                if (event.key === Qt.Key_Back && appStackView.depth > 1) {
                    appStackView.pop()
                    event.accepted = true
                }
            }

            initialItem: MenuPage { }
        }
    }

    Dialog {
        id: fieldMessagesDialog
        title: qsTr("Field messages")
        standardButtons: StandardButton.Ok

        property alias model: messagesList.model

        onAccepted: {
            messagesList.model = null
        }

        ListView {
            id: messagesList

            delegate: Row {

                FmFormFieldStatusIndicator {
                    width: FmMetrics.textFieldHeight
                    height: FmMetrics.textFieldHeight
                    enableClick: false
                    messageStatus: severity
                }

                Item {
                    width: FmMetrics.standardMargin
                    height: FmMetrics.textFieldHeight
                }

                Text {
                    text: message
                    height: FmMetrics.textFieldHeight
                }
            }
        }
    }

    function showFieldMessages(messages) {
        fieldMessagesDialog.model = messages.messages
        fieldMessagesDialog.open()
    }

}
