#ifndef MACRO_H
#define MACRO_H

#define QTT(NAME) QQ(NAME)
#define QQ(NAME) #NAME
#define SIMPLE_COPY_CONSTRUCTOR(ClassName) ClassName(const ClassName& other) { *this = other; }

#define MAX(A, B) ((A) > (B)	?	(A)	: (B))
#define MIN(A, B) ((A) < (B)	?	(A)	: (B))
#define ABS(A)	  ((A) > 0		?	(A)	: -(A))

template<typename T>
static inline void swap(T a, T b) { T c = b; b = a; a = c; }
#endif