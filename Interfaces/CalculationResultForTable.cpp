#include "CalculationResultForTable.h"
#include <Utils.h>


CalculationResultForTable::CalculationResultForTable()
{
	m_whitesTable = new CalculationResultForSquare* [8];
	m_blacksTable = new CalculationResultForSquare* [8];
	for (short col = 0; col< 8; ++col)
	{
		m_whitesTable[col] = new CalculationResultForSquare[8];
		m_blacksTable[col] = new CalculationResultForSquare[8];
	}
}

CalculationResultForTable::CalculationResultForTable(const CalculationResultForTable& other)
{
	m_whitesTable = new CalculationResultForSquare* [8];
	m_blacksTable = new CalculationResultForSquare* [8];
	for (short col = 0; col< 8; ++col)
	{
		m_whitesTable[col] = new CalculationResultForSquare[8];
		m_blacksTable[col] = new CalculationResultForSquare[8];
	}
	*this = other;
}

CalculationResultForTable& CalculationResultForTable::operator=(const CalculationResultForTable& other)
{
	for(short col = 0; col < 8; ++col)
	{
		for(short row = 0; row < 8; ++row)
		{
			setSquareValue(Whites, col, row, other.squareValue(Whites, col, row));
			setSquareValue(Blacks, col, row, other.squareValue(Blacks, col, row));
		}
	}
	return *this;
}

void CalculationResultForTable::setSquareValue(const CalculationResultForTable::Color color,
											   const short column,
											   const short row,
											   const CalculationResultForSquare value)
{
	ASSERT(column < 8 || row < 8 || column >= 0 || row >= 0);
	CalculationResultForSquare& square = ((color != Blacks) ? m_whitesTable[row][column] : m_blacksTable[row][column]);
	if (!value.undefined())
	{
		square = value;
	}
}

const CalculationResultForSquare& CalculationResultForTable::squareValue(const CalculationResultForTable::Color color,
																   const short column,
																   const short row) const
{
	if (column >= 8 || row >= 8 || column < 0 || row < 0) return CalculationResultForSquare();
	return ((color != Blacks) ? m_whitesTable[row][column] : m_blacksTable[row][column]);
}

CalculationResultForTable::~CalculationResultForTable()
{
}
