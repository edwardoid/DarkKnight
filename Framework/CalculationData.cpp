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

bool CalculationData::calculate( const char* conceptName, const char* requieredValue, ChEngn::piece_color color ) const
{
	Plugin::ID conceptId = 0;
	ConceptPlugin* plg = NULL;
	foreach(ConceptPlugin* nextPlg, framework()->concepts())
	{
		if (0 == nextPlg->name().compare(conceptName, Qt::CaseInsensitive))
		{
			conceptId = nextPlg->id();
			plg = nextPlg;
		}
	}
	if (conceptId == 0 || plg == NULL) return false;

	CalculationResultForGame* result = m_conceptToResult.result(conceptId);

	ConceptPlugin::Color c = color == ChEngn::white ? ConceptPlugin::Whites : ConceptPlugin::Blacks;

	if(NULL == result)
	{
		CalculationResultForGame calcResult = plg->calculate(*game(), c);
		m_conceptToResult.add(conceptId, calcResult);
		result = &calcResult;
	}
	return result->hasValue(requieredValue);
}

void CalculationData::addGame( const pgn::Game* game )
{
	m_game = game;
}

CalculationResultForGame* CalculationData::result( Plugin::ID id )
{
	return m_conceptToResult.result(id);
}
