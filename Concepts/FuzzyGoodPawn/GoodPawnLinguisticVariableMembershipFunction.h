#ifndef GOODPAWNLINGUISTICVARIABLEMEMBERSHIPFUNCTION_H
#define GOODPAWNLINGUISTICVARIABLEMEMBERSHIPFUNCTION_H

#include <QtGlobal>
#include <MembershipFunction.h>
#include <CETable.h>
#include <CommonPrimitives.h>

class Q_DECL_EXPORT GoodPawnLinguisticVariableMembershipFunction :
	public MembershipFunction<Primitives::TableAndPos>
{
public:
	GoodPawnLinguisticVariableMembershipFunction();
	virtual ~GoodPawnLinguisticVariableMembershipFunction();
	virtual Real operator() (void) const;
};


#endif // GOODPAWNLINGUISTICVARIABLEMEMBERSHIPFUNCTION_H
