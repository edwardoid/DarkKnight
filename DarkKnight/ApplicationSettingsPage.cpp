#include "ApplicationSettingsPage.h"
#include "ui_ApplicationSettingsPage.h"
#include <Framework.h>
#include <Settings.h>
#include <Utils.h>

ApplicationSettingsPage::ApplicationSettingsPage(QWidget* parent /*= NULL*/)
	: SettingsPageBase(parent)
	, ui(new Ui::ApplicationSettingsPage)
{
	ui->setupUi(this);
}


ApplicationSettingsPage::~ApplicationSettingsPage(void)
{
	delete ui;
}

void ApplicationSettingsPage::readSettings()
{
	Settings* settings = framework()->settings();
	ASSERT(settings != NULL);
	const QString mode = settings->get(APP_SETTINGS, APP_QUERY_MODE, APP_QUERY_MODE_BUILDER).toString();
	if(mode == APP_QUERY_MODE_PLAIN_QUERY)
		ui->modeCGSQLRadioBttn->setChecked(true);
	else
		ui->modeBuilderRadioBttn->setChecked(true);
}

void ApplicationSettingsPage::writeSettings()
{
	Settings* settings = framework()->settings();
	ASSERT(settings != NULL);
	if(ui->modeCGSQLRadioBttn->isChecked())
		settings->set(APP_SETTINGS, APP_QUERY_MODE, APP_QUERY_MODE_PLAIN_QUERY);
	else
		settings->set(APP_SETTINGS, APP_QUERY_MODE, APP_QUERY_MODE_BUILDER);
}
