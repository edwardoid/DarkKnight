#include "MoveQuality.h"
#include <CEEngine.h>
#include <LinearCharacteristicFunction.h>
#include <Utils.h>
#include <CommonPrimitives.h>
#include <SimpleCalculations.h>
#include <CEPiece.h>
#include "MoveQualityMembershipFunction.h"

MoveQuality::MoveQuality()
	: m_mbF(new MoveQualityMembershipFunction())
{
	m_lingValue = LinguisticVariable<pgn::Ply*>(m_mbF);
	m_lingValue.addValue(LinguisticValue("expected", new LinearCharacteristicFunction(Point(0, 1), Point(1000, 0))));
	m_lingValue.addValue(LinguisticValue("unexpected", new LinearCharacteristicFunction(Point(0, 0), Point(1000, 1))));
}

MoveQuality::~MoveQuality()
{

}

QString MoveQuality::name() const
{
	return "MoveQuality";
}

QString MoveQuality::author() const
{
	return "Edward Sarkisyan";
}

QString MoveQuality::version() const
{
	return "1.0";
}

const ListofLinguisticValues& MoveQuality::availableValues() const
{
	return m_lingValue.values();
}

CalculationResultForGame MoveQuality::calculate( const pgn::Game& game, const Color color ) const
{
	CalculationResultForGame res;
	CE::Engine engine;
	const MoveQualityMembershipFunction* f = dynamic_cast<const MoveQualityMembershipFunction*> (m_mbF.get());
	if(f == NULL)
		return res;
	bool whites = color == ConceptPlugin::Whites;
	f->setColor(whites);
	f->setEngine(&engine);

	pgn::MoveList moves = game.moves();

	pgn::MoveList::iterator move = moves.begin();
	engine.makeMove(pgn::Move(*move));
	++move;
	for(;move != moves.end(); ++move)
	{
		pgn::Move m = *move;
		std::list<CE::PairOfPieces> changes;
		ResultPair result;
		if(whites)
		{
			const CE::VirtualTable prev = engine.getVirtualTable();
			result = m_lingValue.value(m.white());
			const CE::VirtualTable now = engine.getVirtualTable();
			engine.makePly(m.black(), false);
			changes = Primitives::changes(prev, now);
		}
		else
		{
			engine.makePly(m.white(), true);
			const CE::VirtualTable prev = engine.getVirtualTable();
			result = m_lingValue.value(m.black());
			const CE::VirtualTable now = engine.getVirtualTable();
			changes = Primitives::changes(prev, now);
		}

		CalculationResultForTable whitesTable, blacksTable;
		std::list<CE::PairOfPieces>::const_iterator itChange = changes.begin();
		CalculationResultForTable::Color sqColor = whites ? CalculationResultForTable::Whites : CalculationResultForTable::Blacks;
		for(; itChange != changes.cend(); ++itChange)
		{
			if(whites)
			{
				if(!itChange->second.isUnknown() && itChange->second.isWhite())
				{
					CalculationResultForSquare sqVal;
					sqVal.setTextValue(QString::fromStdString(result.text));
					sqVal.setInternalValue(result.value);
					whitesTable.setSquareValue(sqColor, itChange->second.column(), itChange->second.row(), sqVal);
				}
			}
			else
			{
				if(!itChange->second.isUnknown() && itChange->second.isBlack())
				{
					CalculationResultForSquare sqVal;
					sqVal.setTextValue(QString::fromStdString(result.text));
					sqVal.setInternalValue(result.value);
					whitesTable.setSquareValue(sqColor, itChange->second.column(), itChange->second.row(), sqVal);
				}
			}
		}
		res.addTable(whitesTable);
		res.addTable(blacksTable);
	}

	f->setEngine(NULL);
	return res;
}

Real MoveQuality::positionGrade( const CE::VirtualTable& table, const Color color ) const
{
	const FuzzyPrimitives::PiecePrestemceFuzzySet persestence(table);
	bool whites = (color == ConceptPlugin::Whites ? true : false);
	const CE::ListOfPieces myPieces = Primitives::pieces(&table, CE::unknown, &whites);
	whites = !whites;
	const CE::ListOfPieces enemyPieces = Primitives::pieces(&table, CE::unknown, &whites);
	const Real myCost = FuzzyPrimitives::realCost(persestence, myPieces);
	const Real enemyCost = FuzzyPrimitives::realCost(persestence, enemyPieces);
	if(enemyCost == DBL_MIN)
		return myCost;
	if(myCost == DBL_MIN)
		return -enemyCost;
	return myCost - enemyCost;
}

Q_EXPORT_PLUGIN2(moveQuality, MoveQuality);