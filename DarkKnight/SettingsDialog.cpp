#include "SettingsDialog.h"
#include "Framework.h"
#include "ConceptPlugin.h"
#include "DataStore.h"
#include "ApplicationSettingsPage.h"
#include "ui_SettingsDialog.h"
#include <SettingsPageBase.h>

SettingsDialog::SettingsDialog(Framework* framework, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    initWithFramework(framework);
	m_appSettings = new ApplicationSettingsPage;
	m_appSettings->initWithFramework(framework);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
	delete m_appSettings;
}

void SettingsDialog::readSettings()
{
	m_appSettings->readSettings();
	ui->settingsTabWidget->addTab(m_appSettings, m_appSettings->name());
	Framework* fw = framework();
    ConceptsList concepts = fw->concepts();
    foreach(ConceptPlugin* c, concepts)
    {
        SettingsPageBase* page = c->settingsPage();
        if(page)
            ui->settingsTabWidget->addTab(page, c->name());
    }

    DataStoresList datastores = fw->dataStores();
    foreach(DataStore* d, datastores)
    {
        SettingsPageBase* page = d->settingsPage();
        if(page)
		{
			page->readSettings();
            ui->settingsTabWidget->addTab(page, d->name());
		}
    }
}

void SettingsDialog::writeSettings()
{
	m_appSettings->writeSettings();
	Framework* fw = framework();
	ConceptsList concepts = fw->concepts();
	foreach(ConceptPlugin* c, concepts)
	{
		SettingsPageBase* page = c->settingsPage();
		if(page)
			page->writeSettings();
	}

	DataStoresList datastores = fw->dataStores();
	foreach(DataStore* d, datastores)
	{
		SettingsPageBase* page = d->settingsPage();
		if(page)
		{
			page->writeSettings();
		}
	}
	ui->settingsTabWidget->clear();
}
