#ifndef UT_PRIMITIVES_H
#define UT_PRIMITIVES_H

#include <UnitTest++.h>
#include <CETable.h>
#include <CEPiece.h>
#include <CEEngine.h>
#include <CommonPrimitives.h>

TEST(piecesAttacs_on_e4)
{
	CE::Table tbl; // Initial state
	CE::ListOfPieces res = Primitives::piecesAttacs(tbl, 4, 3, NULL);
	bool whites = true;
	CHECK_EQUAL(0, res.size());
	res = Primitives::piecesAttacs(tbl, 4, 3, &whites);
	CHECK_EQUAL(0, res.size());
	whites = false;
	res = Primitives::piecesAttacs(tbl, 4, 3, &whites);
	CHECK_EQUAL(0, res.size());
};

TEST(piecesAttacs_on_c3)
{
	CE::Table tbl; // Initial state
	CE::ListOfPieces res = Primitives::piecesAttacs(tbl, 2, 2, NULL);
	bool whites = true;
	CHECK_EQUAL(3, res.size());
	res = Primitives::piecesAttacs(tbl, 2, 2, &whites);
	CHECK_EQUAL(3, res.size());
	whites = false;
	res = Primitives::piecesAttacs(tbl, 2, 2, &whites);
	CHECK_EQUAL(0, res.size());
};


TEST(piecesCount_on_initial_table)
{
	CE::VirtualTable tbl;
	CHECK_EQUAL(32, Primitives::piecesCount(&tbl, CE::unknown, NULL));
	bool whites = true;
	CHECK_EQUAL(8, Primitives::piecesCount(&tbl, CE::pawn, &whites));
	whites = false;
	CHECK_EQUAL(2, Primitives::piecesCount(&tbl, CE::bishop, &whites));
	CHECK_EQUAL(1, Primitives::piecesCount(&tbl, CE::queen, &whites));
}

#endif // UT_PRIMITIVES_H
