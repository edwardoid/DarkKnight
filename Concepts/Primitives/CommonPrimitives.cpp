#include "CommonPrimitives.h"
#include <string>
#include <PGNPly.h>
#include <CEPawnMove.h>
#include <CERookMove.h>
#include <CEKnightMove.h>
#include <CEBishopMove.h>
#include <CEQueenMove.h>
#include <CEKingMove.h>
#include <CEException.h>
#include <CEPiece.h>
#include <ScopedPointer.h>

namespace Primitives {

CE::ListOfPieces pieces(const CE::VirtualTable* table, const CE::piece_type type, const bool* whites )
{
	CE::ListOfPieces res;
	for(int r = 0; r < 8; ++r)
	{
		CE::ListOfPieces tmpRes = piecesOnRow(table, r, type, whites);
		res.insert(res.end(), tmpRes.begin(), tmpRes.end());
	}
	return res;
}

CE::ListOfPieces piecesOnRow(const CE::VirtualTable* table, const short row, const CE::piece_type type, const bool* whites)
{
	CE::ListOfPieces res;
	for(int c = 0; c < 8; ++c)
	{
		const CE::Piece* p = table->pieceAt(c, row);
		if(isOk(p, type, whites))
			res.push_back(CE::PieceEx(*p, row, c));
	}
	return res;
}
CE::ListOfPieces piecesOnColumn(const CE::VirtualTable* table, const short column, const CE::piece_type type, const bool* whites)
{
	CE::ListOfPieces res;
	for(int r = 0; r < 8; ++r)
	{
		const CE::Piece* p = table->pieceAt(column, r);
		if(isOk(p, type, whites))
			res.push_back(CE::PieceEx(*p, r, column));
	}
	return res;
}


bool isOk(const CE::Piece* piece, const CE::piece_type type, const bool* whites)
{
	if(piece == NULL) return false;
	if(whites != NULL && (piece->isWhite() ^ *whites) || piece->isUnknown())
		return false;
	return true;
}

CE::ListOfPieces piecesAttacs_helper( const CE::VirtualTable& table, const short column, const short row, const bool whites )
{
	CE::VirtualTable tmp = table;
	CE::ListOfPieces res;
	// Rook
	std::string plyString = "Ra1";
	plyString[1] += (char)column;
	plyString[2] += (char)row;
	ScopedPointer<pgn::Ply> ply(new pgn::Ply(plyString));
	CE::RookMove rM(ply, whites);
	
	try {
		if(rM.make(&tmp))
		{
			tmp = table;
			res.push_back(rM.movedPiece());
		}
	}
	catch(CE::BadMove e) {}
	// Knight
	plyString[0] = 'N';
	ply = new pgn::Ply(plyString);
	CE::KnightMove knM(ply, whites);
	try {
		if(knM.make(&tmp))
		{
			tmp = table;
			res.push_back(knM.movedPiece());
		}
	}
	catch(CE::BadMove e) {}
	// Bishop
	plyString[0] = 'B';
	ply = new pgn::Ply(plyString);
	CE::BishopMove bM(ply, whites);
	try {
		if(bM.make(&tmp))
		{
			tmp = table;
			res.push_back(bM.movedPiece());
		}
	}
	catch(CE::BadMove e) {}
	// Queen
	plyString[0] = 'Q';
	ply = new pgn::Ply(plyString);
	CE::QueenMove qM(ply, whites);
	try {
		if(qM.make(&tmp))
		{
			tmp = table;
			res.push_back(qM.movedPiece());
		}
	}
	catch(CE::BadMove e) {}
	// King
	plyString[0] = 'K';
	ply = new pgn::Ply(plyString);
	CE::KingMove kM(ply, whites);
	try {
		if(kM.make(&tmp))
		{
			tmp = table;
			res.push_back(kM.movedPiece());
		}
	}
	catch(CE::BadMove e) {}
	std::string pawnCaptureString = "axa1";
	pawnCaptureString[2] += (char)column;
	pawnCaptureString[3] += (char)row;
	tmp.pieceAt(column, row)->setType(CE::pawn);
	if(whites)
		tmp.pieceAt(column, row)->setBlack();
	else
		tmp.pieceAt(column, row)->setWhite();
	if(column > 0)
	{
		pawnCaptureString[0] =  'a' + (char)column - 1;
		ply = new pgn::Ply(pawnCaptureString);
		CE::PawnMove pLM(ply, whites);
		try {
			if(pLM.make(&tmp))
			{
				res.push_back(pLM.movedPiece());
			}
		}
		catch(CE::BadMove e) {}
	}
	tmp.pieceAt(column, row)->setType(CE::pawn);
	if(whites)
		tmp.pieceAt(column, row)->setBlack();
	else
		tmp.pieceAt(column, row)->setWhite();
	if(column < 6)
	{
		pawnCaptureString[0] =  'a' + (char)column + 1;
		ply = new pgn::Ply(pawnCaptureString);
		CE::PawnMove pRM(ply, whites);
		try {
			if(pRM.make(&tmp))
			{
				res.push_back(pRM.movedPiece());
			}
		}
		catch(CE::BadMove e) {}
	}

	return res;
}

CE::ListOfPieces piecesAttacs(	const CE::VirtualTable& table,
									const short column,
									const short row,
									const bool* whites /*= NULL */ )
{
	if(column > 7 || column < 0 || row > 7 || row < 0)
		return CE::ListOfPieces();
	CE::VirtualTable tmp = table;
	tmp.pieceAt(column, row)->setType(CE::unknown);
	
	if(whites != NULL)
		return piecesAttacs_helper(tmp, column, row, *whites);
	
	CE::ListOfPieces resWhites = piecesAttacs_helper(tmp, column, row, true);
	CE::ListOfPieces resBlacks = piecesAttacs_helper(tmp, column, row, false);

	if(resBlacks.size() > 0)
		resWhites.insert(resWhites.end(), resBlacks.begin(), resBlacks.end());
	return	resWhites;
}

unsigned short piecesCount_helper( const CE::VirtualTable* table, CE::piece_type type, const bool whites )
{
	unsigned short res = 0;
	for (unsigned int c = 0; c < 8; ++c)
	{
		for(unsigned int r = 0; r < 8; ++r)
		{
			CE::Piece* p = table->pieceAt(c, r);
			if(p == NULL) continue;
			if(p->isUnknown()) continue;
			if(type != CE::unknown && p->type() != type) continue;
			if(p->isBlack() ^ whites)
				++res;
		}
	}
	return res;
}

unsigned short piecesCount( const CE::VirtualTable* table,
							const CE::piece_type type /*= ChEngn::unknown*/,
							const bool* whites /*= NULL*/ )
{
	if(whites != NULL)
		return piecesCount_helper(table, type, *whites);
	return piecesCount_helper(table, type, true) + piecesCount_helper(table, type, false);
}

bool canBeCovered(bool coveringPieceIsWhite, const CE::Piece* p)
{
	if(p == NULL)
		return false;
	if(p->isUnknown())
		return true;
	return p->isWhite() ^ coveringPieceIsWhite;
}


void coveredSquares_helper_bishop(	const	CE::VirtualTable* table,
									const	CE::PieceEx& piece,
											pgn::ListOfSquares& res)
{
	pgn::Square pos = piece.square();
	
	if(!pos)
		return; 

	char iters = 0;
	for(short r = pos.rowIndex() + 1; r < 8; ++r ) // move up right
	{

		pgn::Square tmpPos(pos.col() + iters, r + '1');
		if(canBeCovered(piece.isWhite(), table->pieceAt(tmpPos)))
			res.push_back(tmpPos);
		++iters;
	}

	iters = 0;
	for(short r = pos.rowIndex() + 1; r < 8; ++r ) // move up right
	{

		pgn::Square tmpPos(pos.col() - iters, '1' + r);
		if(canBeCovered(piece.isWhite(), table->pieceAt(tmpPos)))
			res.push_back(tmpPos);
	}

	iters = 0;
	for(short r = 0; r < pos.rowIndex(); ++r ) // move up left
	{

		pgn::Square tmpPos(pos.col() + r, r + '1');
		if(canBeCovered(piece.isWhite(), table->pieceAt(tmpPos)))
			res.push_back(tmpPos);
	}

	iters = 0;
	for(short r = 0; r < pos.rowIndex(); ++r ) // move up left
	{

		pgn::Square tmpPos(pos.col() + r, r + '1');
		if(canBeCovered(piece.isWhite(), table->pieceAt(tmpPos)))
			res.push_back(tmpPos);
	}
}

void coveredSquares_helper_rook(const	CE::VirtualTable* table,
								const	CE::PieceEx& piece,
										pgn::ListOfSquares& res)
{
	pgn::Square pos = piece.square();

	if(!pos)
		return;

	for (char r = pos.row() + 1; r < '9'; ++r)
	{
		pgn::Square sq(r, pos.col());
		if(canBeCovered(piece.isWhite(), table->pieceAt(sq)))
			res.push_back(sq);
	}

	for (char r = '1' ; r < pos.row(); ++r)
	{
		pgn::Square sq(r, pos.col());
		if(canBeCovered(piece.isWhite(), table->pieceAt(sq)))
			res.push_back(sq);
	}

	for (char c = pos.col() + 1; c < ('h' + 1); ++c)
	{
		pgn::Square sq(c, pos.row());
		if(canBeCovered(piece.isWhite(), table->pieceAt(sq)))
			res.push_back(sq);
	}

	for (char c = 'a' ; c < pos.col(); ++c)
	{
		pgn::Square sq(c, pos.row());
		if(canBeCovered(piece.isWhite(), table->pieceAt(sq)))
			res.push_back(sq);
	}

}

int maxCanCover(const CE::piece_type& type)
{
	switch(type)
	{
	case CE::pawn:
		{
			return 2;
		}
	case CE::knight:
	case CE::king:
		{
			return 8;
		}
	case CE::bishop:
		{
			return 13;
		}
	case CE::rook:
		{
			return 14;
		}
	case CE::queen:
		{
			return 27;
		}
	default:
		{
			return 0;
		}
	}
	return 0;
}

pgn::ListOfSquares coveredSquares(	const CE::VirtualTable* table,
									const CE::PieceEx& piece ) 

{
	pgn::ListOfSquares res;

	pgn::Square pos = piece.square();

	if(!pos)
		return res;

	switch(piece.type())
	{
	case CE::pawn:
		{

			short direction = piece.isWhite() ? 1 : -1;
			pgn::Square left(pos.col() + direction, pos.row() - 1);
			if(left)
			{
				const CE::Piece* pl = table->pieceAt(left);
				if(canBeCovered(piece.isWhite(), pl))
					res.push_back(left);
			}
			pgn::Square right(pos.col() + direction, pos.row() + 1);
			if(right)
			{
				const CE::Piece* pr = table->pieceAt(right);
				if(canBeCovered(piece.isWhite(), pr))
					res.push_back(right);
			}
			break;
		}
	case CE::knight:
		{
			const pgn::ListOfSquares availablePoss = CE::KnightMove::knightPositions(pos);
			pgn::ListOfSquares::const_iterator it = availablePoss.cbegin();
			for(; it != availablePoss.cend(); ++it)
			{
				const CE::Piece* p = table->pieceAt(*it);
				if(canBeCovered(piece.isWhite(), p))
					res.push_back(*it);
			}
			break;
		}
	case CE::king:
		{
			const pgn::ListOfSquares availablePoss = CE::KingMove::kingPositions(pos);
			pgn::ListOfSquares::const_iterator it = availablePoss.cbegin();
			for(; it != availablePoss.cend(); ++it)
			{
				const CE::Piece* p = table->pieceAt(*it);
				if(canBeCovered(piece.isWhite(), p))
					res.push_back(*it);
			}
			break;
		}
	case CE::bishop:
	case CE::rook:
	case CE::queen:
		{
			if(piece.type() != CE::rook) // Bishop or queen
			{
				coveredSquares_helper_bishop(table, piece, res);
			}
			
			if(piece.type() != CE::bishop) // Rook or queen
			{
				coveredSquares_helper_rook(table, piece, res);
			}
		}
	}
	return res;
}
}