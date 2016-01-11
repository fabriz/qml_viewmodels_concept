import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import ViewModels 1.0

import "../fmcontrols"


FmPage {

    pageTitle: qsTr("Complex form example")
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

    ComplexFormPageViewModel {
        id: viewModel
    }

    FmVerticalScroller {
        anchors.fill: parent

        FmForm {
            columns: 2
            onStatusIndicatorClicked: appWindow.showFieldMessages(messages)

            FmFieldText     {backend: viewModel.userName;                   label: qsTr("User name")}
            FmFieldPassword {backend: viewModel.password;                   label: qsTr("Password")}
            FmFieldText     {backend: viewModel.firstName;                  label: qsTr("First name")}
            FmFieldText     {backend: viewModel.lastName;                   label: qsTr("Last name")}
        }

        FmForm {
            columns: 3
            onStatusIndicatorClicked: appWindow.showFieldMessages(messages)

            FmFieldText     {backend: viewModel.street;                     label: qsTr("Street"); formFieldSpan: 3}
            FmFieldText     {backend: viewModel.city;                       label: qsTr("City"); formFieldSpan: 3}
            FmFieldText     {backend: viewModel.stateOrProvince;            label: qsTr("State/Province")}
            FmFieldText     {backend: viewModel.postalCode;                 label: qsTr("Postal code")}
            FmFieldText     {backend: viewModel.country;                    label: qsTr("Country")}
        }

        FmForm {
            columns: 2
            onStatusIndicatorClicked: appWindow.showFieldMessages(messages)

            FmFieldSwitch   {backend: viewModel.enablePriceFields;          label: qsTr("Set price parameters")}
            FmFieldDropDown {backend: viewModel.priceUnit;                  label: qsTr("Currency")}
            FmFieldQuantity {backend: viewModel.priceMin;                   label: qsTr("Minimim price")}
            FmFieldQuantity {backend: viewModel.priceMax;                   label: qsTr("Maximum price")}
            FmFieldQuantity {backend: viewModel.priceValue;                 label: qsTr("Price")}
            FmFieldVoid     { }
            FmFieldSwitch   {backend: viewModel.enableTemperatureFields;    label: qsTr("Set temperature parameters")}
            FmFieldDropDown {backend: viewModel.temperatureUnit;            label: qsTr("Temperature unit")}
            FmFieldQuantity {backend: viewModel.temperatureMin;             label: qsTr("Minimim temperature")}
            FmFieldQuantity {backend: viewModel.temperatureMax;             label: qsTr("Maximum temperature")}
            FmFieldQuantity {backend: viewModel.temperatureValue;           label: qsTr("Temperature")}
            FmFieldVoid     { }
            FmFieldMemo     {backend: viewModel.notes;                      label: qsTr("Notes"); formFieldSpan: 2}
        }
    }
}
