#pragma once
#ifndef CORBEAU_DATA_NOTEBOOKSMODEL_H_
#define CORBEAU_DATA_NOTEBOOKSMODEL_H_

#include <QAbstractItemModel>

namespace corbeau {
namespace data {

class NoteTreeNode;
class NotesModel;

class NoteBooksModel : public QAbstractItemModel
{
    Q_OBJECT

    Q_PROPERTY( int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged )
    friend class NotesModel;

public:
    explicit NoteBooksModel( QObject* parent = nullptr );
    virtual ~NoteBooksModel();

    // QAbstractItemModel interface
public:
    virtual int columnCount( const QModelIndex& parent ) const final;
    virtual int rowCount( const QModelIndex& parent ) const final;
    virtual Qt::ItemFlags flags( const QModelIndex& index ) const final;
    virtual QModelIndex index( int row, int column, const QModelIndex& parent ) const final;
    virtual QModelIndex parent( const QModelIndex& child ) const final;
    virtual QVariant data( const QModelIndex& index, int role ) const final;

    virtual QHash< int, QByteArray > roleNames() const final;

public:
    int currentIndex() const;

signals:
    void currentIndexChanged( int currentIndex );

public slots:
    void setCurrentIndex( int currentIndex );

private:
    NoteTreeNode* m_RootNode;
    int m_CurrentIndex;

    NoteTreeNode* getItem( const QModelIndex& index ) const;
};

} // namespace data
} // namespace corbeau

#endif // CORBEAU_DATA_NOTEBOOKSMODEL_H_
