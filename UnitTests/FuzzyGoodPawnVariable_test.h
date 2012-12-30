#ifndef UT_FGPV_H
#define UT_FGPV_H
#include <UnitTest++.h>
#include <CETable.h>
#include <GoodPawnLinguisticVariableMembershipFunction.h>
#include <LinguisticVariable.h>
#include <LinearCharacteristicFunction.h>
#include <TriangularCharacteristicFunction.h>

TEST(Fuzzy_Good_Pawn_Linguisitc_Variable_on_initial_table)
{
	LinguisticVariable<TableAndPos> lingVariable(new GoodPawnLinguisticVariableMembershipFunction());
	LinearCharacteristicFunction weakValueCharFunc(Point(0, 1), Point(1, 0));
	TriangularCharacteristicFunction averageValueCharFunc(0, Point(0.5, 1), 1);
	LinearCharacteristicFunction strongValueCharFunc(Point(0, 0), Point(1, 1));
	lingVariable.addValue(LinguisticValue("weak",		&weakValueCharFunc, false));
	lingVariable.addValue(LinguisticValue("average",	&averageValueCharFunc, false));
	lingVariable.addValue(LinguisticValue("strong",		&strongValueCharFunc, false));
	ChEngn::VirtualTable table;
	TableAndPos arg;
	arg.table = &table;
	arg.column = 2;
	arg.row = 1;
	ResultPair res = lingVariable.value(arg);
	CHECK_EQUAL("weak", res.text);
	CHECK_CLOSE(1., res.value, 0.2);
	table.cleanTable();
	ChEngn::Piece *pawn = table.pieceAt(3, 4);
	pawn->setWhite();
	ChEngn::Piece *kingW = table.pieceAt(4, 4);
	kingW->setWhite();
	ChEngn::Piece *kingB = table.pieceAt(5, 6);
	kingB->setBlack();
}

TEST(Fuzzy_Good_Pawn_Linguisitc_Variable_on_semi_empty_table)
{
	LinguisticVariable<TableAndPos> lingVariable(new GoodPawnLinguisticVariableMembershipFunction());
	LinearCharacteristicFunction weakValueCharFunc(Point(0, 1), Point(1, 0));
	TriangularCharacteristicFunction averageValueCharFunc(0, Point(0.5, 1), 1);
	LinearCharacteristicFunction strongValueCharFunc(Point(0, 0), Point(1, 1));
	lingVariable.addValue(LinguisticValue("weak",		&weakValueCharFunc, false));
	lingVariable.addValue(LinguisticValue("average",	&averageValueCharFunc, false));
	lingVariable.addValue(LinguisticValue("strong",		&strongValueCharFunc, false));
	ChEngn::VirtualTable table;
	TableAndPos arg;
	arg.table = &table;
	arg.column = 3;
	arg.row = 4;
	table.cleanTable();
	ChEngn::Piece *pawn = table.pieceAt(arg.column, arg.row);
	pawn->setWhite();
	pawn->setType(ChEngn::pawn);
	ChEngn::Piece *kingW = table.pieceAt(4, 4);
	kingW->setWhite();
	kingW->setType(ChEngn::king);
	ChEngn::Piece *kingB = table.pieceAt(5, 6);
	kingB->setBlack();
	kingB->setType(ChEngn::king);
	ResultPair res = lingVariable.value(arg);
	// Pawn should be strong, because it is the last pawn on the board.
	CHECK_EQUAL("strong", res.text);
	CHECK(res.value > .5);
	CHECK(res.value < .9);
}
#endif // UT_FGPV_H