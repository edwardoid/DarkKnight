#ifndef FUZZYPRIMITIVES_H
#define FUZZYPRIMITIVES_H

#include "Primitives.h"
#include "PiecePresestanceFuzzySet.h"

namespace FuzzyPrimitives
{
	PRIMITIVES_EXPORT Real realCost(const CE::VirtualTable& table, const CE::PieceEx& piece);
	PRIMITIVES_EXPORT Real realCost(const PiecePrestemceFuzzySet& presestance, const CE::PieceEx& piece);
	PRIMITIVES_EXPORT Real realCost(const CE::VirtualTable& table, const CE::ListOfPieces& pieces);
	PRIMITIVES_EXPORT Real realCost(const PiecePrestemceFuzzySet& presestance, const CE::ListOfPieces& pieces);
	PRIMITIVES_EXPORT Real positionGrade(const CE::VirtualTable& table, bool whites);
	PRIMITIVES_EXPORT Real positionGrade(const PiecePrestemceFuzzySet& presestance, const CE::VirtualTable& table, bool whites);
}

#endif // FUZZYPRIMITIVES_H