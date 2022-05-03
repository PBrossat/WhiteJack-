#include "MenuSfml.h"
#include "jeuSfml.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main ()
{
    Menu menu;
	menu.initMenu();
	menu.boucleMenu();
	return 0;
}

