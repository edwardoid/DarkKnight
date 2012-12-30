#ifndef CALCULATIONDATA_H
#define CALCULATIONDATA_H
#include "FrameworkGlobal.h"
#include <Plugin.h>
#include <FrameworkUser.h>
#include <AbstractCalculationData.h>
#include <CalculationResultForGame.h>
#include <ConceptCalculationsCache.h>

class FRAMEWORK_EXPORT CalculationData: public CGSQL_NS::AbstractCalculationData, public FrameworkUser
{
public:
	CalculationData(const pgn::Game* game = NULL);
	void addGame(const pgn::Game* game);
	virtual bool calculate(const char* concept, const char* requieredValue) const;
	virtual ~CalculationData();
	inline void clear()  { m_conceptToResult.clear(); };
	inline bool isEmpty() const { return m_conceptToResult.isEmpty(); }
	CalculationResultForGame* result(Plugin::ID id);
	inline ConceptCalculationsCache* cache() { return &m_conceptToResult; }
private:
	mutable ConceptCalculationsCache m_conceptToResult;
};

#endif // CALCULATIONDATA_H
