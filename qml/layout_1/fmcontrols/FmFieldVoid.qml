import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import ViewModelsFramework 1.0


FmFieldBase {

	id: ctrlRoot

    readonly property var backend: null

	property string label: ""
	property int messageStatus: FieldMessage.NONE
	property bool formFieldShowLabel: false
}
