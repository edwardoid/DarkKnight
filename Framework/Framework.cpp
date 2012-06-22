#include "Framework.h"
#include "Settings.h"
#include "PluginLoader.h"

#include <DataStore.h>
#include <Concept.h>

Framework* Framework::m_instance = NULL;

Framework::Framework()
{
    m_settings = new Settings;
    m_stores = PluginLoader<DataStore*>::load(DATASTORES_DIR);
}

Framework* Framework::instance()
{
    if(NULL == m_instance)
        m_instance = new Framework();
    return m_instance;
}

Settings* Framework::settings() const
{
    return m_settings;
}
