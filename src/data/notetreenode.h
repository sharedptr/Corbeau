#pragma once
#ifndef CORBEAU_DATA_NOTETREENODE_H_
#define CORBEAU_DATA_NOTETREENODE_H_

#include <QList>
#include <QObject>
#include <QVariant>

namespace corbeau {
namespace data {

class Note;
class NoteBook;

class NoteTreeNode : public QObject
{
    Q_OBJECT

public:
    enum class NodeType : quint8
    {
        TNote = 0,
        TNoteBook
    };

    enum NodeRole
    {
        Name = Qt::UserRole + 1
    };

    explicit NoteTreeNode( QObject* parent = nullptr );
    NoteTreeNode( const QString& name, NodeType type, NoteTreeNode* parent );

    NoteTreeNode* child( int index );
    NoteTreeNode* treeParent();
    NodeType nodeType() const;
    QList< NoteTreeNode* > children( NodeType nodeType ) const;

    int myIndex() const;
    int childCount() const;
    int columnCount() const;
    QVariant data( int column ) const;

    void addChild( NoteTreeNode* child );

signals:

public slots:

private:
    QList< NoteTreeNode* > m_Children;
    NoteTreeNode* m_Parent;
    Note* m_Note;
    NoteBook* m_NoteBook;
    NodeType m_NodeType;
};

} // namespace data
} // namespace corbeau

#endif // CORBEAU_DATA_NOTETREENODE_H_
