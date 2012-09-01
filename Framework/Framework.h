#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include "FrameworkGlobal.h"
#include <QCoreApplication>

#define DATASTORES_DIR QCoreApplication::applicationDirPath() + "/datastores"
#define CONCEPTS_DIR QCoreApplication::applicationDirPath() + "/concepts"


class Settings;
class ConceptPlugin;
class DataStore;
class Logger;

typedef QList<DataStore*> DataStoresList;
typedef QList<ConceptPlugin*> ConceptsList;

class FRAMEWORK_EXPORT Framework
{
public:
    static Framework* instance();
    void loadConcepts();
    void loadDataStores();
    void initConcepts();
    void initDataStores();
    Settings* settings() const;
    void setLogger(Logger* logger);
    Logger* logger() const;
	const ConceptPlugin* conceptById(quint32 id) const;
	const DataStore* dataStoreById(quint32 id) const;
    const ConceptsList& concepts() const;
    const DataStoresList& dataStores() const;
private:
    Framework();
private:
    static Framework* m_instance;
    Logger* m_logger;
    Settings* m_settings;
    DataStoresList m_stores;
    ConceptsList m_concepts;
	static quint32 m_idEnumerator;
};

#endif // FRAMEWORK_H
