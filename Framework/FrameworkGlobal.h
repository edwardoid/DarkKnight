#ifndef FRAMEWORKGLOBALS_H
#define FRAMEWORKGLOBALS_H

#ifdef _MSC_VER
#define FRAMEWORK_EXPORT __declspec(dllexport)
#else
#define FRAMEWORK_EXPORT
#endif 

#endif // FRAMEWORKGLOBALS_H