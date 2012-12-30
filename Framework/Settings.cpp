#include "Settings.h"
#include <Utils.h>
#include <QCoreApplication>
#include <QSettings>

#define ORGANIZATION "SSC"
#define APPLICATION "DarkKnight"

class SettingsGroupRAII
{
public:
	explicit SettingsGroupRAII(QSettings* settings, QString group)
		: m_settings(settings)
	{
		ASSERT(settings != NULL);
		m_settings->beginGroup(group);
	}

	~SettingsGroupRAII()
	{
		m_settings->endGroup();
	}
private:
	QSettings* m_settings;
};

Settings::Settings()
	: m_settings(new QSettings(QSettings::IniFormat, QSettings::UserScope, ORGANIZATION, APPLICATION, QCoreApplication::instance()))
{
}

QVariant Settings::get(const QString module, const QString parameter, const QVariant defaultValue /* = QVariant */)
{
	SettingsGroupRAII raii(m_settings, module);
	return m_settings->value(parameter, defaultValue);
}

void Settings::set(const QString module, const QString paremeter, const QVariant value)
{
	SettingsGroupRAII raii(m_settings, module);
	m_settings->setValue(paremeter, value);
}