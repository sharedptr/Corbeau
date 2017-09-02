#include "corbeau-config.h"

#include "data/notebooksmodel.h"
#include "data/notesmodel.h"
#include "documenthandler.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

namespace {

template < typename T >
inline int registerType( const char* qmlName )
{
    return qmlRegisterType< T >( CORBEAU_NAME, CORBEAU_PLUGIN_VERSION_MAJOR, CORBEAU_PLUGIN_VERSION_MINOR, qmlName );
}

} // namespace

int main( int argc, char* argv[] )
{
    QCoreApplication::setAttribute( Qt::AA_EnableHighDpiScaling );
    QGuiApplication app( argc, argv );

    registerType< DocumentHandler >( "DocumentHandler" );
    registerType< corbeau::data::NoteBooksModel >( "NoteBooksModel" );
    registerType< corbeau::data::NotesModel >( "NotesModel" );

    QQmlApplicationEngine engine;
    engine.addImportPath( ( QLatin1String( "qrc:///" ) ) );
    engine.load( QUrl( QLatin1String( "qrc:/main.qml" ) ) );
    if( engine.rootObjects().isEmpty() )
    {
        return EXIT_FAILURE;
    }

    return app.exec();
}
