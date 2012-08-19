#ifndef SETTINGSPAGEBASEBASE_H
#define SETTINGSPAGEBASEBASE_H

#include <QWidget>
#include "FrameworkUser.h"

class Settings;
class Framework;

class SettingsPageBase : public QWidget,
                         public FrameworkUser
{
    Q_OBJECT
public:
    explicit SettingsPageBase(QWidget *parent = 0);
    virtual void readSettings() = 0;
    virtual void writeSettings() = 0;
};

#endif // SETTINGSPAGEBASEBASE_H
