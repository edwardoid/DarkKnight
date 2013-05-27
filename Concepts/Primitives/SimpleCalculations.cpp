#include "SimpleCalculations.h"
#include <limits>
#include <assert.h>


namespace Primitives {

short standartCost(const CE::Piece* piece )
{
	return standartCost(piece->type());
}

std::vector<short> standartCost( const CE::ListOfPieces& pieces )
{
	std::vector<short> res;
	for (	CE::ListOfPieces::const_iterator it = pieces.begin();
			it != pieces.end();
			++it)
	{
		res.push_back(standartCost(&(*it)));
	}
	return res;
}

short standartCost( const CE::piece_type type)
{
	switch(type)
	{
	case CE::king:
		return std::numeric_limits<short>::max(); // infinite
	case CE::queen:
		return 8;
	case CE::rook:
		return 6;
	case CE::knight:
	case CE::bishop:
		return 4;
	case CE::pawn:
		return 1;
	default:
		return -1;
	}
	return -1;
}

CE::VirtualTable diff( const CE::VirtualTable& first, const CE::VirtualTable& second )
{
	CE::VirtualTable res;
	for(int r = 0; r < 8; ++r)
	{
		for(int c = 0; c < 8; ++c)
		{
			const CE::Piece* f = first.pieceAt(c, r);
			const CE::Piece* s = second.pieceAt(c, r);
			assert(f != NULL && s != NULL);
			if(*f != *s)
			{
				(*res.pieceAt(c, r)) = *s;
			}
		}
	}
	return res;
}

std::list<CE::PairOfPieces> changes( const CE::VirtualTable& prev, const CE::VirtualTable& now )
{
	std::list<std::pair<CE::PieceEx, CE::PieceEx> > res;
	for(int r = 0; r < 8; ++r)
	{
		for(int c = 0; c < 8; ++c)
		{
			const CE::Piece* p = prev.pieceAt(c, r);
			const CE::Piece* n = now.pieceAt(c, r);
			assert(p != NULL && n != NULL);
			if(*p != *n)
			{
				CE::PairOfPieces change;
				change.first = CE::PieceEx(*p, r, c);
				change.second = CE::PieceEx(*n, r, c);
				res.push_back(change);
			}
		}
	}
	return res;
}

}
