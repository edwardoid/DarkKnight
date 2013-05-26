#include "CheckmatePerception.h"
#include <PolynomialCharacteristicFunction.h>
#include <PowerCharacteristicFunction.h>

CheckmatePerception::CheckmatePerception()
{
	Vector notCoefs(2, 0.);
	notCoefs[0] = 1.;
	notCoefs[1] = -1.;
	m_availableValues.push_back(LinguisticValue("not", new PolynomialCharacteristicFunction(notCoefs)));
	m_availableValues.push_back(LinguisticValue("middle", new PowerCharacteristicFunction(0.5)));
	m_availableValues.push_back(LinguisticValue("very", new PowerCharacteristicFunction(2)));
}

CheckmatePerception::~CheckmatePerception()
{

}

QString CheckmatePerception::name() const
{
	return "CheckmatePerception";
}

QString CheckmatePerception::version() const
{
	return "0.1";
}

QString CheckmatePerception::author() const
{
	return "Edward Sarkisyan";
}

const ListofLinguisticValues& CheckmatePerception::availableValues() const
{
	return m_availableValues;
}

CalculationResultForGame CheckmatePerception::calculate( const pgn::Game& game, const Color color ) const
{
	CalculationResultForGame res;

	return res;
}

Q_EXPORT_PLUGIN2(beautifulMate, CheckmatePerception);
