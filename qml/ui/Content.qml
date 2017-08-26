import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import 'qrc:///components'

Item {
    id: root

    RowLayout {
        id: rowLayout

        anchors.fill: parent

        ColumnLayout {
            id: pickMenu

            Layout.minimumWidth: 50
            Layout.preferredWidth: 100

            Text {
                id: text1
                text: qsTr("Text 1")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 12
            }

            Text {
                id: text2
                text: qsTr("Text 2")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 12
            }

            Text {
                id: text3
                text: qsTr("Text 3")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 12
            }

            Item {
                Layout.fillHeight: true
            }
        }

        ColumnLayout {
            id: notesMenu

            Layout.minimumWidth: 100
            Layout.preferredWidth: 150

            Text {
                text: qsTr("Note 1")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 12
            }

            Text {
                text: qsTr("Note 2")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 12
            }

            Text {
                text: qsTr("Note 3")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pixelSize: 12
            }

            Item {
                Layout.fillHeight: true
            }
        }

        NoteEditor {
            id: editor
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

    }
}
