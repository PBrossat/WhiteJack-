#include "MultiSfml.h"

using namespace std;

int main (int argc, char** argv) 
{
	sfmlMulti multi;
	multi.sfmlInit();
	multi.sfmlBoucle();
	return 0;
}