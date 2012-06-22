#ifndef DATASTORE_H
#define DATASTORE_H

#include "Plugin.h"

class DataStore : public Plugin
{
    Q_OBJECT
public:
    explicit DataStore();
    virtual Plugin::Type type() const;
};

#endif // DATASTORE_H
