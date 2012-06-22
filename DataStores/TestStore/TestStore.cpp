#include "TestStore.h"


TestStore::TestStore()
{
}

QString TestStore::name() const
{
    return "TestStore";
}

QString TestStore::version() const
{
    return "1.0.0";
}

QString TestStore::author() const
{
    return "Edward Sarkisyan";
}

Q_EXPORT_PLUGIN2(testStore, TestStore)
