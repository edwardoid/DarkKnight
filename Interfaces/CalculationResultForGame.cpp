#include "CalculationResultForGame.h"


CalculationResultForGame::CalculationResultForGame(void)
{
}


CalculationResultForGame::~CalculationResultForGame(void)
{
}

CalculationResultForGame::CalculationResultForGame(const CalculationResultForGame& other)
{
	*this = other;
}

CalculationResultForGame& CalculationResultForGame::operator=(const CalculationResultForGame& other)
{
	m_textValue = other.m_textValue;
	m_comment = other.m_comment;
	m_internalValue = other.m_internalValue;
	unsigned int tablesCount = other.m_tables.size();
	for(unsigned int i = 0; i < tablesCount; ++i)
		addTable(other.tableAt(i));
	return *this;
}

void CalculationResultForGame::setTextValue(const QString textValue)
{
	m_textValue = textValue;
}

QString CalculationResultForGame::textValue() const
{
	return m_textValue;
}

void CalculationResultForGame::setComment(const QString comment)
{
	m_comment = comment;
}

QString CalculationResultForGame::comment() const
{
	return m_comment;
}

void CalculationResultForGame::setInternalValue(const InternalValue internalValue)
{
	m_internalValue = internalValue;
	m_undefined = false;
}

CalculationResultForGame::InternalValue CalculationResultForGame::internalValue() const
{
	return m_internalValue;
}

void CalculationResultForGame::addTable(const CalculationResultForTable table)
{
	m_tables << table;
	m_undefined = false;
}

const CalculationResultForTable& CalculationResultForGame::tableAt(const unsigned int i) const
{
	return m_tables[i];
}