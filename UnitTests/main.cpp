#include <UnitTest++.h>
#include "Primitives_test.h"
#include "FuzzyGoodPawnVariable_test.h"
#include "SimpleCalculations_test.h"
#include "EvaluatingGame_test.h"

int main(int, char**)
{
	int res = UnitTest::RunAllTests();
	
#ifdef _WIN32
	system("pause");
#endif // Wait
	return res;
}