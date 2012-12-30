#include "FuzzyGoodPawn.h"
#include "GoodPawnLinguisticVariableMembershipFunction.h"
#include <Primitives.h>
#include <CEEngine.h>
#include <LinearCharacteristicFunction.h>
#include <TriangularCharacteristicFunction.h>
#include <Utils.h>

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
	return res;
}


Q_EXPORT_PLUGIN2(FuzyGoodPawn, FuzyGoodPawn);