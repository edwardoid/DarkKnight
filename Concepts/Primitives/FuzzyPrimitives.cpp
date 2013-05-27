#include "FuzzyPrimitives.h"
#include "SimpleCalculations.h"

namespace FuzzyPrimitives
{
	Real realCost(const CE::VirtualTable& table, const CE::PieceEx& piece)
	{
		PiecePrestemceFuzzySet persestance(table);
		return realCost(persestance, piece);
	}
	
	Real realCost(const PiecePrestemceFuzzySet& presestance, const CE::PieceEx& piece)
	{
		const Real piecePersistent = presestance.fuzzyContains(piece);
		if(piecePersistent == DBL_MIN)
			return DBL_MIN;
		const Real standartCost(Primitives::standartCost(&piece));
		if(standartCost < 0)
			return DBL_MIN;
		return piecePersistent * standartCost;
	}

	Real realCost( const CE::VirtualTable& table, const CE::ListOfPieces& pieces )
	{
		PiecePrestemceFuzzySet persestance(table);
		return realCost(persestance, pieces);
	}

	Real realCost( const PiecePrestemceFuzzySet& persestance, const CE::ListOfPieces& pieces )
	{
		Real cost = 0;
		CE::ListOfPieces::const_iterator piece = pieces.cbegin();
		for(; piece != pieces.cend(); ++piece)
		{
			const Real pieceCost = realCost(persestance, *piece);
			if(pieceCost != DBL_MIN)
			{
				cost += pieceCost;
			}
		}
		if (cost < DBL_EPSILON)
		{
			return DBL_MIN;
		}
		return cost;
	}

	Real positionGrade( const CE::VirtualTable& table, bool whites )
	{
		PiecePrestemceFuzzySet persestance(table);
		return positionGrade(persestance, table, whites);
	}

	Real positionGrade( const PiecePrestemceFuzzySet& presestance, const CE::VirtualTable& table, bool whites )
	{
		const CE::ListOfPieces myPieces = Primitives::pieces(&table, CE::unknown, &whites);
		whites = !whites;
		const CE::ListOfPieces enemyPieces = Primitives::pieces(&table, CE::unknown, &whites);
		const Real myCost = FuzzyPrimitives::realCost(presestance, myPieces);
		const Real enemyCost = FuzzyPrimitives::realCost(presestance, enemyPieces);
		if(enemyCost == DBL_MIN)
			return myCost;
		if(myCost == DBL_MIN)
			return -enemyCost;
		return myCost - enemyCost;
	}

}