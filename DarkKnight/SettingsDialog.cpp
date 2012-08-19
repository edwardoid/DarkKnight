#include "SettingsDialog.h"
#include "Framework.h"
#include "Concept.h"
#include "DataStore.h"
#include "ui_SettingsDialog.h"
#include <SettingsPageBase.h>

SettingsDialog::SettingsDialog(Framework* framework, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    initWithFramework(framework);
	readSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::readSettings()
{
    Framework* fw = framework();
    ConceptsList concepts = fw->concepts();
    foreach(Concept* c, concepts)
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
            ui->settingsTabWidget->addTab(page, d->name());
    }
}

void SettingsDialog::writeSettings()
{

}
