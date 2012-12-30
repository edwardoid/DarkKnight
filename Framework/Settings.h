#ifndef SETTINGS_H
#define SETTINGS_H

#include "FrameworkGlobal.h"
#include <QVariant>

class FRAMEWORK_EXPORT Settings
{
public:
	QVariant get(const QString module, const QString parameter, const QVariant defaultValue = QVariant());
	void set(const QString module, const QString paremeter, const QVariant value);
protected:
	Settings();
	friend class Framework;
private:
	class QSettings* m_settings;
};

#endif // SETTINGS_H
