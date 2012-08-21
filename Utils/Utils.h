#ifndef UTILS_H
#define UTILS_H

#define DEBUG

#define QQ(NAME) #NAME


#ifdef DEBUG
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
