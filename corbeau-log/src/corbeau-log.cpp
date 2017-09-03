#include "corbeau-log.h"

#include "corbeau-log-category.h"

#include <QDir>
#include <QMessageLogContext>
#include <QMutex>
#include <QMutexLocker>
#include <QSettings>
#include <QString>
#include <QTextStream>

#include <spdlog/spdlog.h>

#include <memory>
#include <string>

namespace corbeau {
namespace log {
CRBL_CREATE_CAT( log )

namespace {
inline const QLatin1String& messageTypeStr( QtMsgType type )
{
    static const QLatin1String debugMsg( "debug" );
    static const QLatin1String infoMsg( "info" );
    static const QLatin1String warnMsg( "warn" );
    static const QLatin1String critMsg( "critical" );
    static const QLatin1String fatalMsg( "fatal" );

    switch( type )
    {
        case QtDebugMsg:
            return debugMsg;
        case QtInfoMsg:
            return infoMsg;
        case QtWarningMsg:
            return warnMsg;
        case QtCriticalMsg:
            return critMsg;
        case QtFatalMsg:
            return fatalMsg;
    }

    return debugMsg;
}

inline spdlog::level::level_enum getLevel( QtMsgType type )
{
    switch( type )
    {
        case QtDebugMsg:
            return spdlog::level::debug;
        case QtInfoMsg:
            return spdlog::level::info;
        case QtWarningMsg:
            return spdlog::level::warn;
        case QtCriticalMsg:
            return spdlog::level::err;
        case QtFatalMsg:
            return spdlog::level::critical;
    }

    return spdlog::level::off;
}

void messageHandler( QtMsgType type, const QMessageLogContext& context, const QString& message )
{
    static QMutex mutex;
    QMutexLocker lock( &mutex );
    Q_UNUSED( lock );

    QString result;
    QTextStream( &result ) << "[" << messageTypeStr( type ) << "]\t[" << context.category << "]\t" << message;

    spdlog::apply_all(
        [&]( std::shared_ptr< spdlog::logger > logger ) { logger->log( getLevel( type ), result.toStdString() ); } );
}

} // namespace

void init( const QSettings& settings, const QString& logsDirectory )
{
    QDir logsDir( logsDirectory );

    spdlog::set_pattern( "[%Y-%m-%d %H:%M:%S.%e] %v" );
    spdlog::set_level( getLevel( QtDebugMsg ) );

#if defined( CORBEAU_ENABLE_COLOR_LOG )
    spdlog::stdout_color_mt( "console" );
#else
    spdlog::stdout_logger_mt( "console" );
#endif

    Q_UNUSED( settings )
    Q_UNUSED( logsDir )
    qInstallMessageHandler( messageHandler );

    CRBInfo( log ) << "init logging";
}

void finalize()
{
    CRBInfo( log ) << "finalize logging";
    qInstallMessageHandler( nullptr );
    spdlog::drop_all();
}

} // namespace log
} // namespace corbeau
