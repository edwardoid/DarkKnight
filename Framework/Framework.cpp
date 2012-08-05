#include "Framework.h"
#include "Settings.h"
#include "PluginLoader.h"

#include <DataStore.h>
#include <Concept.h>
#include <Logger.h>

Framework* Framework::m_instance = NULL;

Framework::Framework()
{
    m_settings = new Settings;
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

void Framework::setLogger(Logger *logger)
{
    m_logger = logger;
}

Logger* Framework::logger() const
{
    return m_logger;
}

const ConceptsList& Framework::concepts() const
{
    return m_concepts;
}

const DataStoresList& Framework::dataStores() const
{
    return m_stores;
}

void Framework::loadConcepts()
{
    m_concepts = PluginLoader<Concept*>::load(CONCEPTS_DIR);
}

void Framework::loadDataStores()
{
    m_stores = PluginLoader<DataStore*>::load(DATASTORES_DIR);
}

void Framework::initConcepts()
{
    ConceptsList::iterator it = m_concepts.begin();
    while(it != m_concepts.end())
    {
        Concept* c = *it;
        c->initWithFramework(this);
        ++it;
    }
}

void Framework::initDataStores()
{
    DataStoresList::iterator it = m_stores.begin();
    while(it != m_stores.end())
    {
        DataStore* s = *it;
        s->initWithFramework(this);
        ++it;
    }
}
