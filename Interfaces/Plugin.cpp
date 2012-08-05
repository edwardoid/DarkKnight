#include "Plugin.h"

#include <Framework.h>
#include "SettingsPage.h"

SettingsPage* Plugin::settingsPage() const
{
    return m_settingsPage;
}
