#ifndef CLASSICGOODPAWN_H
#define CLASSICGOODPAWN_H

#include <ConceptPlugin.h>
#include <CalculationResultForTable.h>
#include <CalculationResultForSquare.h>
#include <CETable.h>
#include <PGNSquare.h>
#include <QtCore/QtPlugin>

class ClassicGoodPawn: public ConceptPlugin
{
	Q_OBJECT
	Q_INTERFACES(Plugin)
public:
	ClassicGoodPawn();
	virtual ~ClassicGoodPawn();
	virtual QString name() const;
	virtual QString version() const;
	virtual QString author() const;
	virtual const ListofLinguisticValues& availableValues() const;
	virtual CalculationResultForGame calculate(const pgn::Game& game, const Color color) const;
private:
	CalculationResultForTable calculateForTable(const CE::VirtualTable& table, const Color color) const;
	CalculationResultForSquare calculateForPawn(const pgn::Square& square, const CE::VirtualTable& table) const;
private:
	ListofLinguisticValues m_availableValues;
};

#endif // CLASSICGOODPAWN_H
