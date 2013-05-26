#ifndef GOODPAWNLINGUISTICVARIABLEMEMBERSHIPFUNCTION_H
#define GOODPAWNLINGUISTICVARIABLEMEMBERSHIPFUNCTION_H

#include <QtGlobal>
#include <MembershipFunction.h>
#include <CETable.h>

struct TableAndPos
{
	TableAndPos(){};
	TableAndPos(const TableAndPos& o) { *this = o; }
	TableAndPos& operator = (const TableAndPos& o)
	{
		this->table = o.table;
		this->row = o.row;
		this->column = o.column;
		return *this;
	}
	const ChEngn::VirtualTable* table;
	short row;
	short column;
};

class Q_DECL_EXPORT GoodPawnLinguisticVariableMembershipFunction :
	public MembershipFunction<TableAndPos>
{
public:
	GoodPawnLinguisticVariableMembershipFunction();
	virtual ~GoodPawnLinguisticVariableMembershipFunction();
	virtual Real operator()();
};


#endif // GOODPAWNLINGUISTICVARIABLEMEMBERSHIPFUNCTION_H
