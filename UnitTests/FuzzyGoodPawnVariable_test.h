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
	lingVariable.addValue(LinguisticValue("weak",		&weakValueCharFunc));
	lingVariable.addValue(LinguisticValue("average",	&averageValueCharFunc));
	lingVariable.addValue(LinguisticValue("strong",		&strongValueCharFunc));
	CE::VirtualTable table;
	TableAndPos arg;
	arg.table = &table;
	arg.column = 2;
	arg.row = 1;
	ResultPair res = lingVariable.value(arg);
	CHECK_EQUAL("weak", res.text);
	CHECK_CLOSE(1., res.value, 0.2);
	table.cleanTable();
	CE::Piece *pawn = table.pieceAt(3, 4);
	pawn->setWhite();
	CE::Piece *kingW = table.pieceAt(4, 4);
	kingW->setWhite();
	CE::Piece *kingB = table.pieceAt(5, 6);
	kingB->setBlack();
}

TEST(Fuzzy_Good_Pawn_Linguisitc_Variable_on_semi_empty_table)
{
	LinguisticVariable<TableAndPos> lingVariable(new GoodPawnLinguisticVariableMembershipFunction());
	LinearCharacteristicFunction weakValueCharFunc(Point(0, 1), Point(1, 0));
	TriangularCharacteristicFunction averageValueCharFunc(0, Point(0.5, 1), 1);
	LinearCharacteristicFunction strongValueCharFunc(Point(0, 0), Point(1, 1));
	lingVariable.addValue(LinguisticValue("weak",		&weakValueCharFunc));
	lingVariable.addValue(LinguisticValue("average",	&averageValueCharFunc));
	lingVariable.addValue(LinguisticValue("strong",		&strongValueCharFunc));
	CE::VirtualTable table;
	TableAndPos arg;
	arg.table = &table;
	arg.column = 3;
	arg.row = 4;
	table.cleanTable();
	CE::Piece *pawn = table.pieceAt(arg.column, arg.row);
	pawn->setWhite();
	pawn->setType(CE::pawn);
	CE::Piece *kingW = table.pieceAt(4, 4);
	kingW->setWhite();
	kingW->setType(CE::king);
	CE::Piece *kingB = table.pieceAt(5, 6);
	kingB->setBlack();
	kingB->setType(CE::king);
	ResultPair res = lingVariable.value(arg);
	// Pawn should be strong, because it is the last pawn on the board.
	CHECK_EQUAL("strong", res.text);
	CHECK(res.value > .5);
	CHECK(res.value < .9);
}
#endif // UT_FGPV_H