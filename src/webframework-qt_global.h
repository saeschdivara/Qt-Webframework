#ifndef WEBFRAMEWORKQT_GLOBAL_H
#define WEBFRAMEWORKQT_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtCore/QObject>

#ifdef QT_WEBFRAMEWORK_DEBUG
    #include <QtCore/QDebug>
#endif

#if defined(WEBFRAMEWORKQT_LIBRARY)
#  define WEBFRAMEWORKQTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define WEBFRAMEWORKQTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // WEBFRAMEWORKQT_GLOBAL_H
