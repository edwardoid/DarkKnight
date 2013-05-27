#ifndef PIECEPRESTENCEFUZZY_SET_H
#define PIECEPRESTENCEFUZZY_SET_H

#include "Primitives.h"
#include "CommonPrimitives.h"
#include <MembershipFunction.h>
#include <FuzzySet.h>

namespace FuzzyPrimitives
{

class PiecePrestemceMembershipFunction: public MembershipFunction<CE::PieceEx>
{
public:
	inline PiecePrestemceMembershipFunction(const CE::VirtualTable& table)
		: m_table(table)
	{}
	virtual ~PiecePrestemceMembershipFunction(){};
	Real operator() () const;
private:
	const CE::VirtualTable& m_table;
};

class PRIMITIVES_EXPORT PiecePrestemceFuzzySet: public FuzzySet<CE::PieceEx>
{
public:
	PiecePrestemceFuzzySet(const CE::VirtualTable& table);
	PiecePrestemceFuzzySet(const PiecePrestemceFuzzySet& src) { *this = src; }
	PiecePrestemceFuzzySet& operator = (const PiecePrestemceFuzzySet& src);
private:
	CE::VirtualTable m_table;
};

}
#endif // PIECEPRESTENCEFUZZY_SET_H