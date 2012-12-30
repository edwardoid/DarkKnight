#ifndef SIMPLE_CALCULATIONS_H
#define SIMPLE_CALCULATIONS_H

#include "Primitives.h"
#include <CEPiece.h>
#include <vector>

namespace Primitives
{

PRIMITIVES_EXPORT short standartCost(const ChEngn::Piece* piece);
PRIMITIVES_EXPORT std::vector<short> standartCost(const ChEngn::ListOfPieces& pieces);

}

#endif // SIMPLE_CALCULATIONS_H