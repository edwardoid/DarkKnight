#ifndef INTERFACESGLOBALS_H 
#define INTERFACESGLOBALS_H 

#include <QtCore/qglobal.h>

#ifdef INTERFACES_LIB
# define EXPORT_INTERFACES Q_DECL_EXPORT
#else
# define EXPORT_INTERFACES Q_DECL_IMPORT
#endif

#endif // INTERFACESGLOBALS_H 