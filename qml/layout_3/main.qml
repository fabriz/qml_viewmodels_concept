import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import ViewModels 1.0

import "../layout_1/fmcontrols"


ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("QML ViewModels Concept")

    ManyFieldsViewModel {
        id: viewModel
    }

    FmVerticalScroller {
        anchors.fill: parent

        FmForm {
            columns: 1

            FmFieldText {backend: viewModel.field_01}
            FmFieldText {backend: viewModel.field_02}
            FmFieldText {backend: viewModel.field_03}
            FmFieldText {backend: viewModel.field_04}
            FmFieldText {backend: viewModel.field_05}
            FmFieldText {backend: viewModel.field_06}
            FmFieldText {backend: viewModel.field_07}
            FmFieldText {backend: viewModel.field_08}
            FmFieldText {backend: viewModel.field_09}
            FmFieldText {backend: viewModel.field_10}
            FmFieldText {backend: viewModel.field_11}
            FmFieldText {backend: viewModel.field_12}
            FmFieldText {backend: viewModel.field_13}
            FmFieldText {backend: viewModel.field_14}
            FmFieldText {backend: viewModel.field_15}
            FmFieldText {backend: viewModel.field_16}
            FmFieldText {backend: viewModel.field_17}
            FmFieldText {backend: viewModel.field_18}
            FmFieldText {backend: viewModel.field_19}
            FmFieldText {backend: viewModel.field_20}
            FmFieldText {backend: viewModel.field_21}
            FmFieldText {backend: viewModel.field_22}
            FmFieldText {backend: viewModel.field_23}
            FmFieldText {backend: viewModel.field_24}
            FmFieldText {backend: viewModel.field_25}
            FmFieldText {backend: viewModel.field_26}
            FmFieldText {backend: viewModel.field_27}
            FmFieldText {backend: viewModel.field_28}
            FmFieldText {backend: viewModel.field_29}
            FmFieldText {backend: viewModel.field_30}
        }
    }
}
