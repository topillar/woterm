#ifndef WOIPC_GLOBAL_H
#define WOIPC_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(Q_OS_WIN)

#if defined(WOIPC_LIBRARY)
#  define WOIPCSHARED_EXPORT __declspec(dllexport)
#else
#  define WOIPCSHARED_EXPORT __declspec(dllimport)
#endif

#else

#if defined(WOIPC_LIBRARY)
#  define WOIPCSHARED_EXPORT Q_DECL_EXPORT
#else
#  define WOIPCSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif

//#if defined(WOIPC_LIBRARY2)
//#  define WOIPCSHARED_EXPORT Q_DECL_EXPORT
//#else
//#  define WOIPCSHARED_EXPORT Q_DECL_IMPORT
//#endif
#endif // WOIPC_GLOBAL_H
