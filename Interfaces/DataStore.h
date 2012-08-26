#ifndef DATASTORE_H
#define DATASTORE_H

#include "InterfacesGlobal.h"
#include <QtGlobal>
#include "Plugin.h"

class EXPORT_INTERFACES DataStore : public Plugin
{
	Q_OBJECT
public:
    explicit DataStore();
    virtual Plugin::Type type() const;
};

#endif // DATASTORE_H
