#ifndef CALCULATIONRESULTFORTABLE_H
#define CALCULATIONRESULTFORTABLE_H

#include "InterfacesGlobal.h"
#include "CalculationResultForSquare.h"
#include <QList>
#include <QStringList>

class EXPORT_INTERFACES CalculationResultForTable
{
public:
	typedef CalculationResultForSquare** ResultTable;

	typedef enum
	{
		Any = 0,
		Whites,
		Blacks
	} Color;

	CalculationResultForTable();
	CalculationResultForTable(const CalculationResultForTable& other);
	CalculationResultForTable& operator=(const CalculationResultForTable& other);
	~CalculationResultForTable();
	void setSquareValue(const Color color, const short column, const short row, const CalculationResultForSquare value);
	const CalculationResultForSquare& squareValue(const Color color, const short column, const short row) const;
	const QStringList textValues() const;
private:
	ResultTable m_whitesTable;
	ResultTable m_blacksTable;
	QStringList m_textValues;
};

typedef QList<CalculationResultForTable> CalculationResultTablesList;

#endif // CALCULATIONRESULTFORTABLE_H
