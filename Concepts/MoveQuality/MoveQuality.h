#ifndef MOVEQUALITY_H
#define MOVEQUALITY_H

#include <ConceptPlugin.h>
#include <CalculationResultForTable.h>
#include <CalculationResultForSquare.h>
#include <CETable.h>
#include <PGNSquare.h>
#include <QPair>
#include <QtCore/QtPlugin>
#include <LinguisticVariable.h>
#include <CEEngine.h>

class MoveQuality: public ConceptPlugin
{
	Q_OBJECT
	Q_INTERFACES(Plugin)
public:
	MoveQuality();
	virtual ~MoveQuality();
	virtual QString name() const;
	virtual QString version() const;
	virtual QString author() const;
	virtual const ListofLinguisticValues& availableValues() const;
	virtual CalculationResultForGame calculate(const pgn::Game& game, const Color color) const;
private:
	CalculationResultForTable calculateForTables(const CE::PairOfTables, const Color color) const;
	Real MoveQuality::positionGrade( const CE::VirtualTable& table, const Color color ) const;
private:
	LinguisticVariable<pgn::Ply*>::MembershipFunctionPtr  m_mbF;
	LinguisticVariable<pgn::Ply*> m_lingValue;
	CE::Engine m_engine;
};

#endif // MOVEQUALITY_H
