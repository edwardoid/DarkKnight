#ifndef CONCEPTPLUGIN_H
#define CONCEPTPLUGIN_H

#include "InterfacesGlobal.h"
#include <QtGlobal>
#include "Plugin.h"
#include "CalculationResultForGame.h"
#include <PGNGame.h>

#define  CREATE_LING_VALUE(val) (LinguistingValue(val, QObject::tr(val)))

struct EXPORT_INTERFACES LinguistingValue
{
	LinguistingValue(const char* intValue, QString presValue)
	{
		internalValue = intValue;
		presentationValue = presValue;
	}
	const char* internalValue;
	QString presentationValue;
};

typedef QList<LinguistingValue> LinguistingValuesArray;


class EXPORT_INTERFACES ConceptPlugin : public Plugin
{
	Q_OBJECT
public:

	typedef enum
	{
		All = 0,
		Whites,
		Blacks
	} Color;
    ConceptPlugin();
    virtual Plugin::Type type() const;
	virtual const LinguistingValuesArray& availableValues() const = 0;
	virtual CalculationResultForGame calculate(const pgn::Game& game, const Color color) const = 0;
};

#endif // CONCEPTPLUGIN_H
