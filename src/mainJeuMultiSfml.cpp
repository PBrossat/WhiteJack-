#include "JeuMultiSfml.h"

using namespace std;

int main (int argc, char** argv) 
{
	JeuMultiSfml multi;
	multi.sfmlInit();
	multi.sfmlBoucle();
	return 0;
}