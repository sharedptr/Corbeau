import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ToolButton {
    id: root

    property string icone: ''

    checkable: true
    Layout.minimumWidth: 50
    Layout.preferredWidth: 50

    contentItem: Image {
        anchors.fill: parent
        source: icone
    }

    background: Rectangle {
        color: Qt.darker("#33333333", root.enabled && (root.checked || root.highlighted) ? 1.5 : 1.0)
        opacity: enabled ? 1 : 0.3
        visible: root.down || (root.enabled && (root.checked || root.highlighted))
    }
}
