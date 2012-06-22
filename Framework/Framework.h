#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#define DATASTORES_DIR "datastores"

#include <QMap>

class Settings;
class Concept;
class DataStore;

typedef QMap<QString, DataStore*> DataStoresList;
typedef QMap<QString, Concept*> ConceptsList;

class Framework
{
public:
    static Framework* instance();
    Settings* settings() const;
private:
    Framework();
private:
    static Framework* m_instance;
    Settings* m_settings;
    DataStoresList m_stores;
    ConceptsList m_concepts;
};

#endif // FRAMEWORK_H
