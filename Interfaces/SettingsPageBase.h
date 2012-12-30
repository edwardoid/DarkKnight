#ifndef SETTINGSPAGEBASEBASE_H
#define SETTINGSPAGEBASEBASE_H

#include "InterfacesGlobal.h"
#include "FrameworkUser.h"
#include <QWidget>

class Settings;
class Framework;

class EXPORT_INTERFACES SettingsPageBase : public QWidget, public FrameworkUser
{
    Q_OBJECT
public:
    explicit SettingsPageBase(QWidget *parent = 0);
	~SettingsPageBase() {
	}
    virtual void readSettings() = 0;
    virtual void writeSettings() = 0;
};

#endif // SETTINGSPAGEBASEBASE_H
