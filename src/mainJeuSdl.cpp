#include <iostream>
#include "jeuSdl.h"
#include "winTxt.h"

using namespace std;

int main ( int argc, char** argv ) 
{
	sfmlJeu jeu;
	jeu.sfmlInit();
	jeu.sfmlAff();
	return 0;
}
