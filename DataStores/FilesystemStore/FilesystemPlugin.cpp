#include "FilesystemPlugin.h"
#include <SettingsPageBase.h>
#include <RootNode.h>
#include <ResultNode.h>
#include <PlayerNode.h>
#include <LogicalBase.h>
#include <PGNFile.h>
#include <QFileDialog>
#include <Utils.h>
#include <Framework.h>
#include <Logger.h>
#include "SettingsPage.h"

FilesystemStore::FilesystemStore()
{
    m_settingsPage = new SettingsPage(0);
}

QString FilesystemStore::name() const
{
    return "Filesystem Store";
}

QString FilesystemStore::version() const
{
    return "1.0.0";
}

QString FilesystemStore::author() const
{
    return "Edward Sarkisyan";
}

bool FilesystemStore::load( CGSQL_NS::RootNode* root, pgn::GameCollection& games ) const
{
	QString strFilePath = QFileDialog::getOpenFileName(0,
													   tr("Select PGN file"),
													   qApp->applicationDirPath(),
													   tr("Games in Portable Game Notation (*.pgn)"));
	ASSERT(NULL != root);

	if(strFilePath.isEmpty()) return false;
	
	if(!QFile::exists(strFilePath))
	{
		framework()->logger()->log(tr("File %1 does not exists").arg(strFilePath));
		return false;
	}

	const CGSQL_NS::Body* body = root->body();
	
	pgn::File pgnFile(strFilePath.toAscii().constData());
	pgn::GameCollection allGames = pgnFile.games();
	Framework* fw = framework();
	int gamesSize = allGames.size();
	int currGame = 0;
	for(pgn::GameCollection::iterator it = allGames.begin();
		it != allGames.end();
		++it)
	{
		const pgn::Game& g = (*it);
		if (body->accept(&g))
		{
			games.insert(g);
		}
	}
	return true;
}

Q_EXPORT_PLUGIN2(filesystemStore, FilesystemStore)
