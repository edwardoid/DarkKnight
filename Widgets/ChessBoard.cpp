#include "ChessBoard.h"
#include "TooltipWidget.h"
#include "PiecePixmapFactory.h"
#include <QPainter>
#include <QPaintEvent>
#include <QToolTip>
#include <qxttooltip.h>
#include <QLabel>
#include <CEEngine.h>
#include <Utils.h>
#include <Framework.h>
#include <ConceptPlugin.h>

const QColor ChessBoard::whiteSquareColor(255, 250, 230);
const QColor ChessBoard::blackSquareColor(90, 45, 0);


ChessBoard::ChessBoard(QWidget *parent)
	: QWidget(parent)
	, m_currentMoveIndex(0)
	, m_cache(NULL)
	, m_tooltipWidget(new TooltipWidget(this))
{
	m_tooltipWidget->hide();
	setMouseTracking(true);
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
	CE::VirtualTable table = (m_currentMoveIndex < m_tables.size() ? m_tables[m_currentMoveIndex] : CE::VirtualTable());
	int x = 0;
	int y = 0;
	for(char c = 'a'; c <= 'h'; ++c)
	{
		x += pieceSize;
		y = 7 * pieceSize;
		for(char r = '1'; r <= '8'; ++r, y-= pieceSize)
		{
			CE::Piece* piece = table.pieceAtC(c, r);
			
			QPixmap pixmap = PiecePixmapFactory::pixmap(piece);
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
                   QChar('8' - c));
    }
}

void ChessBoard::paintLetters(QPainter &p, const int pieceSize)
{
    int y = pieceSize * 8;
    for(int r = 0; r < 8; ++r)
    {
        p.drawText(QRect(r * pieceSize + pieceSize,
                         y,
                         pieceSize,
                         pieceSize),
                   Qt::AlignCenter,
                   QChar('A' + r));
    }
}

void ChessBoard::setGame( pgn::Game& game )
{
	m_currentMoveIndex = 0;
	CE::Engine engine(game);
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

void ChessBoard::mouseMoveEvent( QMouseEvent *e )
{
	if(m_cache != NULL)
	{
		const QPoint& p = e->pos();
		const int boardSize = qMin(height(), width());
		const int pieceSize = boardSize / 9;
		int num = p.y() / pieceSize;
		int letter = p.x() / pieceSize - 1;
		if (letter > -1 && letter < 8 && num > -1 && num < 8 && m_tables.size() > m_currentMoveIndex)
		{
			short col = letter;
			short row = 7 - num;
			
			if(m_cache != NULL)
			{
				QList<ConceptCalculationsCache::ID> concepts = m_cache->cachedConcepts();
				QStringList values;
				foreach(ConceptCalculationsCache::ID id, concepts)
				{
					const QString conceptName = Framework::instance()->conceptById(id)->name();
					CalculationResultForGame* gameResult = m_cache->result(id);
					if(gameResult->size() <= m_currentMoveIndex)
						continue;
					const CalculationResultForTable& tableResults = gameResult->tableAt(m_currentMoveIndex);
					const CalculationResultForSquare& squareResultW = tableResults.squareValue(CalculationResultForTable::Whites,col, row);
					if(!squareResultW.undefined() && !squareResultW.textValue().isEmpty())
					{
						values << QString("<b>%1</b>: %2").arg(conceptName, squareResultW.textValue());
						continue;
					}
					
					const CalculationResultForSquare& squareResultB = tableResults.squareValue(CalculationResultForTable::Blacks,col, row);
					if(!squareResultB.undefined() && !squareResultB.textValue().isEmpty())
						values << QString("<b>%1</b>: %2").arg(conceptName, squareResultB.textValue());
				}
				m_tooltipWidget->setText(values.join("</p>"));
			}
			QPixmap piece = PiecePixmapFactory::pixmap(m_tables[m_currentMoveIndex].pieceAt(col, row));
			if(piece.isNull())
				m_tooltipWidget->setSquare(QString("%1%2").arg(QChar('a' + letter)).arg(8 - num));
			else
				m_tooltipWidget->setPixmap(piece);
			QRect r(letter * pieceSize + pieceSize, num * pieceSize, pieceSize, pieceSize);
			QxtToolTip::show(e->globalPos(), m_tooltipWidget, this, r);
			return;
		}
	}
	QWidget::mouseMoveEvent(e);
}
