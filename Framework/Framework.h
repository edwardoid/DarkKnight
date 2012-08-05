#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#define DATASTORES_DIR "datastores"
#define CONCEPTS_DIR "concepts"

#include <QMap>

class Settings;
class Concept;
class DataStore;
class Logger;

typedef QMap<QString, DataStore*> DataStoresList;
typedef QMap<QString, Concept*> ConceptsList;

class Framework
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
};

#endif // FRAMEWORK_H
