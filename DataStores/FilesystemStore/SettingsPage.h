#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <SettingsPageBase.h>

namespace Ui {
class SettingsPage;
}

class SettingsPage : public SettingsPageBase
{
    Q_OBJECT
public:
    SettingsPage(QWidget* parent = NULL);
    virtual void readSettings();
    virtual void writeSettings();
private slots:
	void selectDBFile();
private:
    Ui::SettingsPage *ui;
};

#endif // SETTINGSPAGE_H
