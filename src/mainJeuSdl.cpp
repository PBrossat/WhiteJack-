#include <iostream>
#include "jeuSdl.h"
#include "winTxt.h"

using namespace std;

int main ( int argc, char** argv ) 
{

	Image imCarte;
	imCarte.afficherInit();
	imCarte.afficherBoucle();
	imCarte.afficherDetruit();

	return 0;
}
