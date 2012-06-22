#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>
#include "FrameworkUser.h"

class Settings;
class Framework;

class SettingsPage : public QWidget,
                     public FrameworkUser
{
    Q_OBJECT
public:
    explicit SettingsPage(QWidget *parent = 0);
    virtual void readSettings() = 0;
    virtual void writeSettings() = 0;
signals:
    
public slots:

private:
    Framework* m_framework;
    
};

#endif // SETTINGSPAGE_H
