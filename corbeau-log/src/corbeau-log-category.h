#pragma once
#ifndef CORBEAU_LOG_CATEGORY_H_
#define CORBEAU_LOG_CATEGORY_H_

#include "corbeau-config.h"

#include <QDebug>
#include <QLoggingCategory>

#define CRBL_DEF_CAT( group ) Q_DECLARE_LOGGING_CATEGORY( crbLog_##group )
#define CRBL_DECL_CAT( group ) Q_LOGGING_CATEGORY( crbLog_##group, CORBEAU_NAME "." #group )
#define CRBL_DECL_CAT_CLASS( className, group )                                                                        \
    Q_LOGGING_CATEGORY( crbLog_##className, CORBEAU_NAME "." #group "." #className )

#define CRBL_CREATE_CAT( group )                                                                                       \
    CRBL_DEF_CAT( group );                                                                                             \
    CRBL_DECL_CAT( group );

#define CRBL_CREATE_CAT_CLASS( className, group )                                                                      \
    CRBL_DEF_CAT( className );                                                                                         \
    CRBL_DECL_CAT_CLASS( className, group );

#define CRBLOG( name, Type ) qC##Type( crbLog_##name )
#define CRBDebug( name ) CRBLOG( name, Debug )
#define CRBInfo( name ) CRBLOG( name, Info )
#define CRBWarn( name ) CRBLOG( name, Warnin )
#define CRBCrit( name ) CRBLOG( name, Critical )

#endif // CORBEAU_LOG_CATEGORY_H_
