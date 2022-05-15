#include "jeuSfml.h"

using namespace std;

int main ( int argc, char** argv ) 
{
	sfmlJeu jeu;
	jeu.sfmlInit();
	jeu.sfmlAff();
	jeu.sfmlBoucle();
	return 0;
}