#ifndef MOVEQUALITYMEMBERSHIPFUNCTION_H
#define MOVEQUALITYMEMBERSHIPFUNCTION_H

#include <MembershipFunction.h>
#include <PGNPly.h>
#include <CEEngine.h>
#include <FuzzyPrimitives.h>
#include <SimpleCalculations.h>

class MoveQualityMembershipFunction
	: public MembershipFunction<pgn::Ply*>
{
public:
	MoveQualityMembershipFunction() : m_engine(NULL), m_white(false) {}
	MoveQualityMembershipFunction(const MoveQualityMembershipFunction& src) { *this = src; }
	MoveQualityMembershipFunction& operator = (const MoveQualityMembershipFunction& src)
	{
		this->m_engine = src.m_engine;
	}

	inline void setEngine(CE::Engine* engine) const { m_engine = engine; }
	inline void setColor(bool whites) const { m_white = whites; }

	virtual Real operator()() const;
private:
	mutable CE::Engine* m_engine;
	mutable bool m_white;
};

Real MoveQualityMembershipFunction::operator()() const
{
	pgn::Ply* a = arg();
	Real res = 0;
	CE::VirtualTable prev = m_engine->getVirtualTable();
	Real p = FuzzyPrimitives::positionGrade(prev, m_white);
	if(!m_engine->makePly(a, m_white))
		return DBL_MIN;
	CE::VirtualTable now = m_engine->getVirtualTable();
	Real n = FuzzyPrimitives::positionGrade(now, m_white);
	return (n - p) / Real(Primitives::standartCost(CE::queen));
}



#endif // MOVEQUALITYMEMBERSHIPFUNCTION_H