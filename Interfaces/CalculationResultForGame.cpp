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
	m_textValues = other.m_textValues;
	m_comment = other.m_comment;
	m_internalValue = other.m_internalValue;
	unsigned int tablesCount = other.m_tables.size();
	for(unsigned int i = 0; i < tablesCount; ++i)
		addTable(other.tableAt(i));
	return *this;
}

bool CalculationResultForGame::hasValue(const QString textValue) const
{
	return m_textValues.contains(textValue);
}

QStringList CalculationResultForGame::textValues() const
{
	return m_textValues;
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
	QStringList tableValues = table.textValues();
	foreach(QString tableValue, tableValues)
	{
		if(!hasValue(tableValue))
			m_textValues.append(tableValue);
	}
}

const CalculationResultForTable& CalculationResultForGame::tableAt(const unsigned int i) const
{
	return m_tables[i];
}