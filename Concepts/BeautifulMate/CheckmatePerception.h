#ifndef CHECKMATE_PERCEPTION_H
#define CHECKMATE_PERCEPTION_H

#include <ConceptPlugin.h>
#include <CalculationResultForTable.h>
#include <CalculationResultForSquare.h>
#include <CETable.h>
#include <PGNSquare.h>
#include <QtCore/QtPlugin>

class CheckmatePerception: public ConceptPlugin
{
	Q_OBJECT
	Q_INTERFACES(Plugin)
public:
	CheckmatePerception();
	virtual ~CheckmatePerception();
	virtual QString name() const;
	virtual QString version() const;
	virtual QString author() const;
	virtual const ListofLinguisticValues& availableValues() const;
	virtual CalculationResultForGame calculate(const pgn::Game& game, const Color color) const;
private:
	ListofLinguisticValues m_availableValues;
};

#endif // CHECKMATE_PERCEPTION_H
