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
#include <ScopedPointer.h>

namespace Primitives {

ChEngn::ListOfPieces pieces(const ChEngn::VirtualTable* table, const ChEngn::piece_type type, const bool* whites )
{
	ChEngn::ListOfPieces res;
	for(int r = 0; r < 8; ++r)
	{
		ChEngn::ListOfPieces tmpRes = piecesOnRow(table, r, type, whites);
		res.insert(res.end(), tmpRes.begin(), tmpRes.end());
	}
	return res;
}

ChEngn::ListOfPieces piecesOnRow(const ChEngn::VirtualTable* table, const short row, const ChEngn::piece_type type, const bool* whites)
{
	ChEngn::ListOfPieces res;
	for(int c = 0; c < 8; ++c)
	{
		const ChEngn::Piece* p = table->pieceAt(c, row);
		if(isOk(p, type, whites))
			res.push_back(ChEngn::PieceEx(*p, row, c));
	}
	return res;
}
ChEngn::ListOfPieces piecesOnColumn(const ChEngn::VirtualTable* table, const short column, const ChEngn::piece_type type, const bool* whites)
{
	ChEngn::ListOfPieces res;
	for(int r = 0; r < 8; ++r)
	{
		const ChEngn::Piece* p = table->pieceAt(column, r);
		if(isOk(p, type, whites))
			res.push_back(ChEngn::PieceEx(*p, r, column));
	}
	return res;
}

bool isOk(const ChEngn::Piece* piece, const ChEngn::piece_type type, const bool* whites)
{
	if(piece == NULL) return false;
	if(whites != NULL && !(piece->isWhite() ^ *whites))
		return false;
	if(type != ChEngn::unknown && piece->type() != type)
		return false;
	return true;
}

ChEngn::ListOfPieces piecesAttacs_helper( const ChEngn::VirtualTable& table, const short column, const short row, const bool whites )
{
	ChEngn::VirtualTable tmp = table;
	ChEngn::ListOfPieces res;
	// Rook
	std::string plyString = "Ra1";
	plyString[1] += (char)column;
	plyString[2] += (char)row;
	ScopedPointer<pgn::Ply> ply(new pgn::Ply(plyString));
	ChEngn::RookMove rM(ply, whites);
	
	try {
		if(rM.make(&tmp))
		{
			tmp = table;
			res.push_back(rM.movedPiece());
		}
	}
	catch(ChEngn::BadMove e) {}
	// Knight
	plyString[0] = 'N';
	ply = new pgn::Ply(plyString);
	ChEngn::KnightMove knM(ply, whites);
	try {
		if(knM.make(&tmp))
		{
			tmp = table;
			res.push_back(knM.movedPiece());
		}
	}
	catch(ChEngn::BadMove e) {}
	// Bishop
	plyString[0] = 'B';
	ply = new pgn::Ply(plyString);
	ChEngn::BishopMove bM(ply, whites);
	try {
		if(bM.make(&tmp))
		{
			tmp = table;
			res.push_back(bM.movedPiece());
		}
	}
	catch(ChEngn::BadMove e) {}
	// Queen
	plyString[0] = 'Q';
	ply = new pgn::Ply(plyString);
	ChEngn::QueenMove qM(ply, whites);
	try {
		if(qM.make(&tmp))
		{
			tmp = table;
			res.push_back(qM.movedPiece());
		}
	}
	catch(ChEngn::BadMove e) {}
	// King
	plyString[0] = 'K';
	ply = new pgn::Ply(plyString);
	ChEngn::KingMove kM(ply, whites);
	try {
		if(kM.make(&tmp))
		{
			tmp = table;
			res.push_back(kM.movedPiece());
		}
	}
	catch(ChEngn::BadMove e) {}
	std::string pawnCaptureString = "axa1";
	pawnCaptureString[2] += (char)column;
	pawnCaptureString[3] += (char)row;
	tmp.pieceAt(column, row)->setType(ChEngn::pawn);
	if(whites)
		tmp.pieceAt(column, row)->setBlack();
	else
		tmp.pieceAt(column, row)->setWhite();
	if(column > 0)
	{
		pawnCaptureString[0] =  'a' + (char)column - 1;
		ply = new pgn::Ply(pawnCaptureString);
		ChEngn::PawnMove pLM(ply, whites);
		try {
			if(pLM.make(&tmp))
			{
				res.push_back(pLM.movedPiece());
			}
		}
		catch(ChEngn::BadMove e) {}
	}
	tmp.pieceAt(column, row)->setType(ChEngn::pawn);
	if(whites)
		tmp.pieceAt(column, row)->setBlack();
	else
		tmp.pieceAt(column, row)->setWhite();
	if(column < 6)
	{
		pawnCaptureString[0] =  'a' + (char)column + 1;
		ply = new pgn::Ply(pawnCaptureString);
		ChEngn::PawnMove pRM(ply, whites);
		try {
			if(pRM.make(&tmp))
			{
				res.push_back(pRM.movedPiece());
			}
		}
		catch(ChEngn::BadMove e) {}
	}

	return res;
}

ChEngn::ListOfPieces piecesAttacs(	const ChEngn::VirtualTable& table,
									const short column,
									const short row,
									const bool* whites /*= NULL */ )
{
	if(column > 7 || column < 0 || row > 7 || row < 0)
		return ChEngn::ListOfPieces();
	ChEngn::VirtualTable tmp = table;
	tmp.pieceAt(column, row)->setType(ChEngn::unknown);
	
	if(whites != NULL)
		return piecesAttacs_helper(tmp, column, row, *whites);
	
	ChEngn::ListOfPieces resWhites = piecesAttacs_helper(tmp, column, row, true);
	ChEngn::ListOfPieces resBlacks = piecesAttacs_helper(tmp, column, row, false);

	if(resBlacks.size() > 0)
		resWhites.insert(resWhites.end(), resBlacks.begin(), resBlacks.end());
	return	resWhites;
}

unsigned short piecesCount_helper( const ChEngn::VirtualTable* table, ChEngn::piece_type type, const bool whites )
{
	unsigned short res = 0;
	for (unsigned int c = 0; c < 8; ++c)
	{
		for(unsigned int r = 0; r < 8; ++r)
		{
			ChEngn::Piece* p = table->pieceAt(c, r);
			if(p == NULL) continue;
			if(p->isUnknown()) continue;
			if(type != ChEngn::unknown && p->type() != type) continue;
			if(p->isBlack() ^ whites)
				++res;
		}
	}
	return res;
}

unsigned short piecesCount( const ChEngn::VirtualTable* table,
							const ChEngn::piece_type type /*= ChEngn::unknown*/,
							const bool* whites /*= NULL*/ )
{
	if(whites != NULL)
		return piecesCount_helper(table, type, *whites);
	return piecesCount_helper(table, type, true) + piecesCount_helper(table, type, false);
}

}
