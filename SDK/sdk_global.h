#ifndef SDK_GLOBAL_H
#define SDK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SDK_LIBRARY)
#  define SDKSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SDKSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SDK_GLOBAL_H
