#pragma once
#ifndef CORBEAU_DATA_NOTEBOOK_H_
#define CORBEAU_DATA_NOTEBOOK_H_

#include <QList>
#include <QObject>
#include <QString>

namespace corbeau {
namespace data {

class Note;

class NoteBook : public QObject
{
    Q_OBJECT

    Q_PROPERTY( QString name READ name WRITE setName NOTIFY nameChanged )
public:
    explicit NoteBook( QObject* parent = nullptr );
    NoteBook( const QString& name, QObject* parent = nullptr );
    NoteBook( const QString& name, const QList< Note* >& notes, QObject* parent = nullptr );

    QString name() const;

    const Note* operator[]( int index ) const;
    Note* operator[]( int index );

    const Note* at( int index ) const;
    Note* at( int index );

    int size() const;

signals:
    void nameChanged( QString name );

public slots:
    void setName( QString name );

private:
    QString m_Name;
    QList< Note* > m_Notes;
};

} // namespace data
} // namespace corbeau

#endif // CORBEAU_DATA_NOTEBOOK_H_
