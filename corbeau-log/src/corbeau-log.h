#pragma once
#ifndef CORBEAU_CORBEAULOG_H_
#define CORBEAU_CORBEAULOG_H_

#include "corbeau-log-export.h"

class QString;
class QSettings;

namespace corbeau {
namespace log {

CORBEAU_LOG_EXPORT void init( const QSettings& settings, const QString& logsDirectory );
CORBEAU_LOG_EXPORT void finalize();

} // namespace log
} // namespace corbeau

#endif // CORBEAU_CORBEAULOG_H_
