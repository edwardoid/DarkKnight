#ifndef CLASSICGOODPAWN_H
#define CLASSICGOODPAWN_H

#include <Concept.h>
#include <QtCore/QtPlugin>

class ClassicGoodPawn: public Concept
{
	Q_OBJECT
	Q_INTERFACES(Plugin)
public:
	ClassicGoodPawn();
	virtual ~ClassicGoodPawn();
	virtual QString name() const;
	virtual QString version() const;
	virtual QString author() const;
	bool open();
};

#endif // CLASSICGOODPAWN_H
