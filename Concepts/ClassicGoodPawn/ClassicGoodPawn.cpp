#include "ClassicGoodPawn.h"
#include <CEEngine.h>
#include <LinearCharacteristicFunction.h>
#include <Utils.h>
#include <CommonPrimitives.h>
#include <CEPiece.h>

ClassicGoodPawn::ClassicGoodPawn()
{
	m_availableValues.push_back(LinguisticValue("weak", new LinearCharacteristicFunction(Point(0, 1), Point(1, 0))));
	m_availableValues.push_back(LinguisticValue("strong", new LinearCharacteristicFunction(Point(0, 0), Point(1, 1))));
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
	CE::Engine engine(game);
	while(engine.makeNextHalfMove())
	{
		res.addTable(calculateForTable(engine.getVirtualTable(), color));
	}
	return res;
}

CalculationResultForTable ClassicGoodPawn::calculateForTable(const CE::VirtualTable&  table, const Color color) const
{
	CalculationResultForTable res;
	const bool whites = (color == ConceptPlugin::Whites);
	CE::ListOfPieces pieces = Primitives::pieces(&table, CE::pawn, &whites);


	CE::ListOfPieces::const_iterator itPiece = pieces.cbegin();
	CalculationResultForTable::Color c = color == ConceptPlugin::Whites ? CalculationResultForTable::Whites : CalculationResultForTable::Blacks;
	for (; itPiece != pieces.cend(); ++itPiece)
	{
		res.setSquareValue(c, itPiece->column(), itPiece->row(), calculateForPawn(pgn::Square(itPiece->column(), itPiece->row()), table));
	}
	return res;
}

CalculationResultForSquare ClassicGoodPawn::calculateForPawn(const pgn::Square& square, const CE::VirtualTable& table) const
{
	CalculationResultForSquare res;
	res.setInternalValue(.5);
	res.setTextValue("strong");
	const CE::Piece* piece = table.pieceAt(square.col(), square.row());
	ASSERT(piece->type() == CE::pawn);
	const char rowInc = piece->isWhite() ? 1 : -1;
	const char rowMax = piece->isWhite() ? 8 :  0;
		  char row = square.row();
	const char col = square.col();
	unsigned char count = 0;
	for(row += rowInc; row != rowMax; row += rowInc)
	{
		const CE::Piece* left = table.pieceAt(col -1, row);
		const CE::Piece* right = table.pieceAt(col +1, row);
		const CE::Piece* center = table.pieceAt(col, row);
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