import QtQuick 2.5
import QtQuick.Controls 1.4


Item {

    property string pageTitle: ""

    property bool showAcceptButton: false
    property bool enableAcceptButton: false

    property bool showCancelButton: false
    property bool enableCancelButton: false

    signal acceptButtonPressed
    signal cancelButtonPressed


    width: 600
    height: 400
}
