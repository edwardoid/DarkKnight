#ifndef UT_PRIMITIVES_H
#define UT_PRIMITIVES_H

#include <UnitTest++.h>
#include <CETable.h>
#include <CEPiece.h>
#include <CEEngine.h>
#include <CommonPrimitives.h>

TEST(piecesAttacs_on_e4)
{
	ChEngn::Table tbl; // Initial state
	ChEngn::ListOfPieces res = Primitives::piecesAttacs(tbl, 4, 3, NULL);
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
	ChEngn::Table tbl; // Initial state
	ChEngn::ListOfPieces res = Primitives::piecesAttacs(tbl, 2, 2, NULL);
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
	ChEngn::VirtualTable tbl;
	CHECK_EQUAL(32, Primitives::piecesCount(&tbl, ChEngn::unknown, NULL));
	bool whites = true;
	CHECK_EQUAL(8, Primitives::piecesCount(&tbl, ChEngn::pawn, &whites));
	whites = false;
	CHECK_EQUAL(2, Primitives::piecesCount(&tbl, ChEngn::bishop, &whites));
	CHECK_EQUAL(1, Primitives::piecesCount(&tbl, ChEngn::queen, &whites));
}

#endif // UT_PRIMITIVES_H
