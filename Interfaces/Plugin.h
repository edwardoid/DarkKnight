#ifndef PLUGIN_H
#define PLUGIN_H

#include "InterfacesGlobal.h"
#include <QObject>
#include "FrameworkUser.h"

class Framework;
class SettingsPageBase;

class EXPORT_INTERFACES Plugin : public QObject,
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
    inline SettingsPageBase* settingsPage() const { return m_settingsPage; }

    virtual ~Plugin() {}
protected:
    SettingsPageBase* m_settingsPage;
};

Q_DECLARE_INTERFACE(Plugin, "ssc.darkknight.plugin")

#endif // PLUGIN_H
