#include "ClassicGoodPawn.h"
#include <CEEngine.h>
#include <LinearCharacteristicFunction.h>
#include <Utils.h>

ClassicGoodPawn::ClassicGoodPawn()
{
	m_availableValues.push_back(LinguisticValue("weak", new LinearCharacteristicFunction(Point(0, 1), Point(1, 0))));
	m_availableValues.push_back(LinguisticValue("weak", new LinearCharacteristicFunction(Point(0, 0), Point(1, 1))));
}

ClassicGoodPawn::~ClassicGoodPawn()
{

}

QString ClassicGoodPawn::name() const
{
	return "ClassicGoodPawn";
}

QString ClassicGoodPawn::author() const
{
	return "Edward Sarkisyan";
}

QString ClassicGoodPawn::version() const
{
	return "1.0";
}

const ListofLinguisticValues& ClassicGoodPawn::availableValues() const
{
	return m_availableValues;
}

CalculationResultForGame ClassicGoodPawn::calculate( const pgn::Game& game, const Color color ) const
{
	CalculationResultForGame res;
	ChEngn::Engine engine(game);
	while(engine.makeNextHalfMove())
	{
		res.addTable(calculateForTable(engine.getVirtualTable()));
	}
	return res;
}

CalculationResultForTable ClassicGoodPawn::calculateForTable(const ChEngn::VirtualTable&  table) const
{
	CalculationResultForTable res;
	for (char c = 'a'; c <= 'h'; ++c)
	{
		for (char r = '1'; r <= '8'; ++r)
		{
			const ChEngn::Piece* piece = table.pieceAtC(c, r);
			ASSERT(NULL != piece);
			if (piece->type() == ChEngn::pawn)
			{
				res.setSquareValue((piece->isWhite() ? CalculationResultForTable::Whites : CalculationResultForTable::Blacks),
									(short)(c - 'a'),
									(short)(r - '1'),
									calculateForPawn(pgn::Square(c, r), table));
			}
		}
	}
	return res;
}

CalculationResultForSquare ClassicGoodPawn::calculateForPawn(const pgn::Square& square, const ChEngn::VirtualTable& table) const
{
	CalculationResultForSquare res;
	res.setInternalValue(.5);
	res.setTextValue("strong");
	const ChEngn::Piece* piece = table.pieceAtC(square.col(), square.row());
	ASSERT(piece->type() == ChEngn::pawn);
	const char rowInc = piece->isWhite() ? 1 : -1;
	const char rowMax = piece->isWhite() ? 8 :  0;
		  char row = square.row();
	const char col = square.col();
	unsigned char count = 0;
	for(row += rowInc; row != rowMax; row += rowInc)
	{
		const ChEngn::Piece* left = table.pieceAtC(col -1, row);
		const ChEngn::Piece* right = table.pieceAtC(col +1, row);
		const ChEngn::Piece* center = table.pieceAtC(col, row);
		if (!left || !right || !center) continue;
		if((left->color() != piece->color()) ||
		   (right->color() != piece->color()) ||
		   (center->color() != piece->color()))
		{
			res.setInternalValue(.1);
			res.setTextValue("weak");
		}
	}
	return res;
}

Q_EXPORT_PLUGIN2(classicGoodPawn, ClassicGoodPawn);