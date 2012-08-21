#include "DarkKnight.h"
#include "ui_DarkKnight.h"
#include "SettingsDialog.h"
#include "AuthorsDialog.h"
#include "AboutDialog.h"
#include "QueryWizard.h"
#include <QTime>
#include <Utils.h>

DarkKnight::DarkKnight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DarkKnight)
{
    ui->setupUi(this);
}

void DarkKnight::log(const QString &mess)
{
    ui->logTextEdit->appendPlainText(QString("%1: %2").arg(QTime::currentTime().toString(), mess));
}

DarkKnight::~DarkKnight()
{
    delete ui;
}

void DarkKnight::on_actionQuery_triggered()
{
	QueryWizard wizard(this);
	wizard.exec();
}

void DarkKnight::on_actionExit_triggered()
{
    exit(0);
}

void DarkKnight::on_actionAbout_triggered()
{
    AboutDialog dlg(this);
    dlg.exec();
}

void DarkKnight::on_actionAuthors_triggered()
{
    AuthorsDialog dlg(this);
    dlg.exec();
}

void DarkKnight::on_actionSettings_triggered()
{
    SettingsDialog dlg(Framework::instance(), this);
    if(QDialog::Accepted == dlg.exec())
        dlg.writeSettings();
}

void DarkKnight::on_actionAddNewFeatures_triggered()
{

}

void DarkKnight::on_actionCheckForUpdates_triggered()
{

}

void DarkKnight::on_actionQueryEditor_triggered()
{

}

void DarkKnight::on_actionGameExplorer_triggered()
{

}
