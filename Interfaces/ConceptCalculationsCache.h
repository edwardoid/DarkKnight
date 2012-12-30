#ifndef CONCEPTCALCULATIONSCACHE_H
#define CONCEPTCALCULATIONSCACHE_H

#include "InterfacesGlobal.h"
#include "CalculationResultForGame.h"
#include <QMap>

class ConceptPlugin;

class EXPORT_INTERFACES ConceptCalculationsCache
{
public:
	typedef unsigned int ID;
	ConceptCalculationsCache();
	~ConceptCalculationsCache();
	bool add(const ID conceptId, CalculationResultForGame result);
	CalculationResultForGame* result(const ID conceptId);
	inline void clear()  { m_cache.clear(); };
	inline bool isEmpty() const { return m_cache.isEmpty(); }
	inline QList<ID> cachedConcepts() const { return m_cache.uniqueKeys(); }
private:
	typedef QMap<ID, CalculationResultForGame> ConceptCalculations;
	ConceptCalculations m_cache;
};

#endif // CONCEPTCALCULATIONSCACHE_H