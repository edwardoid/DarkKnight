#ifndef FILESYSTEMPLUGIN_H
#define FILESYSTEMPLUGIN_H

#include <DataStore.h>
#include <RootNode.h>
#include <QtCore/QtPlugin>

class Q_DECL_EXPORT FilesystemStore: public DataStore
{
    Q_OBJECT
    Q_INTERFACES(Plugin)
public:
    FilesystemStore();
    virtual QString name() const;
    virtual QString version() const;
    virtual QString author() const;
	virtual bool load(CGSQL_NS::RootNode* root, pgn::GameCollection& games) const;
private:
	bool acceptGame(CGSQL_NS::Body* body, const pgn::Game& game) const;
};

#endif // FILESYSTEMPLUGIN_H
