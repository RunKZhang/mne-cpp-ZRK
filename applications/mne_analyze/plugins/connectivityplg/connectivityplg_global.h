#ifndef CONNECTIVITYPLG_GLOBAL_H
#define CONNECTIVITYPLG_GLOBAL_H

//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include <utils/buildinfo.h>

//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QtCore/qglobal.h>

//=============================================================================================================
// PREPROCESSOR DEFINES
//=============================================================================================================

#if defined(CONNECTIVITYPLG_PLUGIN)
#  define CONNECTIVITYPLGSHARED_EXPORT Q_DECL_EXPORT   /**< Q_DECL_EXPORT must be added to the declarations of symbols used when compiling a shared library. */
#else
#  define CONNECTIVITYPLGSHARED_EXPORT Q_DECL_IMPORT   /**< Q_DECL_IMPORT must be added to the declarations of symbols used when compiling a client that uses the shared library. */
#endif

namespace CONNECTIVITYPLGPLUGIN{

//=============================================================================================================
/**
 * Returns build date and time.
 */
CONNECTIVITYPLGSHARED_EXPORT const char* buildDateTime();

//=============================================================================================================
/**
 * Returns abbreviated build git hash.
 */
CONNECTIVITYPLGSHARED_EXPORT const char* buildHash();

//=============================================================================================================
/**
 * Returns full build git hash.
 */
CONNECTIVITYPLGSHARED_EXPORT const char* buildHashLong();
}

#endif // FILTERING_GLOBAL_H
