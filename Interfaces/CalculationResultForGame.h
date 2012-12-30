#ifndef CALCULATIONRESULTFORGAME_H
#define CALCULATIONRESULTFORGAME_H

#include "InterfacesGlobal.h"
#include "CalculationResultForTable.h"
#include "CalculationResultForSquare.h"

class EXPORT_INTERFACES CalculationResultForGame
{
public:

	typedef double InternalValue;
	CalculationResultForGame();
	CalculationResultForGame(const CalculationResultForGame& other);
	CalculationResultForGame& CalculationResultForGame::operator=(const CalculationResultForGame& other);
	~CalculationResultForGame();
	void setTextValue(const QString textValue);
	QString textValue() const;
	void setComment(const QString comment);
	QString comment() const;
	void setInternalValue(const InternalValue internalValue);
	InternalValue internalValue() const;
	bool undefined() const;
	void addTable(const CalculationResultForTable table);
	const CalculationResultForTable& tableAt(const unsigned int) const;
	inline int size() const { return m_tables.size(); }
private:
	QString m_textValue;
	QString m_comment;
	InternalValue m_internalValue;
	bool m_undefined;
	CalculationResultTablesList m_tables;
};

#endif // CALCULATIONRESULTFORGAME_H