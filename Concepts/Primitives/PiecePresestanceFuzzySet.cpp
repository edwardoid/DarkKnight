#include "PiecePresestanceFuzzySet.h"

namespace FuzzyPrimitives
{

Real PiecePrestemceMembershipFunction::operator()() const
{
	const CE::PieceEx& a = arg();
	const int coveredOnTable = Primitives::coveredSquares(&m_table, a).size();  // MR_r
	const int maxCanCover = Primitives::maxCanCover(a.type()); // MR_t

	if(maxCanCover == 0)
		return DBL_MIN;

	return Real(coveredOnTable) / maxCanCover;
}

PiecePrestemceFuzzySet::PiecePrestemceFuzzySet( const CE::VirtualTable& table )
	: FuzzySet(PiecePrestemceFuzzySet::SetOfElements(), MembershipFunctionPtr(new PiecePrestemceMembershipFunction(table)))
	, m_table(table)
{
	CE::ListOfPieces allPieces = Primitives::pieces(&table);
	CE::ListOfPieces::const_iterator piece = allPieces.cbegin();
	for(; piece != allPieces.cend(); ++piece)
	{
		if(!piece->isUnknown())
			add(*piece);
	}
}

PiecePrestemceFuzzySet& PiecePrestemceFuzzySet::operator=( const PiecePrestemceFuzzySet& src )
{
	FuzzySet<PiecePrestemceFuzzySet::ElementType>::operator =(src);
	m_table = src.m_table;
	return *this;
}

}