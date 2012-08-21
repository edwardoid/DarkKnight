#ifndef CONCEPT_H
#define CONCEPT_H

#include "InterfacesGlobal.h"
#include "Plugin.h"
#include "CalculationResultForGame.h"
#include <PGNGame.h>

class Concept : public Plugin
{
    Q_OBJECT
public:

	typedef enum
	{
		All = 0,
		Whites,
		Blacks
	} Color;
    Concept();
    virtual Plugin::Type type() const;
	virtual CalculationResultForGame calculate(const pgn::Game& game, const Color color) const = 0;
};

#endif // CONCEPT_H
