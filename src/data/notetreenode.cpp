#include "notetreenode.h"

#include "data/note.h"
#include "data/notebook.h"

namespace corbeau {
namespace data {

NoteTreeNode::NoteTreeNode( QObject* parent )
    : QObject( parent )
    , m_Children()
    , m_Parent( nullptr )
    , m_Note( nullptr )
    , m_NoteBook( nullptr )
    , m_NodeType( NodeType::TNoteBook )
{
}

NoteTreeNode::NoteTreeNode( const QString& name, NoteTreeNode::NodeType type, NoteTreeNode* parent )
    : QObject( parent )
    , m_Children()
    , m_Parent( parent )
    , m_Note( nullptr )
    , m_NoteBook( nullptr )
    , m_NodeType( type )
{
    switch( type )
    {
        case NodeType::TNote:
            m_Note = new Note( name, this );
            break;
        case NodeType::TNoteBook:
            m_NoteBook = new NoteBook( name, this );
            break;
    }
}

NoteTreeNode* NoteTreeNode::child( int index )
{
    return m_Children.value( index );
}

NoteTreeNode* NoteTreeNode::treeParent()
{
    return m_Parent;
}

NoteTreeNode::NodeType NoteTreeNode::nodeType() const
{
    return m_NodeType;
}

QList< NoteTreeNode* > NoteTreeNode::children( NoteTreeNode::NodeType nodeType ) const
{
    QList< NoteTreeNode* > list;
    for( auto item : m_Children )
    {
        if( item->nodeType() == nodeType )
        {
            list << item;
        }
    }
    return list;
}

int NoteTreeNode::myIndex() const
{
    if( m_Parent != nullptr )
    {
        return m_Parent->m_Children.indexOf( const_cast< NoteTreeNode* >( this ) );
    }

    return 0;
}

int NoteTreeNode::childCount() const
{
    return m_Children.size();
}

int NoteTreeNode::columnCount() const
{
    return 1;
}

QVariant NoteTreeNode::data( int column ) const
{
    if( m_Parent == nullptr )
    {
        return QVariant();
    }

    switch( m_NodeType )
    {
        case NodeType::TNote:
            return m_Note->name();
        case NodeType::TNoteBook:
            return m_NoteBook->name();
    }

    return QVariant();
}

void NoteTreeNode::addChild( NoteTreeNode* child )
{
    if( child == nullptr )
    {
        return;
    }
    m_Children << child;
}

} // namespace data
} // namespace corbeau
