#include "ClassicGoodPawn.h"

ClassicGoodPawn::ClassicGoodPawn()
{

}

ClassicGoodPawn::~ClassicGoodPawn()
{

}

QString ClassicGoodPawn::name() const
{
	return "ClassicGoodPawn";
}

QString ClassicGoodPawn::author() const
{
	return "Edward Sarkisyan";
}

QString ClassicGoodPawn::version() const
{
	return "1.0";
}

Q_EXPORT_PLUGIN2(classicGoodPawn, ClassicGoodPawn)