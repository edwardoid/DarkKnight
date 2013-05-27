#ifndef FUZZYGOODPAWN_H
#define FUZZYGOODPAWN_H

#include <ConceptPlugin.h>
#include <CalculationResultForTable.h>
#include <CalculationResultForSquare.h>
#include <CETable.h>
#include <PGNSquare.h>
#include <LinguisticVariable.h>
#include <QtCore/QtPlugin>
#include <CommonPrimitives.h>

class FuzyGoodPawn: public ConceptPlugin
{
	Q_OBJECT
	Q_INTERFACES(Plugin)
public:
	FuzyGoodPawn();
	virtual ~FuzyGoodPawn();
	virtual QString name() const;
	virtual QString version() const;
	virtual QString author() const;
	virtual const ListofLinguisticValues& availableValues() const;
	virtual CalculationResultForGame calculate(const pgn::Game& game, const Color color) const;
private:
	CalculationResultForTable	calculateForTable(const CE::VirtualTable& table, const Color color) const;
private:
	LinguisticVariable<Primitives::TableAndPos> m_lingVariable;
};

#endif // FUZZYGOODPAWN_H
