#ifndef PIECEPIXMAPFACTORY_H
#define PIECEPIXMAPFACTORY_H

#include <QPixmap>
#include <CEPiece.h>
#include <Utils.h>

class PiecePixmapFactory
{
public:
	static inline QPixmap pixmap(ChEngn::Piece* piece)
	{
		if (!piece || piece->isUnknown()) return QPixmap();
		QString pixmapName = QString(":/pieces/%1_").arg((piece->isWhite() ? "white" : "black"));
		switch(piece->type())
		{
		case ChEngn::pawn:
			{
				pixmapName += QString("pawn");
				break;
			}
		case ChEngn::knight:
			{
				pixmapName += QString("knight");
				break;
			}
		case ChEngn::bishop:
			{
				pixmapName += QString("bishop");
				break;
			}
		case ChEngn::rook:
			{
				pixmapName += QString("rook");
				break;
			}
		case ChEngn::queen:
			{
				pixmapName += QString("queen");
				break;
			}
		case ChEngn::king:
			{
				pixmapName += QString("king");
				break;
			}
		default: { ASSERT(false); }
		}

		return QPixmap(pixmapName);
	}
};

#endif // PIECEPIXMAPFACTORY_H