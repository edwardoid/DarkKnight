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
	if(!value.textValue().isEmpty() && !m_textValues.contains(value.textValue()))
	{
		m_textValues << value.textValue();
	}
}

const CalculationResultForSquare& CalculationResultForTable::squareValue(const CalculationResultForTable::Color color,
																   const short column,
																   const short row) const
{
	if (column >= 8 || row >= 8 || column < 0 || row < 0) return CalculationResultForSquare();
	if(color == Blacks)
		return m_blacksTable[row][column];
	return m_whitesTable[row][column];
}

CalculationResultForTable::~CalculationResultForTable()
{
}

const QStringList CalculationResultForTable::textValues() const
{
	return m_textValues;
}

void CalculationResultForTable::merge( const CalculationResultForTable& src )
{
	for (int row = 0; row < 8; ++row)
	{
		for(int column = 0; column < 8; ++column)
		{
			m_whitesTable[row][column].merge(src.m_whitesTable[row][column]);
			QString strWhites = src.m_whitesTable[row][column].textValue();
			m_blacksTable[row][column].merge(src.m_blacksTable[row][column]);
			QString strBlacks = src.m_blacksTable[row][column].textValue();
			if(!m_textValues.contains(strWhites))
				m_textValues << strWhites;
			if(!m_textValues.contains(strBlacks))
				m_textValues << strBlacks;
		}
	}
}

bool CalculationResultForTable::hasValuesFor( Color color ) const
{
	for (int row = 0; row < 8; ++row)
	{
		for(int column = 0; column < 8; ++column)
		{
			if(color == CalculationResultForTable::Whites)
			{
				if(m_whitesTable[row][column].internalValue() > 0)
					return true;
			}
			else
			{
				if(m_blacksTable[row][column].internalValue() > 0)
					return true;
			}
		}
	}
	return false;
}
