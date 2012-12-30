#include "Framework.h"
#include "Settings.h"
#include "PluginLoader.h"
#include <QProgressBar>
#include <DataStore.h>
#include <ConceptPlugin.h>
#include <Logger.h>

quint32 Framework::m_idEnumerator = 1;
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
    m_concepts = PluginLoader<ConceptPlugin*>::load(CONCEPTS_DIR);
	foreach(ConceptPlugin* c, m_concepts)
	{
		c->setId(++m_idEnumerator);
		c->initWithFramework(this);
	}
}

void Framework::loadDataStores()
{
    m_stores = PluginLoader<DataStore*>::load(DATASTORES_DIR);
	foreach(DataStore* s, m_stores)
	{
		s->setId(++m_idEnumerator);
		s->initWithFramework(this);	
	}
}

void Framework::initConcepts()
{
    ConceptsList::iterator it = m_concepts.begin();
    while(it != m_concepts.end())
    {
        ConceptPlugin* c = *it;
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

const ConceptPlugin* Framework::conceptById(quint32 id) const
{
	foreach(ConceptPlugin* c, m_concepts)
	{
		if (c->id() == id)
		{
			return c;
		}
		
	}
	return NULL;
}

const DataStore* Framework::dataStoreById(quint32 id) const
{
	foreach(DataStore* s, m_stores)
	{
		if (s->id() == id)
		{
			return s;
		}

	}
	return NULL;
}