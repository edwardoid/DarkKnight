#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include <PGNGame.h>
#include <CETable.h>
#include <ConceptCalculationsCache.h>

namespace ChEngn
{
	class Engine;
}

class QPaintEvent;
class TooltipWidget;

class ChessBoard : public QWidget
{
    Q_OBJECT
public:
    explicit ChessBoard(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *e);
    virtual ~ChessBoard();
	void setGame(pgn::Game& game);
	inline void setCache(ConceptCalculationsCache* cache) { m_cache = cache; }
signals:
    
public:
	void nextMove();
	void previousMove();
	void setMove(int i);
	inline bool nextMoveAvailable() const { return ((m_currentMoveIndex + 1) < m_tables.size()) && (m_tables.size() > 0); }
	inline bool previousMoveAvailable() const { return (m_tables.size() > 0) && (m_currentMoveIndex > 0); }
	inline int currentMoveIndex() const { return m_currentMoveIndex; }
protected:
	virtual void mouseMoveEvent(QMouseEvent *e);
private:
	static const QColor whiteSquareColor;
	static const QColor blackSquareColor;
	void paintPieces(QPainter& p, const int pieceSize);
    void paintTable(QPainter& p, const int pieceSize);
    void paintNumbers(QPainter& p, const int pieceSize);
    void paintLetters(QPainter& p, const int pieceSize);
private:
	QVector<ChEngn::VirtualTable> m_tables;
	TooltipWidget* m_tooltipWidget;
	ConceptCalculationsCache* m_cache;
	int m_currentMoveIndex;
};

#endif // CHESSBOARD_H
