#include "MenuSfml.h"
#include "jeuSfml.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main ()
{
    Menu menu;
	menu.initMenu();
	unsigned int res=menu.boucleMenu();
	switch (res)
	{
		case 0:
		break;

		case 1:
		break;

		case 2:
		sf::RenderWindow fenetre (VideoMode(1400,750), "Regle" , Style::Default);
		while (fenetre.isOpen())
		{
    	fenetre.draw(menu.rsRegle);
		}
	}
	return 0;
}

