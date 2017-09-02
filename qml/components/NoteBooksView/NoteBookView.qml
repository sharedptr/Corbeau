import QtQuick 2.7
import QtQuick.Controls 2.2

Item {
    id: root
    signal clicked()

    width: 150
    height: 40
    Text {
        anchors.fill: parent
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        text: '<b>Name:</b> ' + display
    }
    MouseArea {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}
