#include "MenuSfml.h"
#include "JeuSoloSfml.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main ()
{
	sf::View view(sf::Vector2f(1400/2.f, 375.f), sf::Vector2f(1400.f, 750.f));

    Menu menu;
	menu.initMenu();
	unsigned int res=menu.boucleMenu();
	switch (res)
	{
		case 1:
		break;

		case 2:
		break;

		case 3:
		sf::RenderWindow * fenetre;
		fenetre = new RenderWindow(VideoMode(1400,750), "Regle" , Style::Default);
		while (fenetre->isOpen())
		{
			Event event; 
        	while (fenetre->pollEvent(event))
        	{
				if (event.type == Event::Closed)   
            		fenetre->close();
				if (event.type == Event::MouseWheelScrolled)
				{
					if(event.mouseWheelScroll.delta<0)
					{
						if(view.getCenter().y < menu.rsRegle.getSize().y-450)
						{
							view.move(0, 100.f);
							fenetre->setView(view);
						}
					}
					else if(event.mouseWheelScroll.delta>0)
					{
						if(view.getCenter().y > 375)
						{
							view.move(0, -100.f);
							fenetre->setView(view);
						}
					}
				}
			}
			fenetre->draw(menu.rsRegle);
			fenetre->display();
		}
	}
	return 0;
}

