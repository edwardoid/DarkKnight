#include "FilesystemPlugin.h"
#include <SettingsPageBase.h>
#include "SettingsPage.h"

#include <PGNSquare.h>

FilesystemStore::FilesystemStore()
{
    m_settingsPage = new SettingsPage(0);

	pgn::Square f;
	//ChEngn::RookMove rm(0, true);
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

bool FilesystemStore::open()
{

	return false;
}

Q_EXPORT_PLUGIN2(filesystemStore, FilesystemStore)
