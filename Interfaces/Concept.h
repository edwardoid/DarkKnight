#ifndef CONCEPT_H
#define CONCEPT_H

#include "Plugin.h"

class Concept : public Plugin
{
    Q_OBJECT
public:
    Concept();
    virtual Plugin::Type type() const;
};

#endif // CONCEPT_H
