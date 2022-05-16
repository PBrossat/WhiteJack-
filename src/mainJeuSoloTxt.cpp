#include <iostream>
#include "JeuSoloTxt.h"
#include "WinTxt.h"

using namespace std;

int main ( int argc, char** argv ) 
{
	termClear();
	JeuSolo jeu;
	txtBoucle(jeu);
	return 0;
}
