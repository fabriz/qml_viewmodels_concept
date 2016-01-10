import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import ViewModels 1.0

import "../fmcontrols"


FmPage {

    pageTitle: qsTr("Basic controls example")
    showAcceptButton: true
    enableAcceptButton: viewModel.modified
    showCancelButton: true
    enableCancelButton: true

    onAcceptButtonPressed: {
        viewModel.acceptButtonHandler()
    }

    onCancelButtonPressed: {
        appStackView.pop()
    }

    BasicControlsPageViewModel {
        id: viewModel
    }

    GridLayout {
        width: Math.round(parent.width * 2 / 3)
        anchors.centerIn: parent
        columns: 2
        columnSpacing: 20

        Label {text: qsTr("Name")}
        FmFieldText {
            backend: viewModel.name
            Layout.fillWidth: true
        }

        Label {text: qsTr("Password")}
        FmFieldPassword {
            backend: viewModel.password
            Layout.fillWidth: true
        }

        Label {text: qsTr("Enable extra fields")}
        FmFieldSwitch {
            backend: viewModel.enableOptionalFields
            Layout.fillWidth: true
        }

        Label {text: qsTr("Age"); enabled: viewModel.enableOptionalFields.value}
        FmFieldInteger {
            backend: viewModel.age
            Layout.fillWidth: true
        }

        Label {text: qsTr("Gender"); enabled: viewModel.enableOptionalFields.value}
        FmFieldDropDown {
            backend: viewModel.gender
            Layout.fillWidth: true
        }

        Label {text: qsTr("Height"); enabled: viewModel.enableOptionalFields.value}
        FmFieldQuantity {
            backend: viewModel.height
            Layout.fillWidth: true
        }

        Label {text: qsTr("Weight"); enabled: viewModel.enableOptionalFields.value}
        FmFieldQuantity {
            backend: viewModel.weight
            Layout.fillWidth: true
        }

        Label {text: qsTr("Notes"); enabled: viewModel.enableOptionalFields.value}
        FmFieldMemo {
            backend: viewModel.notes
            Layout.fillWidth: true
        }
    }
}

