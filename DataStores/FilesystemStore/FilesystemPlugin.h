#ifndef FILESYSTEMPLUGIN_H
#define FILESYSTEMPLUGIN_H

#include <DataStore.h>
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
	bool open();
};

#endif // FILESYSTEMPLUGIN_H
