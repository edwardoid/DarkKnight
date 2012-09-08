#include "CalculationData.h"
#include "Framework.h"
#include <CalculationResultForGame.h>
#include <ConceptPlugin.h>

CalculationData::CalculationData(const pgn::Game* game)
	: AbstractCalculationData(game)
{
}


CalculationData::~CalculationData()
{
}

bool CalculationData::calculate( const char* conceptName, const char* requieredValue ) const
{
	qint32 conceptId = 0;
	foreach(ConceptPlugin* plg, framework()->concepts())
	{
		if (0 == plg->name().compare(conceptName, Qt::CaseInsensitive))
		{
			conceptId = plg->id();
		}
	}
	if (conceptId == 0) return false;
	if(m_conceptToResult.contains(conceptId))
	{
		const CalculationResultForGame& result = m_conceptToResult[conceptId];
		return result.textValue().compare(requieredValue, Qt::CaseInsensitive);
	}
	const ConceptPlugin* concept = framework()->conceptById(conceptId);
	m_conceptToResult.insert(conceptId, concept->calculate(*game(), ConceptPlugin::Whites));
	return true;
}

void CalculationData::addGame( const pgn::Game* game )
{
	m_game = game;
}
