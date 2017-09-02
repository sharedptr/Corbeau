import QtQuick 2.7
import QtQuick.Controls 2.2

import 'NoteBooksView'

ListView {
    id: root

    signal itemSelected( int index )

    delegate: NoteBookView {
        onClicked: root.itemSelected( index )
    }
    highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
    focus: true
}
