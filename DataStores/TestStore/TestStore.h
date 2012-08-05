#ifndef TESTSTORE_H
#define TESTSTORE_H

#include <DataStore.h>
#include <QtCore/QtPlugin>

class TestStore: public DataStore
{
    Q_OBJECT
    Q_INTERFACES(Plugin)
public:
    TestStore();
    virtual QString name() const;
    virtual QString version() const;
    virtual QString author() const;
};

#endif // TESTSTORE_H
