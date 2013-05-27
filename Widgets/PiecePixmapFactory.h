#ifndef PIECEPIXMAPFACTORY_H
#define PIECEPIXMAPFACTORY_H

#include <QPixmap>
#include <CEPiece.h>
#include <Utils.h>

class PiecePixmapFactory
{
public:
	static inline QPixmap pixmap(CE::Piece* piece)
	{
		if (!piece || piece->isUnknown()) return QPixmap();
		QString pixmapName = QString(":/pieces/%1_").arg((piece->isWhite() ? "white" : "black"));
		switch(piece->type())
		{
		case CE::pawn:
			{
				pixmapName += QString("pawn");
				break;
			}
		case CE::knight:
			{
				pixmapName += QString("knight");
				break;
			}
		case CE::bishop:
			{
				pixmapName += QString("bishop");
				break;
			}
		case CE::rook:
			{
				pixmapName += QString("rook");
				break;
			}
		case CE::queen:
			{
				pixmapName += QString("queen");
				break;
			}
		case CE::king:
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