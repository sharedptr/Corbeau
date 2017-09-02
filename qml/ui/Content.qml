import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQml.Models 2.2

import Corbeau 1.0

import 'qrc:///components'

Item {
    id: root

    RowLayout {
        id: rowLayout

        anchors.fill: parent

        NoteBooksView {
            id: noteBooksView
            Layout.minimumWidth: 100
            Layout.preferredWidth: 150

            Layout.fillHeight: true
            currentIndex: noteBooksModel.currentIndex

            model: NoteBooksModel {
                id: noteBooksModel
            }

            onItemSelected: noteBooksModel.currentIndex = index
        }

        NoteBooksView {
            id: notesView
            Layout.minimumWidth: 100
            Layout.preferredWidth: 150

            Layout.fillHeight: true
            currentIndex: notesModel.currentIndex

            model: NotesModel {
                id: notesModel
                sourceModel: noteBooksModel
                bookIndex: noteBooksModel.currentIndex
            }

            onItemSelected: notesModel.currentIndex = index
        }

        NotesEditor {
            id: editor
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

    }
}
