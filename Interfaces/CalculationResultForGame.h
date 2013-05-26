#ifndef CALCULATIONRESULTFORGAME_H
#define CALCULATIONRESULTFORGAME_H

#include "InterfacesGlobal.h"
#include "CalculationResultForTable.h"
#include "CalculationResultForSquare.h"
#include <QStringList>

class EXPORT_INTERFACES CalculationResultForGame
{
public:

	typedef double InternalValue;
	CalculationResultForGame();
	CalculationResultForGame(const CalculationResultForGame& other);
	CalculationResultForGame& CalculationResultForGame::operator=(const CalculationResultForGame& other);
	~CalculationResultForGame();
	bool hasValue(const QString testValue) const;
	QStringList textValues() const;
	void setComment(const QString comment);
	QString comment() const;
	void setInternalValue(const InternalValue internalValue);
	InternalValue internalValue() const;
	bool undefined() const;
	void addTable(const CalculationResultForTable table);
	const CalculationResultForTable& tableAt(const unsigned int) const;
	inline int size() const { return m_tables.size(); }
private:
	QStringList m_textValues;
	QString m_comment;
	InternalValue m_internalValue;
	bool m_undefined;
	CalculationResultTablesList m_tables;
};

#endif // CALCULATIONRESULTFORGAME_H