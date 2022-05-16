#include "JeuSoloSfml.h"

using namespace std;

int main ( int argc, char** argv ) 
{
	JeuSoloSfml jeu;
	jeu.sfmlInit();
	jeu.sfmlAff();
	jeu.sfmlBoucle();
	return 0;
}