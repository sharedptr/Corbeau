#include "note.h"

namespace corbeau {
namespace data {

Note::Note( QObject* parent )
    : Note( QString(), parent )
{
}

Note::Note( const QString& name, QObject* parent )
    : QObject( parent )
    , m_Name( name )
{
}

QString Note::name() const
{
    return m_Name;
}

void Note::setName( QString name )
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
