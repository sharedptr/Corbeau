import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

import Qt.labs.platform 1.0

import 'NotesEditor'

import org.Qotes 1.0

Item {
    id: root

    RowLayout {
        id: editorMenu
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        height: 50

        CheckedToolButton {
            id: ctrlBold

            icone: 'qrc:///images/NotesEditor/textbold.png'
            checked: document.bold
            onClicked: document.bold = !document.bold
        }

        CheckedToolButton {
            id: ctrlItalic

            icone: 'qrc:///images/NotesEditor/textitalic.png'
            checked: document.italic
            onClicked: document.italic = !document.italic
        }

        CheckedToolButton {
            id: ctrlUnderline

            icone: 'qrc:///images/NotesEditor/textunder.png'
            checked: document.underline
            onClicked: document.underline = !document.underline
        }

        ToolSeparator {}

        CheckedToolButton {
            id: ctrlAlignLeft

            icone: 'qrc:///images/NotesEditor/textleft.png'
            checked: document.alignment == Qt.AlignLeft
            onClicked: document.alignment = Qt.AlignLeft
        }

        CheckedToolButton {
            id: ctrlAlignCenter

            icone: 'qrc:///images/NotesEditor/textcenter.png'
            checked: document.alignment == Qt.AlignHCenter
            onClicked: document.alignment = Qt.AlignHCenter
        }

        CheckedToolButton {
            id: ctrlAlignRight

            icone: 'qrc:///images/NotesEditor/textright.png'
            checked: document.alignment == Qt.AlignRight
            onClicked: document.alignment = Qt.AlignRight
        }

        CheckedToolButton {
            id: ctrlAlignJustify

            icone: 'qrc:///images/NotesEditor/textjustify.png'
            checked: document.alignment == Qt.AlignJustify
            onClicked: document.alignment = Qt.AlignJustify
        }

        ToolSeparator {}

        ComboBox {
            id: fontFamilyComboBox
            Layout.minimumWidth: 150
            Layout.preferredWidth: 150
            model: Qt.fontFamilies()
            property bool special : false
            onActivated: {
                if (special == false || index != 0) {
                    document.fontFamily = textAt(index)
                }
            }
        }

        SpinBox {
            id: fontSizeSpinBox
            // activeFocusOnPress: false
            Layout.minimumWidth: 100
            Layout.preferredWidth: 100
            value: 0
            property bool valueGuard: true
            onValueChanged: if (valueGuard) document.fontSize = value
        }

        ToolSeparator {}

        ColorDialog {
            id: colorDialog
            color: 'black'
        }

        Item {
            Layout.fillWidth: true
        }

    }

    ScrollView {
        id: view

        anchors.top: editorMenu.bottom
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left

        // ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        TextArea {
            Accessible.name: "document"
            id: textArea

            selectByMouse: true
            mouseSelectionMode: TextEdit.SelectCharacters
            baseUrl: "qrc:/"
            text: document.text
            anchors.fill: parent
            textFormat: Qt.RichText
            Component.onCompleted: forceActiveFocus()
        }

        DocumentHandler {
            id: document
            target: textArea
            cursorPosition: textArea.cursorPosition
            selectionStart: textArea.selectionStart
            selectionEnd: textArea.selectionEnd
            textColor: colorDialog.color
            Component.onCompleted: document.fileUrl = "qrc:/example.html"
            onFontSizeChanged: {
                fontSizeSpinBox.valueGuard = false
                fontSizeSpinBox.value = document.fontSize
                fontSizeSpinBox.valueGuard = true
            }
            onFontFamilyChanged: {
                var index = Qt.fontFamilies().indexOf(document.fontFamily)
                if (index == -1) {
                    fontFamilyComboBox.currentIndex = 0
                    fontFamilyComboBox.special = true
                } else {
                    fontFamilyComboBox.currentIndex = index
                    fontFamilyComboBox.special = false
                }
            }
            onError: {
                errorDialog.text = message
                errorDialog.visible = true
            }
        }
    }
}
