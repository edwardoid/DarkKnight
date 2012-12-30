#include "SimpleCalculations.h"
#include <limits>


namespace Primitives {

short standartCost(const ChEngn::Piece* piece )
{
	switch(piece->type())
	{
	case ChEngn::king:
		return std::numeric_limits<short>::max(); // infinite
	case ChEngn::queen:
		return 8;
	case ChEngn::rook:
		return 6;
	case ChEngn::knight:
	case ChEngn::bishop:
		return 4;
	case ChEngn::pawn:
		return 1;
	default:
		return -1;
	}
	return -1;
}

std::vector<short> standartCost( const ChEngn::ListOfPieces& pieces )
{
	std::vector<short> res;
	for (	ChEngn::ListOfPieces::const_iterator it = pieces.begin();
			it != pieces.end();
			++it)
	{
		res.push_back(standartCost(&(*it)));
	}
	return res;
}

}
