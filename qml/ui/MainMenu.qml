import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ToolBar {
    id:root

    RowLayout {
        anchors.fill: parent

        ComboBox {
            id: fontFamilyComboBox
            implicitWidth: 150
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
            implicitWidth: 50
            value: 0
            property bool valueGuard: true
            onValueChanged: if (valueGuard) document.fontSize = value
        }

        Item {
            Layout.fillWidth: true
        }
    }
}
