#ifndef UTILS_H
#define UTILS_H

#define DEBUG

#include "Macro.h"

#ifdef DEBUG

#ifdef ASSERT // Force define GUI-assertions
#undef ASSERT
#endif

#include "AssertDialog.h"
#define ASSERT(EXP)\
	if(!(EXP)) \
	{ \
	AssertDialog dlg(QQ(EXP), __LINE__, __FILE__ );\
		dlg.exec(); \
	}
#else
#define ASSERT(EXP) {}
#endif

#endif // UTILS_H
