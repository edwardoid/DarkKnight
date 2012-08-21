#ifndef CONCEPTCALCULATIONSCACHE_H
#define CONCEPTCALCULATIONSCACHE_H

#include "InterfacesGlobal.h"
#include "CalculationResultForGame.h"
#include <QMap>

class Concept;

class EXPORT_INTERFACES ConceptCalculationsCache
{
public:
	typedef unsigned int ID;
	ConceptCalculationsCache();
	~ConceptCalculationsCache();
	bool add(const ID conceptId, CalculationResultForGame result, const ID gameId);
	CalculationResultForGame& result(const ID conceptId, const ID gameId);
private:
	typedef QMap<ID, CalculationResultForGame> ConceptCalculations;
	typedef QMap<ID, ConceptCalculations> GameCalculations;
	GameCalculations m_cache;
};

#endif // CONCEPTCALCULATIONSCACHE_H