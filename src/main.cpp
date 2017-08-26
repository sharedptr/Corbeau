#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "corbeau-config.h"

#include "documenthandler.h"

int main( int argc, char* argv[] )
{
    QCoreApplication::setAttribute( Qt::AA_EnableHighDpiScaling );
    QGuiApplication app( argc, argv );

    qmlRegisterType< DocumentHandler >( CORBEAU_NAME, CORBEAU_PLUGIN_VERSION_MAJOR, CORBEAU_PLUGIN_VERSION_MINOR,
                                        "DocumentHandler" );

    QQmlApplicationEngine engine;
    engine.addImportPath( ( QLatin1String( "qrc:///" ) ) );
    engine.load( QUrl( QLatin1String( "qrc:/main.qml" ) ) );
    if( engine.rootObjects().isEmpty() )
    {
        return EXIT_FAILURE;
    }

    return app.exec();
}
