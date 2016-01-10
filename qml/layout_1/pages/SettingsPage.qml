import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import ViewModels 1.0

import "../fmcontrols"


FmPage {

    pageTitle: "Example settings page"

    SettingsPageViewModel {
        id: viewModel
    }

    Component.onCompleted: {
        console.log("SettingsPage load completed.")
        console.count("SettingsPage.Component.onCompleted")
    }


    TabView {
        anchors.fill: parent

        Tab {
            title: qsTr("All")

            GridLayout {
                columns: 4
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right

                Label {text: "Field 1:"}
                FmFieldText {
                    Layout.fillWidth: true
                    backend: viewModel.field_1
                }

                Label {text: "Field 1 (again!):"}
                FmFieldText {
                    Layout.fillWidth: true
                    backend: viewModel.field_1
                }

                Label {text: "Field 2:"}
                FmFieldText {
                    Layout.fillWidth: true
                    backend: viewModel.field_2
                }

                Label {text: "Field 3:"}
                FmFieldText {
                    Layout.fillWidth: true
                    backend: viewModel.field_3
                }

                Label {text: "Field 4:"}
                FmFieldText {
                    Layout.fillWidth: true
                    backend: viewModel.field_4
                }

                Label {text: "Field 20:"}
                FmFieldInteger {
                    Layout.fillWidth: true
                    backend: viewModel.field_20
                }

                Label {text: "Field 21:"}
                FmFieldInteger {
                    Layout.fillWidth: true
                    backend: viewModel.field_21
                }

                Label {text: "Field 22:"}
                FmFieldInteger {
                    Layout.fillWidth: true
                    backend: viewModel.field_22
                }

                Label {text: "Field 30:"}
                FmFieldDouble {
                    Layout.fillWidth: true
                    backend: viewModel.field_30
                }

                Label {text: "Field 31:"}
                FmFieldDouble {
                    Layout.fillWidth: true
                    backend: viewModel.field_31
                }

                Label {text: "Field 32:"}
                FmFieldDouble {
                    Layout.fillWidth: true
                    backend: viewModel.field_32
                }

                Label {text: "Field 40:"}
                FmFieldQuantity {
                    Layout.fillWidth: true
                    backend: viewModel.field_40
                }

                Label {text: "Field 41:"}
                FmFieldQuantity {
                    Layout.fillWidth: true
                    backend: viewModel.field_41
                }

                Label {text: "Field 42:"}
                FmFieldQuantity {
                    Layout.fillWidth: true
                    backend: viewModel.field_42
                }


                Button {
                    text: "Change text of Field 1"
                    onClicked: viewModel.buttonHandler1()
                }

                Button {
                    text: "Change value of Field 20"
                    onClicked: viewModel.buttonHandler2()
                }

                Button {
                    text: "Change value of Field 30"
                    onClicked: viewModel.buttonHandler3()
                }

                Button {
                    text: "Show/hide field 4"
                    onClicked: viewModel.buttonHandler4()
                }
            }
        }

        Tab {
            title: qsTr("Temperature")

            GridLayout {
                columns: 4
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right

                Label {text: "Field 1:"}
                FmFieldText {
                    Layout.fillWidth: true
                    backend: viewModel.field_1
                }

                Label {text: "Field 1 (again!):"}
                FmFieldText {
                    Layout.fillWidth: true
                    backend: viewModel.field_1
                }

                Label {text: "Field 20:"}
                FmFieldInteger {
                    Layout.fillWidth: true
                    backend: viewModel.field_20
                }

                Label {text: "Field 30:"}
                FmFieldDouble {
                    Layout.fillWidth: true
                    backend: viewModel.field_30
                }

                Label {text: "Field 40:"}
                FmFieldQuantity {
                    Layout.fillWidth: true
                    backend: viewModel.field_40
                }


                Button {
                    text: "Change text of Field 1"
                    onClicked: viewModel.buttonHandler1()
                }

                Button {
                    text: "Change value of Field 20"
                    onClicked: viewModel.buttonHandler2()
                }

                Button {
                    text: "Change value of Field 30"
                    onClicked: viewModel.buttonHandler3()
                }
            }
        }

        Tab {
            title: qsTr("Varie ed eventuali 1")
        }

        Tab {
            title: qsTr("Varie ed eventuali 2")
        }

        Tab {
            title: qsTr("Varie ed eventuali 3")
        }

        Tab {
            title: qsTr("Varie ed eventuali 4")
        }

        Tab {
            title: qsTr("Varie ed eventuali 5")
        }

        Tab {
            title: qsTr("Varie ed eventuali 6")
        }

    }




}

