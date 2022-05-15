#include <iostream>
#include "JeuSoloTxt.h"
#include "WinTxt.h"

using namespace std;

int main ( int argc, char** argv ) 
{
	termClear();
	Jeu jeu;
	txtBoucle(jeu);
	return 0;
}
