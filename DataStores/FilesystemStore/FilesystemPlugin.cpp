#include "FilesystemPlugin.h"
#include <SettingsPageBase.h>
#include <RootNode.h>
#include <ResultNode.h>
#include <PlayerNode.h>
#include <LogicalBase.h>
#include <PGNFile.h>
#include <QFileDialog>
#include <Utils.h>
#include <CalculationData.h>
#include <Framework.h>
#include <Settings.h>
#include <Logger.h>
#include "SettingsPage.h"
#include "Constants.h"

FilesystemStore::FilesystemStore()
{
    m_settingsPage = new SettingsPage(0);
}

QString FilesystemStore::name() const
{
    return PLUGIN_NAME;
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
	QString strFilePath;
	

	Framework* f = framework();
	Settings* s = f->settings();
	bool bUseStaticDB = s->get(PLUGIN_NAME, USE_STATIC_DB, false).toBool();
	
	if (bUseStaticDB)
	{
		strFilePath = s->get(PLUGIN_NAME, STATIC_DB_FILE_PATH, QString()).toString();
	}

	if(!QFile::exists(strFilePath))
		strFilePath = QFileDialog::getOpenFileName(0,
												   tr("Select PGN file"),
												   QDir::homePath(),
												   tr("Games in Portable Game Notation (*.pgn)"));
	ASSERT(NULL != root);

	if(strFilePath.isEmpty()) return false;
	
	if(!QFile::exists(strFilePath))
	{
		f->logger()->log(tr("File %1 does not exists").arg(strFilePath));
		return false;
	}

	const CGSQL_NS::Body* header = root->header();
	
	pgn::File pgnFile(strFilePath.toAscii().constData());
	pgn::GameCollection allGames = pgnFile.games();
	for(pgn::GameCollection::iterator it = allGames.begin();
		it != allGames.end();
		++it)
	{
		const pgn::Game& g = (*it);
		CalculationData arg(&g);
		if (header->accept(&arg))
		{
			games.insert(g);
		}
	}
	return true;
}

void FilesystemStore::initWithFramework( Framework* fw )
{
	m_settingsPage->initWithFramework(fw);
	DataStore::initWithFramework(fw);
}

Q_EXPORT_PLUGIN2(filesystemStore, FilesystemStore)
