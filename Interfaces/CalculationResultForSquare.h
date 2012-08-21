
#ifndef CALCULATIONRESULTFORSQUARE_H
#define CALCULATIONRESULTFORSQUARE_H

#include "InterfacesGlobal.h"
#include <QString>

class EXPORT_INTERFACES CalculationResultForSquare
{
public:

	typedef double InternalValue;
	CalculationResultForSquare();
	CalculationResultForSquare(const CalculationResultForSquare& other);
	CalculationResultForSquare& operator=(const CalculationResultForSquare& other);
	~CalculationResultForSquare();
	void setTextValue(const QString textValue);
	QString textValue() const;
	void setComment(const QString comment);
	QString comment() const;
	void setInternalValue(const InternalValue internalValue);
	InternalValue internalValue() const;
	bool undefined() const;
private:
	QString m_textValue;
	QString m_comment;
	InternalValue m_internalValue;
	bool m_undefined;
};

#endif // CALCULATIONRESULTFORSQUARE_H