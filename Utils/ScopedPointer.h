#ifndef SCOPED_POINTER_H
#define SCOPED_POINTER_H

#include "Macro.h"

template<typename T>
class ScopedPointer
{
public:
	ScopedPointer(T* pointer = NULL) { m_data = pointer; }
	SIMPLE_COPY_CONSTRUCTOR(ScopedPointer)
	const ScopedPointer& operator=(const ScopedPointer& other) { return this = other.m_data; }
	const ScopedPointer& operator=(T* const pointer)
	{
		destroy();
		m_data = pointer;
		return *this;
	}

	void destroy() { if(m_data) delete m_data; }

	~ScopedPointer() { destroy(); }

	T* data()				{ return const_cast<T*>(m_data); }
	const T* data()	const	{ return m_data; }

	T* operator->()					{ return data(); }
	const T* operator->()	const	{ return data(); }

	operator T* ()					{ return data(); }
	operator const T* ()	const	{ return data(); }

	operator bool ()		const	{ return m_data != NULL; }

	bool operator == (const ScopedPointer& other) const { return m_data == other->m_data; }
	bool operator != (const ScopedPointer& other) const { return !(*this == other); }

	bool operator == (const T* other) const { return m_data == other; }
	bool operator != (const T* other) const { return !(*this == other); }

	bool operator == (const int other) const { return m_data == other; }
	bool operator != (const int other) const { return !(*this == other); }

	bool isNull() const { return m_data == NULL; }
private:
	T* m_data;
};

#endif // SCOPED_POINTER_H