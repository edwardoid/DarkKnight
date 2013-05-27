#ifndef COMMONPRIMITIVES_H
#define COMMONPRIMITIVES_H

#include "Primitives.h"
#include <CEPiece.h>
#include <CETable.h>
#include <PGNSquare.h>
#include <list>

namespace Primitives {

	struct PRIMITIVES_EXPORT TableAndPos
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
		const CE::VirtualTable* table;
		short row;
		short column;
	};

/**
	Returns queried pieces on table
*/
PRIMITIVES_EXPORT CE::ListOfPieces	pieces(	const CE::VirtualTable*	table,
											const CE::piece_type	type = CE::unknown,
											const bool*					whites = NULL );

/**
	Returns pieces on Rows
*/
PRIMITIVES_EXPORT CE::ListOfPieces	piecesOnRow(const CE::VirtualTable*	table,
												const short				row,
												const CE::piece_type	type	= CE::unknown,
												const bool*				whites	= NULL );

/**
	Returns pieces on Column
*/
PRIMITIVES_EXPORT CE::ListOfPieces	piecesOnColumn(	const CE::VirtualTable*	table,
													const short				column,
													const CE::piece_type	type = CE::unknown,
													const bool*				whites = NULL );
/**
	Returns pieces which attacks square(row, column)
*/
PRIMITIVES_EXPORT CE::ListOfPieces	piecesAttacs(	const CE::VirtualTable&	table,
													const short				column,
													const short				row,
													const bool*				whites = NULL );

/**
	Count pieces on table
*/
PRIMITIVES_EXPORT unsigned short		piecesCount(	const CE::VirtualTable*	table,
														const CE::piece_type	type = CE::unknown,
														const bool*					whites = NULL);

PRIMITIVES_EXPORT int					maxCanCover(const CE::piece_type& type);

PRIMITIVES_EXPORT pgn::ListOfSquares	coveredSquares(	const	CE::VirtualTable*	table,
														const	CE::PieceEx&		piece);

PRIMITIVES_EXPORT bool isOk(const CE::Piece* piece,
							const CE::piece_type type = CE::unknown,
							const bool* whites = NULL );

PRIMITIVES_EXPORT bool canBeCovered(bool coveringPieceIsWhite, const CE::Piece* p);

}
#endif // COMMONPRIMITIVES_H