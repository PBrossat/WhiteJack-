#include <iostream>
#include "Carte.h"

using namespace std;

int main()
{
	Carte cardTest(Carte::VALET,10,1);
	cardTest.testRegression();
	return 0;
}