#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "FrameworkUser.h"
#include "Framework.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog, public FrameworkUser
{
    Q_OBJECT
    
public:
    explicit SettingsDialog(Framework* fw = Framework::instance(), QWidget *parent = 0);
    ~SettingsDialog();
    void writeSettings();
    void readSettings();
private:
    Ui::SettingsDialog *ui;
	class ApplicationSettingsPage* m_appSettings;
};

#endif // SETTINGSDIALOG_H
