pragma Singleton
import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {

    Text {
        id: sampleText
        text: "Ap"
        color: "transparent"
    }

    readonly property alias appFont: sampleText.font
    readonly property int appFontHeight: sampleText.height

    readonly property int standardMargin: Math.round(sampleText.height * 0.75)


    TextEdit {
        id: sampleTextEdit
    }

    readonly property int textFieldHeight: sampleTextEdit.height


    Button {
        id: sampleButton
        text: "Ap"
    }

    readonly property int buttonHeight: sampleButton.height

}
