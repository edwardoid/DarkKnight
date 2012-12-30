#include "GoodPawnLinguisticVariableMembershipFunction.h"
#include <CommonPrimitives.h>

GoodPawnLinguisticVariableMembershipFunction::GoodPawnLinguisticVariableMembershipFunction()
{
}


GoodPawnLinguisticVariableMembershipFunction::~GoodPawnLinguisticVariableMembershipFunction()
{
}


/*
	Calculation formula has been implemented as described in
	Suren Shakhnazaryan's course work. Final formula is:
		Pawn_power = [(n1 + n2) / 2] * n3 * n4
	, where n1, n2, n3 and n4 are various coefficients.
	See Suren's work for more information.
*/
Real GoodPawnLinguisticVariableMembershipFunction::operator()()
{
	ChEngn::Piece* piece = arg().table->pieceAt(arg().column, arg().row);
	if(piece == NULL)
		return NotANumber;
	if(piece->type() != ChEngn::pawn)
		return NotANumber;
	bool whites = piece->isWhite();
	double enemyPiecesCount = Primitives::piecesCount(arg().table, ChEngn::unknown, &whites) - 
							  Primitives::piecesCount(arg().table, ChEngn::pawn, &whites) - 1;
	const double n1 = 1. - enemyPiecesCount / 8.;

	double squaresCountToGoalWithoutGoalSquare = (whites ? (6 - arg().row) : (arg().row - 1));
	double squaresCountToGoal = squaresCountToGoalWithoutGoalSquare + 1.;
	const double n2 = 1. - squaresCountToGoalWithoutGoalSquare / 6.;

	double squaresCountToGoalNotUnderAttack = squaresCountToGoal;
	double freeSquaresCount = squaresCountToGoal;
	const int coef = whites ? 1 : -1;
	const int goalRow = whites ? 7 : -1;
	bool enemy = !whites;
	for (int r = arg().row + coef; r != goalRow; r += coef)
	{
		if(Primitives::piecesAttacs(*(arg().table), arg().column, r, &enemy).size() > 0)
			squaresCountToGoalNotUnderAttack -= 1.;
		ChEngn::Piece *p = arg().table->pieceAt(arg().column, r);
		//ASSERT(p != NULL);
		if(!p->isUnknown())
		{
			freeSquaresCount -= 1.;
		}
	}

	const double n3 = squaresCountToGoalNotUnderAttack / squaresCountToGoal;
	const double n4 = freeSquaresCount / squaresCountToGoal;

	return ((n1 + n2) / 2) * n3 * n4;
}