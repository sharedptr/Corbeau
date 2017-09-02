#include "notesmodel.h"

#include "data/notebooksmodel.h"
#include "data/notetreenode.h"

namespace corbeau {
namespace data {

NotesModel::NotesModel( QObject* parent )
    : QAbstractProxyModel( parent )
    , m_BooksModel( nullptr )
    , m_CurrentBook( nullptr )
    , m_CurrentIndex( -1 )
    , m_BookIndex( -1 )
{
}

QModelIndex NotesModel::index( int row, int column, const QModelIndex& parent ) const
{
    if( m_CurrentBook == nullptr )
    {
        return QModelIndex();
    }

    auto childItem = m_CurrentBook->child( row );
    if( childItem != nullptr )
    {
        return createIndex( row, column, childItem );
    }

    return QModelIndex();
}

QModelIndex NotesModel::parent( const QModelIndex& child ) const
{
    return sourceModel()->parent( child );
}

int NotesModel::rowCount( const QModelIndex& parent ) const
{
    if( m_BookIndex < 0 )
    {
        return 0;
    }

    auto parentItem = m_BooksModel->getItem( parent );
    auto currentItem = parentItem->child( m_BookIndex );
    return currentItem->childCount();
}

int NotesModel::columnCount( const QModelIndex& parent ) const
{
    return sourceModel()->columnCount( parent );
}

void NotesModel::setSourceModel( QAbstractItemModel* sourceModel )
{
    m_BooksModel = qobject_cast< NoteBooksModel* >( sourceModel );
    QAbstractProxyModel::setSourceModel( sourceModel );
}

QModelIndex NotesModel::mapToSource( const QModelIndex& proxyIndex ) const
{
    if( m_BookIndex < 0 )
    {
        return QModelIndex();
    }

    return proxyIndex;
}

QModelIndex NotesModel::mapFromSource( const QModelIndex& sourceIndex ) const
{
    if( m_BookIndex < 0 )
    {
        return QModelIndex();
    }

    return sourceIndex;
}

int NotesModel::currentIndex() const
{
    return m_CurrentIndex;
}

int NotesModel::bookIndex() const
{
    return m_BookIndex;
}

void NotesModel::setCurrentIndex( int currentIndex )
{
    if( m_CurrentIndex == currentIndex )
    {
        return;
    }

    m_CurrentIndex = currentIndex;
    emit currentIndexChanged( m_CurrentIndex );
}

void NotesModel::setBookIndex( int bookIndex )
{
    if( m_BookIndex == bookIndex )
    {
        return;
    }

    beginResetModel();
    m_BookIndex = bookIndex;
    m_CurrentBook = m_BooksModel->getItem( QModelIndex() )->child( m_BookIndex );
    endResetModel();
    setCurrentIndex( -1 );
    emit bookIndexChanged( m_BookIndex );
}

QHash< int, QByteArray > NotesModel::roleNames() const
{
    return sourceModel()->roleNames();
}

} // namespace data
} // namespace corbeau
