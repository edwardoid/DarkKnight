#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <PGNGameCollection.h>
#include <CalculationData.h>

class QueryResult
{
public:
	QueryResult();
	~QueryResult();
	CalculationData& data();
	pgn::GameCollection& games();
	inline void clear() { m_data.clear(); m_games.clear(); }
	inline bool isEmpty() const { return m_games.size() < 1; }
private:
	CalculationData m_data;
	pgn::GameCollection m_games;
};

#endif // QUERYRESULT_H

