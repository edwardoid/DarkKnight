#include "QueryResult.h"


QueryResult::QueryResult(void)
{
}


QueryResult::~QueryResult(void)
{
}

CalculationData& QueryResult::data()
{
	return m_data;
}

pgn::GameCollection& QueryResult::games()
{
	return m_games;
}
