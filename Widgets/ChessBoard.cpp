#include "ChessBoard.h"
#include <QPainter>
#include <QPaintEvent>

ChessBoard::ChessBoard(QWidget *parent) :
    QWidget(parent)
{
}

ChessBoard::~ChessBoard()
{

}

void ChessBoard::paintEvent(QPaintEvent *e)
{
    const int boardSize = qMin(height(), width());
    const int pieceSize = boardSize / 9;
    QPainter p(this);
    paintTable(p, pieceSize);
    paintNumbers(p, pieceSize);
    paintLetters(p, pieceSize);

    float factor = pieceSize / p.fontMetrics().width("A");
    if ((factor < 1) || (factor > 1.25))
    {
        QFont f = p.font();
        f.setPointSizeF(f.pointSizeF()*factor);
        p.setFont(f);
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
                           Qt::black);
            }
            else
                p.fillRect(pieceRect,
                           Qt::white);
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
