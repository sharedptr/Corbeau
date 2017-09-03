#include "corbeau-config.h"

#include "data/notebooksmodel.h"
#include "data/notesmodel.h"

#include <corbeau-log-category.h>
#include <corbeau-log.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSettings>
#include <QStandardPaths>

CRBL_CREATE_CAT( app )

namespace {

template < typename T >
inline int registerType( const char* qmlName )
{
    CRBDebug( app ) << "Register type with name:" << qmlName;
    return qmlRegisterType< T >( CORBEAU_NAME, CORBEAU_PLUGIN_VERSION_MAJOR, CORBEAU_PLUGIN_VERSION_MINOR, qmlName );
}

} // namespace

int main( int argc, char* argv[] )
{
    QCoreApplication::setAttribute( Qt::AA_EnableHighDpiScaling );
    QCoreApplication::setOrganizationName( QLatin1String( CORBEAU_NAME ) );
    QCoreApplication::setApplicationName( QLatin1String( CORBEAU_NAME ) );
    QCoreApplication::setApplicationVersion( QLatin1String( CORBEAU_VERSION_STR ) );

    QGuiApplication app( argc, argv );

    {
        const QSettings appSettings( QSettings::IniFormat, QSettings::UserScope, app.organizationName(),
                                     app.applicationName() );
        corbeau::log::init( appSettings, QStandardPaths::writableLocation( QStandardPaths::AppLocalDataLocation ) );

        app.connect( &app, QCoreApplication::aboutToQuit, corbeau::log::finalize );
    }

    CRBInfo( app ) << "Start application:" << app.applicationName() << app.applicationVersion();

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
