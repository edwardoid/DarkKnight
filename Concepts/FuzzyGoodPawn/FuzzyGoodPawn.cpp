#include "FuzzyGoodPawn.h"
#include "GoodPawnLinguisticVariableMembershipFunction.h"
#include <Primitives.h>
#include <CEEngine.h>
#include <LinearCharacteristicFunction.h>
#include <TriangularCharacteristicFunction.h>
#include <Utils.h>
#include <CommonPrimitives.h>

using namespace ChEngn;

FuzyGoodPawn::FuzyGoodPawn()
	: m_lingVariable(new GoodPawnLinguisticVariableMembershipFunction())
{
	m_lingVariable.addValue(LinguisticValue("weak",		new LinearCharacteristicFunction(Point(0, 1), Point(1, 0))));
	m_lingVariable.addValue(LinguisticValue("average",	new TriangularCharacteristicFunction(0, Point(0.5, 1), 1)));
	m_lingVariable.addValue(LinguisticValue("strong",	new LinearCharacteristicFunction(Point(0, 0), Point(1, 1))));
}

FuzyGoodPawn::~FuzyGoodPawn()
{

}

QString FuzyGoodPawn::name() const
{
	return "FuzyGoodPawn";
}

QString FuzyGoodPawn::author() const
{
	return "Edward Sarkisyan";
}

QString FuzyGoodPawn::version() const
{
	return "1.0";
}

const ListofLinguisticValues& FuzyGoodPawn::availableValues() const
{
	return m_lingVariable.values();
}

CalculationResultForGame FuzyGoodPawn::calculate( const pgn::Game& game, const Color color ) const
{
	CalculationResultForGame res;
	Engine engine(game);
	while (engine.makeNextHalfMove())
	{
		VirtualTable table = engine.getVirtualTable();
		res.addTable(calculateForTable(table, color));
	}
	return res;
}

CalculationResultForTable FuzyGoodPawn::calculateForTable( const VirtualTable& table, const Color color ) const
{
	const bool whites = (color == ConceptPlugin::Whites);
	const ListOfPieces pieces = Primitives::pieces(&table, ChEngn::pawn, &whites);
	ListOfPieces::const_iterator itPiece = pieces.cbegin();
	CalculationResultForTable::Color resColor = whites ? CalculationResultForTable::Whites : CalculationResultForTable::Blacks;
	CalculationResultForTable tblResult;
	for(; itPiece != pieces.cend(); ++itPiece)
	{
		TableAndPos arg;
		arg.table = &table;
		arg.column = itPiece->column();
		arg.row = itPiece->row();
		const ResultPair res = m_lingVariable.value(arg);
		CalculationResultForSquare sqResult;
		sqResult.setTextValue(QString::fromStdString(res.text));
		sqResult.setInternalValue(res.value);
		tblResult.setSquareValue(resColor, arg.column, arg.row, sqResult);
	}
	return tblResult;
}


Q_EXPORT_PLUGIN2(FuzyGoodPawn, FuzyGoodPawn);