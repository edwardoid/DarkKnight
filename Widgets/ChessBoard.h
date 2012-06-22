#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>

class QPaintEvent;

class ChessBoard : public QWidget
{
    Q_OBJECT
public:
    explicit ChessBoard(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *e);
    virtual ~ChessBoard();
signals:
    
public slots:

private:
    void paintTable(QPainter& p, const int pieceSize);
    void paintNumbers(QPainter& p, const int pieceSize);
    void paintLetters(QPainter& p, const int pieceSize);
};

#endif // CHESSBOARD_H
