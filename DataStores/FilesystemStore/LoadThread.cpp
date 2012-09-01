#include "LoadThread.h"
#include <PGNGameCollection.h>

LoadThread::LoadThread(QObject *parent)
	: QThread(parent)
{

}

LoadThread::~LoadThread()
{

}

void LoadThread::init( QString fileName, pgn::GameCollection* games )
{
	m_fileName = fileName;
	m_games = games;
}

void LoadThread::run()
{

}
