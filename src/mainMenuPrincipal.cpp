#include "MenuSfml.h"
#include "jeuSfml.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main (int argc, char** argv)
{
    Menu menu;
	menu.initMenu();
	menu.boucleMenu();
	return 0;
    
    // sf::RenderWindow fenetre (VideoMode(1400,750), "Menu Principal" , Style::Default);
    // Menu menu (fenetre.getSize().x, fenetre.getSize().y);
    // menu.sfmlInit();
    // menu.rsFond.setSize(Vector2f(fenetre.getSize().x, fenetre.getSize().y));
    // fenetre.draw(menu.rsFond);

    // menu.sonAmbiance.play();


    // while (fenetre.isOpen())
    // {
    //     Event evenement; 
    //     while (fenetre.pollEvent(evenement))
    //     {
    //         switch (evenement.type)
    //         {
    //             case sf::Event::KeyReleased:

    //             switch (evenement.key.code)
    //             {
    //                 case sf::Keyboard::Up:
    //                 menu.monter();
    //                 break;

    //                 case sf::Keyboard::Left:
    //                 menu.monter();
    //                 break;

    //                 case sf::Keyboard::Down:
    //                 menu.descendre();
    //                 break;

    //                 case sf::Keyboard::Right:
    //                 menu.descendre();
    //                 break;

    //                 case sf::Keyboard::Return:
    //                 menu.sonAmbiance.stop();
    //                 menu.sonMise.play();
    //                 switch (menu.menuPrincipalAppuyer())
    //                 {
    //                     case 0:
    //                     cout<<"Jeu Solo selectionné"<<endl;
    //                     break;

    //                     case 1:
    //                     cout<<"Jeu Multi selectionné"<<endl;
    //                     break;

    //                     case 2:
    //                     cout<<"Règles selectionné"<<endl;
    //                     break;

    //                 }
    //             }
                

    //             break;
    //             case sf::Event::Closed:
    //             fenetre.close();
    //             break;
    //         }
    //     }

    //     fenetre.clear();
    //     menu.dessiner(fenetre);
    //     fenetre.display();
    // }
}

