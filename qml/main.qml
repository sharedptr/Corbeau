import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import "ui"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Corbeau")

    header: Label {
        id: mainMenu

        height: 50
        text: 'Main menu'
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        background: Rectangle {
            color: 'blue'
        }
    }

    Content {
        id: content
        anchors.fill: parent
    }


    footer: Label {
        id: bottomArea

        height: 50
        text: 'Bottom panel'
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        background: Rectangle {
            color: 'green'
        }
    }
}
