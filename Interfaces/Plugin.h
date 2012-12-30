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

	typedef quint32 ID;
	Plugin(): m_settingsPage(NULL) {}
    virtual Type type() const = 0;
    virtual QString name() const = 0;
    virtual QString version() const = 0;
    virtual QString author() const = 0;
    inline SettingsPageBase* settingsPage() const { return m_settingsPage; }
	inline void setId(const ID id) { m_id = id; };
	inline ID id() const { return m_id; };
    virtual ~Plugin() {}
protected:
    SettingsPageBase* m_settingsPage;
	quint32 m_id;
};

Q_DECLARE_INTERFACE(Plugin, "ssc.darkknight.plugin")

#endif // PLUGIN_H
