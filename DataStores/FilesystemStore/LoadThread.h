#ifndef LOADTHREAD_H
#define LOADTHREAD_H

#include <QThread>

namespace pgn
{
	class GameCollection;
}

class LoadThread : public QThread
{
	Q_OBJECT

public:
	LoadThread(QObject *parent);
	~LoadThread();
	void init(QString fileName, pgn::GameCollection* games);
	virtual void run();
	inline pgn::GameCollection* result() const { return m_games; };
private:
	QString m_fileName;
	pgn::GameCollection* m_games;
};

#endif // LOADTHREAD_H
