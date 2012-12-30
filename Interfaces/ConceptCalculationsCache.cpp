#include "ConceptCalculationsCache.h"


ConceptCalculationsCache::ConceptCalculationsCache(void)
{
}


ConceptCalculationsCache::~ConceptCalculationsCache(void)
{
}


bool ConceptCalculationsCache::add(const ID conceptId, CalculationResultForGame result)
{
	if(!m_cache.contains(conceptId))
	{
		m_cache.insert( conceptId, result);
		return true;
	}
	
	return false;
}

CalculationResultForGame* ConceptCalculationsCache::result(const ID conceptId)
{
	ConceptCalculations::iterator it = m_cache.find(conceptId);
	if (it != m_cache.end())
	{
		return &(*it);
	}
	return NULL;
}
