#ifndef SIMPLE_CALCULATIONS_TEST_H
#define SIMPLE_CALCULATIONS_TEST_H

#include "UnitTest++.h"
#include <limits>
#include <vector>
#include <CEPiece.h>
#include <SimpleCalculations.h>
#include <ScopedPointer.h>

TEST(standartCost_on_singlePiece)
{

	CHECK_EQUAL(std::numeric_limits<short>::max(), Primitives::standartCost(ScopedPointer<CE::Piece>(new CE::Piece(CE::king))));
	CHECK_EQUAL(8,	Primitives::standartCost(ScopedPointer<CE::Piece>(new CE::Piece(CE::queen))));
	CHECK_EQUAL(6,	Primitives::standartCost(ScopedPointer<CE::Piece>(new CE::Piece(CE::rook))));
	CHECK_EQUAL(4,	Primitives::standartCost(ScopedPointer<CE::Piece>(new CE::Piece(CE::bishop))));
	CHECK_EQUAL(4,	Primitives::standartCost(ScopedPointer<CE::Piece>(new CE::Piece(CE::knight))));
	CHECK_EQUAL(1,	Primitives::standartCost(ScopedPointer<CE::Piece>(new CE::Piece(CE::pawn))));
	CHECK_EQUAL(-1,	Primitives::standartCost(ScopedPointer<CE::Piece>(new CE::Piece(CE::unknown))));
}


TEST(standartCost_on_list_of_pieces)
{
	CE::ListOfPieces pieces;
	std::vector<short> goldenCosts;
	pieces.push_back(CE::PieceEx(CE::Piece(CE::pawn), 1, 2));
	goldenCosts.push_back(1);
	pieces.push_back(CE::PieceEx(CE::Piece(CE::pawn), 1, 2));
	goldenCosts.push_back(1);
	pieces.push_back(CE::PieceEx(CE::Piece(CE::knight), 1, 2));
	goldenCosts.push_back(4);
	pieces.push_back(CE::PieceEx(CE::Piece(CE::queen), 1, 2));
	goldenCosts.push_back(8);
	pieces.push_back(CE::PieceEx(CE::Piece(CE::rook), 1, 2));
	goldenCosts.push_back(6);
	pieces.push_back(CE::PieceEx(CE::Piece(CE::rook), 1, 2));
	goldenCosts.push_back(6);
	pieces.push_back(CE::PieceEx(CE::Piece(CE::bishop), 1, 2));
	goldenCosts.push_back(4);
	pieces.push_back(CE::PieceEx(CE::Piece(CE::king), 1, 2));
	goldenCosts.push_back(std::numeric_limits<short>::max());
	std::vector<short> resultCosts = Primitives::standartCost(pieces);
	CHECK_EQUAL(goldenCosts.size(), resultCosts.size());
	CHECK_EQUAL(pieces.size(), resultCosts.size());
	std::vector<short>::const_iterator goldenIt = goldenCosts.cbegin();
	CE::ListOfPieces::const_iterator piecesIt = pieces.cbegin();
	std::vector<short>::const_iterator resIt = resultCosts.cbegin();
	while(	goldenIt != goldenCosts.cend() &&
			piecesIt != pieces.cend() &&
			resIt != resultCosts.cend())
	{
		CHECK_EQUAL(*goldenIt, *resIt);
		CHECK_EQUAL(*goldenIt, Primitives::standartCost(&*piecesIt));
		++goldenIt;
		++piecesIt;
		++resIt;
	}
}

#endif