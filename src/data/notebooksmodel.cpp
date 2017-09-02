#include "notebooksmodel.h"

#include "data/notetreenode.h"

namespace corbeau {
namespace data {

NoteBooksModel::NoteBooksModel( QObject* parent )
    : QAbstractItemModel( parent )
    , m_RootNode( new NoteTreeNode( this ) )
    , m_CurrentIndex( -1 )
{
    auto tn = new NoteTreeNode( QLatin1String( "Notebook 1" ), NoteTreeNode::NodeType::TNoteBook, m_RootNode );
    tn->addChild( new NoteTreeNode( QLatin1String( "Note 11" ), NoteTreeNode::NodeType::TNote, tn ) );
    tn->addChild( new NoteTreeNode( QLatin1String( "Note 12" ), NoteTreeNode::NodeType::TNote, tn ) );
    tn->addChild( new NoteTreeNode( QLatin1String( "Note 13" ), NoteTreeNode::NodeType::TNote, tn ) );

    m_RootNode->addChild( tn );
    m_RootNode->addChild(
        new NoteTreeNode( QLatin1String( "Notebook 2" ), NoteTreeNode::NodeType::TNoteBook, m_RootNode ) );

    tn = new NoteTreeNode( QLatin1String( "Notebook 3" ), NoteTreeNode::NodeType::TNoteBook, m_RootNode );
    tn->addChild( new NoteTreeNode( QLatin1String( "Note 31" ), NoteTreeNode::NodeType::TNote, tn ) );
    tn->addChild( new NoteTreeNode( QLatin1String( "Note 32" ), NoteTreeNode::NodeType::TNote, tn ) );
    tn->addChild( new NoteTreeNode( QLatin1String( "Note 33" ), NoteTreeNode::NodeType::TNote, tn ) );
    tn->addChild( new NoteTreeNode( QLatin1String( "Note 34" ), NoteTreeNode::NodeType::TNote, tn ) );
    tn->addChild( new NoteTreeNode( QLatin1String( "Note 35" ), NoteTreeNode::NodeType::TNote, tn ) );
    tn->addChild( new NoteTreeNode( QLatin1String( "Note 36" ), NoteTreeNode::NodeType::TNote, tn ) );

    m_RootNode->addChild( tn );

    if( m_RootNode->childCount() > 0 )
    {
        setCurrentIndex( 0 );
    }
}

NoteBooksModel::~NoteBooksModel()
{
}

int NoteBooksModel::columnCount( const QModelIndex& parent ) const
{
    Q_UNUSED( parent )
    return m_RootNode->columnCount();
}

int NoteBooksModel::rowCount( const QModelIndex& parent ) const
{
    auto parentItem = getItem( parent );
    return parentItem->childCount();
}

Qt::ItemFlags NoteBooksModel::flags( const QModelIndex& index ) const
{
    if( !index.isValid() )
    {
        return Qt::NoItemFlags;
    }

    return QAbstractItemModel::flags( index );
}

QModelIndex NoteBooksModel::index( int row, int column, const QModelIndex& parent ) const
{
    if( parent.isValid() && parent.column() != 0 )
    {
        return QModelIndex();
    }

    auto parentItem = getItem( parent );
    auto childItem = parentItem->child( row );
    if( childItem != nullptr )
    {
        return createIndex( row, column, childItem );
    }

    return QModelIndex();
}

QModelIndex NoteBooksModel::parent( const QModelIndex& child ) const
{
    if( !child.isValid() )
    {
        return QModelIndex();
    }

    auto childItem = getItem( child );
    auto parentItem = childItem->treeParent();

    if( parentItem == m_RootNode )
    {
        return QModelIndex();
    }

    return createIndex( parentItem->myIndex(), 0, parentItem );
}

QVariant NoteBooksModel::data( const QModelIndex& index, int role ) const
{
    if( !index.isValid() )
    {
        return QVariant();
    }

    if( role != Qt::DisplayRole && role != Qt::EditRole )
    {
        return QVariant();
    }

    auto item = getItem( index );
    return item->data( index.column() );
}

int NoteBooksModel::currentIndex() const
{
    return m_CurrentIndex;
}

void NoteBooksModel::setCurrentIndex( int currentIndex )
{
    if( m_CurrentIndex == currentIndex )
    {
        return;
    }

    m_CurrentIndex = currentIndex;
    emit currentIndexChanged( m_CurrentIndex );
}

QHash< int, QByteArray > NoteBooksModel::roleNames() const
{
    QHash< int, QByteArray > roles = QAbstractItemModel::roleNames();
    if( !roles.contains( Qt::DisplayRole ) )
    {
        roles[Qt::DisplayRole] = "display";
    }
    return roles;
}

NoteTreeNode* NoteBooksModel::getItem( const QModelIndex& index ) const
{
    if( index.isValid() )
    {
        auto item = static_cast< NoteTreeNode* >( index.internalPointer() );
        if( item != nullptr )
        {
            return item;
        }
    }
    return m_RootNode;
}

} // namespace data
} // namespace corbeau
