#include "DataStore.h"

DataStore::DataStore()
{
}

Plugin::Type DataStore::type() const
{
    return Plugin::DataStore;
}
