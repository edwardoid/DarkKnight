#ifndef DATASTORE_H
#define DATASTORE_H

#include "Plugin.h"

class DataStore : public Plugin
{
public:
    explicit DataStore();
    virtual Plugin::Type type() const;
};

#endif // DATASTORE_H
