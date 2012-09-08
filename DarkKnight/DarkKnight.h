#ifndef DARKKNIGHT_H
#define DARKKNIGHT_H

#include <QMainWindow>
#include <Logger.h>
#include "QueryResult.h"

namespace Ui {
class DarkKnight;
}

class DarkKnight : public QMainWindow, public Logger
{
    Q_OBJECT
    
public:
    explicit DarkKnight(QWidget *parent = 0);
    virtual ~DarkKnight();
    virtual void log(const QString &mess);
private slots:
    void on_actionQuery_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionAuthors_triggered();

    void on_actionSettings_triggered();

    void on_actionAddNewFeatures_triggered();

    void on_actionCheckForUpdates_triggered();

    void on_actionQueryEditor_triggered();

    void on_actionGameExplorer_triggered();

	void on_gamesCombo_currentIndexChanged(int index);
private:
	void enableContorls(bool enable);
	void updateControlsInfo();
private:
    Ui::DarkKnight *ui;
	QueryResult m_data;
};

#endif // DARKKNIGHT_H
