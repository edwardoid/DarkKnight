#include "CalculationResultForSquare.h"


CalculationResultForSquare::CalculationResultForSquare()
	: m_undefined(true)
	, m_textValue("undefined")
	, m_comment("")
{
}

CalculationResultForSquare::CalculationResultForSquare(const CalculationResultForSquare& other)
{
	if (!other.undefined())
	{
		*this = other;
	}
}

CalculationResultForSquare& CalculationResultForSquare::operator=(const CalculationResultForSquare& other)
{
	m_textValue = other.m_textValue;
	m_comment = other.m_comment;
	m_internalValue = other.m_internalValue;
	return *this;
}

CalculationResultForSquare::~CalculationResultForSquare()
{
}

void CalculationResultForSquare::setTextValue(const QString textValue)
{
	m_textValue = textValue;
}

QString CalculationResultForSquare::textValue() const
{
	return m_textValue;
}

void CalculationResultForSquare::setComment(const QString comment)
{
	m_comment = comment;
}

QString CalculationResultForSquare::comment() const
{
	return m_comment;
}

void CalculationResultForSquare::setInternalValue(const InternalValue internalValue)
{
	m_internalValue = internalValue;
	m_undefined = false;
}

CalculationResultForSquare::InternalValue CalculationResultForSquare::internalValue() const
{
	return m_internalValue;
}