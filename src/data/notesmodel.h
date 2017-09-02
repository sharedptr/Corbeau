#pragma once
#ifndef CORBEAU_DATA_NOTESMODEL_H_
#define CORBEAU_DATA_NOTESMODEL_H_

#include <QAbstractProxyModel>

namespace corbeau {
namespace data {

class NoteTreeNode;
class NoteBooksModel;

class NotesModel : public QAbstractProxyModel
{
    Q_OBJECT

    Q_PROPERTY( int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged )
    Q_PROPERTY( int bookIndex READ bookIndex WRITE setBookIndex NOTIFY bookIndexChanged )

public:
    explicit NotesModel( QObject* parent = nullptr );

    // QAbstractItemModel interface
public:
    virtual QModelIndex index( int row, int column, const QModelIndex& parent ) const final;
    virtual QModelIndex parent( const QModelIndex& child ) const final;
    virtual int rowCount( const QModelIndex& parent ) const final;
    virtual int columnCount( const QModelIndex& parent ) const final;

    virtual QHash< int, QByteArray > roleNames() const final;

    // QAbstractProxyModel interface
public:
    virtual void setSourceModel( QAbstractItemModel* sourceModel ) final;
    virtual QModelIndex mapToSource( const QModelIndex& proxyIndex ) const final;
    virtual QModelIndex mapFromSource( const QModelIndex& sourceIndex ) const final;

public:
    int currentIndex() const;
    int bookIndex() const;

signals:
    void currentIndexChanged( int currentIndex );
    void bookIndexChanged( int bookIndex );

public slots:
    void setCurrentIndex( int currentIndex );
    void setBookIndex( int bookIndex );

private:
    NoteBooksModel* m_BooksModel;
    NoteTreeNode* m_CurrentBook;
    int m_CurrentIndex;
    int m_BookIndex;
};

} // namespace data
} // namespace corbeau

#endif // CORBEAU_DATA_NOTESMODEL_H_
