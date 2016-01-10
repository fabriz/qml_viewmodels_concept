import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

import ViewModels 1.0

import "../fmcontrols"


FmPage {

    pageTitle: "Main menu page"

    FmVerticalScroller {
        anchors.fill: parent
        margins: FmMetrics.standardMargin
        spacing: FmMetrics.standardMargin
        leftMargin: Math.round(parent.width / 6)
        rightMargin: Math.round(parent.width / 6)

        Button {
            text: "1 - Basic controls - Simple use of data bound controls"
            anchors.left: parent.left
            anchors.right: parent.right
            height: Math.round(FmMetrics.buttonHeight * 2)
            onClicked: appStackView.push(Qt.resolvedUrl("BasicControlsPage.qml"))
        }

        Button {
            text: "2 - Simple form - Simple form using the form framework"
            anchors.left: parent.left
            anchors.right: parent.right
            height: Math.round(FmMetrics.buttonHeight * 2)
            onClicked: appStackView.push(Qt.resolvedUrl("SimpleFormPage.qml"))
        }

        Button {
            text: "3 - Scrolling form - Scrollable form, same layout and ViewModel of (2)"
            anchors.left: parent.left
            anchors.right: parent.right
            height: Math.round(FmMetrics.buttonHeight * 2)
            onClicked: appStackView.push(Qt.resolvedUrl("SimpleScrollingFormPage.qml"))
        }

        Button {
            text: "4 - Complex form - Complex form layout"
            anchors.left: parent.left
            anchors.right: parent.right
            height: Math.round(FmMetrics.buttonHeight * 2)
            onClicked: appStackView.push(Qt.resolvedUrl("ComplexFormPage.qml"))
        }

        Button {
            text: "5 - Tabbed form - Tabbed form, same layout and ViewModel of (4)"
            anchors.left: parent.left
            anchors.right: parent.right
            height: Math.round(FmMetrics.buttonHeight * 2)
            onClicked: appStackView.push(Qt.resolvedUrl("ComplexTabbedFormPage.qml"))
        }

        Button {
            text: "Settings form - Complex tabbed settings page"
            anchors.left: parent.left
            anchors.right: parent.right
            height: Math.round(FmMetrics.buttonHeight * 2)
            onClicked: appStackView.push(Qt.resolvedUrl("SettingsPage.qml"))
        }
    }
}

