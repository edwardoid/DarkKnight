#ifndef SIMPLE_CALCULATIONS_H
#define SIMPLE_CALCULATIONS_H

#include "Primitives.h"
#include <CEPiece.h>
#include <CETable.h>
#include <vector>
#include <list>
#include <map>

namespace Primitives
{

PRIMITIVES_EXPORT short standartCost(const CE::piece_type type);
PRIMITIVES_EXPORT short standartCost(const CE::Piece* piece);
PRIMITIVES_EXPORT std::vector<short> standartCost(const CE::ListOfPieces& pieces);
PRIMITIVES_EXPORT CE::VirtualTable diff(const CE::VirtualTable& first, const CE::VirtualTable& second);
PRIMITIVES_EXPORT std::list<CE::PairOfPieces> changes(const CE::VirtualTable& first, const CE::VirtualTable& second);
}

#endif // SIMPLE_CALCULATIONS_H