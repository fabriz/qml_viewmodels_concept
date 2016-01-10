import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import ViewModels 1.0

import "../fmcontrols"


FmPage {

    pageTitle: qsTr("Simple scrolling form example")
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

    SimpleFormPageViewModel {
        id: viewModel
    }

    FmVerticalScroller {
        anchors.fill: parent

        FmForm {
            columns: 1

            FmFieldText     {backend: viewModel.name;                   label: qsTr("Name")}
            FmFieldPassword {backend: viewModel.password;               label: qsTr("Password")}
            FmFieldSwitch   {backend: viewModel.enableOptionalFields;   label: qsTr("Enable extra fields")}
            FmFieldInteger  {backend: viewModel.age;                    label: qsTr("Age")}
            FmFieldDropDown {backend: viewModel.gender;                 label: qsTr("Gender")}
            FmFieldQuantity {backend: viewModel.height;                 label: qsTr("Height")}
            FmFieldQuantity {backend: viewModel.weight;                 label: qsTr("Weight")}
            FmFieldMemo     {backend: viewModel.notes;                  label: qsTr("Notes")}
        }
    }
}
