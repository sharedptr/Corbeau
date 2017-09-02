#include "notebook.h"

#include "data/note.h"

namespace corbeau {
namespace data {

NoteBook::NoteBook( QObject* parent )
    : NoteBook( QString(), parent )
{
}

NoteBook::NoteBook( const QString& name, QObject* parent )
    : NoteBook( name, QList< Note* >(), parent )
{
}

NoteBook::NoteBook( const QString& name, const QList< Note* >& notes, QObject* parent )
    : QObject( parent )
    , m_Name( name )
    , m_Notes( notes )
{
    for( auto note : m_Notes )
    {
        note->setParent( this );
    }
}

QString NoteBook::name() const
{
    return m_Name;
}

const Note* NoteBook::operator[]( int index ) const
{
    if( index < 0 || index >= m_Notes.size() )
    {
        return nullptr;
    }

    return m_Notes[index];
}

Note* NoteBook::operator[]( int index )
{
    if( index < 0 || index >= m_Notes.size() )
    {
        return nullptr;
    }

    return m_Notes[index];
}

const Note* NoteBook::at( int index ) const
{
    return operator[]( index );
}

Note* NoteBook::at( int index )
{
    return operator[]( index );
}

int NoteBook::size() const
{
    return m_Notes.size();
}

void NoteBook::setName( QString name )
{
    if( m_Name == name )
    {
        return;
    }

    m_Name = name;
    emit nameChanged( m_Name );
}

} // namespace data
} // namespace corbeau
