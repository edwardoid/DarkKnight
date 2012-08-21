#include "ConceptCalculationsCache.h"


ConceptCalculationsCache::ConceptCalculationsCache(void)
{
}


ConceptCalculationsCache::~ConceptCalculationsCache(void)
{
}


bool ConceptCalculationsCache::add(const ID conceptId, CalculationResultForGame result, const ID gameId)
{
	GameCalculations::iterator gameIt = m_cache.find(gameId);
	if(gameIt == m_cache.end())
	{
		m_cache.insert(gameId, ConceptCalculations());
		gameIt = m_cache.find(gameId);
	}
	ConceptCalculations::iterator conceptCalculationsIt = (*gameIt).find(conceptId);
	if(conceptCalculationsIt == (*gameIt).end())
	{
		gameIt->insert(conceptId, result);
		return true;
	}
	return false;
}

CalculationResultForGame& ConceptCalculationsCache::result(const ID conceptId, const ID gameId)
{
	return m_cache[gameId][conceptId];
}
