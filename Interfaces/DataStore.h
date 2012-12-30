#ifndef DATASTORE_H
#define DATASTORE_H

#include "InterfacesGlobal.h"
#include <QtGlobal>
#include <PGNGameCollection.h>
#include <CGSQL.h>
#include "Plugin.h"


BEGIN_CGSQL_NS
	class RootNode;
END_CGSQL_NS

class EXPORT_INTERFACES DataStore : public Plugin
{
	Q_OBJECT
public:
    DataStore();
    virtual Plugin::Type type() const;
	virtual bool load(CGSQL_NS::RootNode* root, pgn::GameCollection& games) const = 0;
};

#endif // DATASTORE_H
