#ifndef APPLICATION_SETTINGS_PAGE_H
#define APPLICATION_SETTINGS_PAGE_H

#include <SettingsPageBase.h>
#include "ApplicationConstants.h"

namespace Ui
{
	class ApplicationSettingsPage;
}

class ApplicationSettingsPage :
	public SettingsPageBase
{
public:
	ApplicationSettingsPage(QWidget* parent = NULL);
	inline QString name() const { return APP_SETTINGS; }
	virtual ~ApplicationSettingsPage();
	virtual void readSettings();
	virtual void writeSettings();
private:
	Ui::ApplicationSettingsPage *ui;
};

#endif // APPLICATION_SETTINGS_PAGE_H