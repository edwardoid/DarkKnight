#include "Plugin.h"

#include <Framework.h>
#include "SettingsPage.h"

void Plugin::initWithFramework(Framework *fw)
{
    m_framework = fw;
}

Framework* Plugin::framework() const
{
    return m_framework;
}

SettingsPage* Plugin::settingsPage() const
{
    return m_settingsPage;
}
