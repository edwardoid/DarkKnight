#include "SettingsPage.h"
#include "ui_SettingsPage.h"
#include "Constants.h"
#include <Framework.h>
#include <Settings.h>
#include <QFileDialog>
#include <QFile>

SettingsPage::SettingsPage(QWidget *parent)
    : SettingsPageBase(parent)
{
	ui = new Ui::SettingsPage();
    ui->setupUi(this);
	connect(ui->browseBttn, SIGNAL(clicked()), this, SLOT(selectDBFile()));
}

void SettingsPage::readSettings()
{
	Settings* s = framework()->settings();
	ui->staticDBFile->setChecked(s->get(PLUGIN_NAME, USE_STATIC_DB, false).toBool());
	ui->staticDbFileLineEdit->setText(s->get(PLUGIN_NAME, STATIC_DB_FILE_PATH, QString()).toString());
	if(!QFile::exists(ui->staticDbFileLineEdit->text()))
		ui->staticDBFile->setChecked(false);
}

void SettingsPage::writeSettings()
{
	Settings* s = framework()->settings();
	s->set(PLUGIN_NAME, USE_STATIC_DB, ui->staticDBFile->isChecked());
	s->set(PLUGIN_NAME, STATIC_DB_FILE_PATH, ui->staticDbFileLineEdit->text());
}

void SettingsPage::selectDBFile()
{
	QString dbFile = QFileDialog::getOpenFileName(this, tr("Select database file"), QDir::homePath(), tr("PGN games (*.pgn)"));
	if(QFile::exists(dbFile))
	{
		ui->staticDbFileLineEdit->setText(dbFile);
	}
}
