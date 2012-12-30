#include "DarkKnight.h"
#include "ui_DarkKnight.h"
#include "SettingsDialog.h"
#include "AuthorsDialog.h"
#include "AboutDialog.h"
#include "QueryWizard.h"
#include <QTime>
#include <PGNGameCollection.h>
#include <PGNGame.h>
#include <PGNMoveList.h>
#include <PGNMove.h>
#include <Utils.h>

DarkKnight::DarkKnight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DarkKnight),
	m_settingsDialog(NULL)
{
    ui->setupUi(this);
	m_data.data().initWithFramework(Framework::instance());
	enableContorls(false);
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
	m_data.clear();
	QueryWizard wizard(&m_data, this);
	wizard.exec();
	enableContorls(!m_data.isEmpty());
	updateControlsInfo();
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
	if(m_settingsDialog == NULL)
		m_settingsDialog = new SettingsDialog(Framework::instance(), this);
	m_settingsDialog->readSettings();
    if(QDialog::Accepted == m_settingsDialog->exec())
        m_settingsDialog->writeSettings();
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

void DarkKnight::enableContorls( bool enable )
{
	ui->gamesCombo->clear();
	ui->gamesCombo->setEnabled(enable);
	ui->movesListWidget->clear();
	ui->movesListWidget->setEnabled(enable);
	ui->prevBttn->setEnabled(enable);
	ui->nextBttn->setEnabled(enable);
}

void DarkKnight::updateControlsInfo()
{
	pgn::GameCollection& games = m_data.games();
	for(pgn::GameCollection::iterator it = games.begin();
		it != games.end();
		++it)
	{
		QString label = QString("%1 vs %2").arg((*it).white().c_str(), (*it).black().c_str());
		ui->gamesCombo->addItem(label);
	}
}

void DarkKnight::on_gamesCombo_currentIndexChanged(int index)
{
	ui->movesListWidget->clear();
	if (index < 0) return;
	
	pgn::Game& game = m_data.games()[index];
	const pgn::MoveList& moves = game.moves();
	for (pgn::MoveList::iterator it = moves.begin();
		it != moves.end();
		++it)
	{
		ui->movesListWidget->addItem(new QListWidgetItem(QString::fromStdString(it->toStdString())));
	}
	ui->boardWidget->setGame(game);
	ui->boardWidget->setCache(m_data.data().cache());
}	

void DarkKnight::on_nextBttn_clicked()
{
	ui->movesListWidget->blockSignals(true);
	ui->boardWidget->nextMove();
	ui->movesListWidget->setCurrentRow(ui->boardWidget->currentMoveIndex() / 2  + ui->boardWidget->currentMoveIndex() % 2 - 1);
	ui->movesListWidget->blockSignals(false);
	ui->nextBttn->setEnabled(ui->boardWidget->nextMoveAvailable());
	ui->prevBttn->setEnabled(ui->boardWidget->previousMoveAvailable());
}

void DarkKnight::on_prevBttn_clicked()
{
	ui->boardWidget->previousMove();
	ui->movesListWidget->blockSignals(true);
	ui->movesListWidget->setCurrentRow(ui->boardWidget->currentMoveIndex() / 2  + ui->boardWidget->currentMoveIndex() % 2 - 1);
	ui->movesListWidget->blockSignals(false);
	ui->nextBttn->setEnabled(ui->boardWidget->nextMoveAvailable());
	ui->prevBttn->setEnabled(ui->boardWidget->previousMoveAvailable());
}

void DarkKnight::on_movesListWidget_currentRowChanged(int row)
{
	if(row < 0) return;
	ui->boardWidget->setMove(row * 2);
	ui->nextBttn->setEnabled(ui->boardWidget->nextMoveAvailable());
	ui->prevBttn->setEnabled(ui->boardWidget->previousMoveAvailable());
}
