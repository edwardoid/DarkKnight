#include "ChessBoard.h"
#include <QPainter>
#include <QPaintEvent>
#include <CEEngine.h>
#include <Utils.h>

const QColor ChessBoard::whiteSquareColor(255, 250, 230);
const QColor ChessBoard::blackSquareColor(90, 45, 0);


ChessBoard::ChessBoard(QWidget *parent)
	: QWidget(parent)
	, m_currentMoveIndex(0)
{
}

ChessBoard::~ChessBoard()
{

}

void ChessBoard::paintEvent(QPaintEvent *)
{
    const int boardSize = qMin(height(), width());
    const int pieceSize = boardSize / 9;
    QPainter p(this);
	p.setRenderHint(QPainter::TextAntialiasing);
    paintTable(p, pieceSize);
	paintPieces(p, pieceSize);

    float factor = (pieceSize - 10) / p.fontMetrics().width("W"); // Hope W is the widest letter :)
    if ((factor < 1) || (factor > 1.25))
    {
        QFont f = p.font();
        f.setPointSizeF(f.pointSizeF()*factor);
        p.setFont(f);
    }

	paintNumbers(p, pieceSize);
	paintLetters(p, pieceSize);
}

void ChessBoard::paintPieces( QPainter& p, const int pieceSize )
{
	ChEngn::VirtualTable table = (m_currentMoveIndex < m_tables.size() ? m_tables[m_currentMoveIndex] : ChEngn::VirtualTable());
	int x = 0;
	int y = 0;
	for(char c = 'a'; c <= 'h'; ++c)
	{
		x += pieceSize;
		y = 7 * pieceSize;
		for(char r = '1'; r <= '8'; ++r, y-= pieceSize)
		{
			ChEngn::Piece* piece = table.pieceAtC(c, r);
			if (!piece || piece->isUnknown()) continue;
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

			QPixmap pixmap(pixmapName);
			if (pixmap.isNull())
				continue;
			
			pixmap = pixmap.scaled(pieceSize, pieceSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
			p.drawPixmap(x, y, pieceSize, pieceSize, pixmap );
		}
		
	}
}

void ChessBoard::paintTable(QPainter& p, const int pieceSize)
{
    for(int c = 0; c < 8; ++c)
        for(int r = 0; r < 8; ++r)
        {
            QRect pieceRect(pieceSize + r * pieceSize,
                            c * pieceSize,
                            pieceSize,
                            pieceSize);
            if((r + c)% 2 == 1)
            {
                p.fillRect(pieceRect,
                           blackSquareColor);
            }
            else
                p.fillRect(pieceRect,
                           whiteSquareColor);
        }
    p.drawRect(QRect(pieceSize, 0, 8 * pieceSize, 8 * pieceSize));

}

void ChessBoard::paintNumbers(QPainter &p, const int pieceSize)
{
    for(int c = 0; c < 8; ++c)
    {
        p.drawText(QRect(0,
                         c * pieceSize,
                         pieceSize,
                         pieceSize),
                   Qt::AlignCenter,
                   QChar('A' + c));
    }
}

void ChessBoard::paintLetters(QPainter &p, const int pieceSize)
{
    int y = pieceSize * 8;
    for(int r = 1; r < 9; ++r)
    {
        p.drawText(QRect(r * pieceSize,
                         y,
                         pieceSize,
                         pieceSize),
                   Qt::AlignCenter,
                   QChar('0' + r));
    }
}

void ChessBoard::setGame( pgn::Game& game )
{
	m_currentMoveIndex = 0;
	ChEngn::Engine engine(game);
	do
	{
		m_tables.push_back(engine.getVirtualTable());
	}
	while(engine.makeNextHalfMove());
}

void ChessBoard::nextMove()
{
	if (nextMoveAvailable())
		setMove(++m_currentMoveIndex);
	else
	{
		setMove(m_tables.size() - 1);
	}
}

void ChessBoard::previousMove()
{
	if (previousMoveAvailable())
		setMove(--m_currentMoveIndex);
	else
		setMove(0);
}

void ChessBoard::setMove( int i )
{
	m_currentMoveIndex = i;
	update();
}
