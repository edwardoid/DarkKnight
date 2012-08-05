#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include "FrameworkUser.h"

class Framework;
class SettingsPage;

class Plugin : public QObject,
               public FrameworkUser
{
public:
    typedef enum
    {
        Concept = 0,
        DataStore
    } Type;

    virtual Type type() const = 0;
    virtual QString name() const = 0;
    virtual QString version() const = 0;
    virtual QString author() const = 0;
    SettingsPage* settingsPage() const;

    virtual ~Plugin() {}
private:
    SettingsPage* m_settingsPage;
};

Q_DECLARE_INTERFACE(Plugin, "ssc.darkknight.plugin")

#endif // PLUGIN_H