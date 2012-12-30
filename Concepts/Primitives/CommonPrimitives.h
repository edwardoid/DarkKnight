#ifndef COMMONPRIMITIVES_H
#define COMMONPRIMITIVES_H

#include "Primitives.h"
#include <CEPiece.h>
#include <CETable.h>
#include <list>

namespace Primitives {

PRIMITIVES_EXPORT ChEngn::ListOfPieces	pieces(	const ChEngn::VirtualTable* table,
												const ChEngn::piece_type type = ChEngn::unknown,
												const bool* whites = NULL );

PRIMITIVES_EXPORT ChEngn::ListOfPieces	piecesOnRow(	const ChEngn::VirtualTable* table,
	const short row,
	const ChEngn::piece_type type = ChEngn::unknown,
	const bool* whites = NULL );

PRIMITIVES_EXPORT ChEngn::ListOfPieces	piecesOnColumn(	const ChEngn::VirtualTable* table,
														const short column,
														const ChEngn::piece_type type = ChEngn::unknown,
														const bool* whites = NULL );

PRIMITIVES_EXPORT ChEngn::ListOfPieces	piecesAttacs(	const ChEngn::VirtualTable& table,
														const short column,
														const short row,
														const bool* whites = NULL );

PRIMITIVES_EXPORT unsigned short		piecesCount(	const ChEngn::VirtualTable* table,
														const ChEngn::piece_type type = ChEngn::unknown,
														const bool* whites = NULL);

PRIMITIVES_EXPORT bool isOk(const ChEngn::Piece* piece,
							const ChEngn::piece_type type = ChEngn::unknown,
							const bool* whites = NULL );

}
#endif // COMMONPRIMITIVES_H