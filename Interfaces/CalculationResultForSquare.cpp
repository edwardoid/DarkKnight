#include "CalculationResultForSquare.h"


CalculationResultForSquare::CalculationResultForSquare()
	: m_undefined(true)
	, m_textValue("undefined")
	, m_comment("")
	, m_internalValue(-1.)
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
	m_undefined = other.m_undefined;
	return *this;
}

CalculationResultForSquare::~CalculationResultForSquare()
{
}

void CalculationResultForSquare::setTextValue(const QString textValue)
{
	m_textValue = textValue;
	m_undefined = false;
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

void CalculationResultForSquare::merge( const CalculationResultForSquare& src )
{
	m_internalValue = std::max(m_internalValue, src.m_internalValue);
	if(src.textValue().size() > 0)
	{
		if(m_textValue.size() > 0)
			m_textValue.append("; ");
		m_textValue.append(src.m_textValue);
	}
	if(m_internalValue > 0)
	{
		m_undefined = false;
	}
}
