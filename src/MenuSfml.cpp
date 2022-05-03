#include "MenuSfml.h"
#include <iostream>
using namespace std;


Menu::Menu()
{
    if (!police.loadFromFile("data/BLACKJAC.ttf"))
    {
        cout<<"pas de police BLACKJAC dans data"<<endl;
    }

    menu[0].setFont(police);
    menu[0].setFillColor(Color::Red);
    menu[0].setString ("Mode Solo");
    menu[0].setCharacterSize(70);
    menu[0].setPosition(800, 100);

    menu[1].setFont(police);
    menu[1].setFillColor(Color::White);
    menu[1].setString ("Mode Multi");
    menu[1].setCharacterSize(70);
    menu[1].setPosition(800, 300);

    menu[2].setFont(police);
    menu[2].setFillColor(Color::White);
    menu[2].setString ("Regles du jeu");
    menu[2].setCharacterSize(70);
    menu[2].setPosition(800, 500);


    menuPrincipalSelection= 0;
}


Menu :: ~Menu ()
{

}


void Menu::boucleMenu()
{
    sf::RenderWindow fenetre (VideoMode(1400,750), "Menu Principal" , Style::Default);
    rsFond.setSize(Vector2f(fenetre.getSize().x, fenetre.getSize().y));
    fenetre.draw(rsFond);

    sonAmbiance.play();


    while (fenetre.isOpen())
    {
        Event evenement; 
        while (fenetre.pollEvent(evenement))
        {
            switch (evenement.type)
            {
                case sf::Event::KeyReleased:

                switch (evenement.key.code)
                {
                    case sf::Keyboard::Up:
                    monter();
                    break;

                    case sf::Keyboard::Left:
                    monter();
                    break;

                    case sf::Keyboard::Down:
                    descendre();
                    break;

                    case sf::Keyboard::Right:
                    descendre();
                    break;

                    case sf::Keyboard::Return:
                    sonAmbiance.stop();
                    sonMise.play();
                    switch (menuPrincipalAppuyer())
                    {
                        case 0:
                        cout<<"Jeu Solo selectionné"<<endl;
                        break;

                        case 1:
                        cout<<"Jeu Multi selectionné"<<endl;
                        break;

                        case 2:
                        cout<<"Règles selectionné"<<endl;
                        break;

                    }
                }
                

                break;
                case sf::Event::Closed:
                fenetre.close();
                break;
            }
        }

        fenetre.clear();
        dessiner(fenetre);
        fenetre.display();
    }
}


void Menu::dessiner(RenderWindow & fenetre)
{
    fenetre.draw(rsFond);
    for (unsigned int i=0; i<Max_menu_principal; i++)
    {
        fenetre.draw(menu[i]);
    }
}


void Menu::monter()
{
    if (menuPrincipalSelection-1>=0)
    {
        menu[menuPrincipalSelection].setFillColor(Color::White);
        menuPrincipalSelection --;
        menu[menuPrincipalSelection].setFillColor(Color::Red);
    }else if (menuPrincipalSelection==0)
    {

        menu[menuPrincipalSelection].setFillColor(Color::White);
        menuPrincipalSelection=2;
        menu[menuPrincipalSelection].setFillColor(Color::Red);
    }
    
    
}


void Menu::descendre()
{

    if (menuPrincipalSelection+1<Max_menu_principal)
    {
        
        menu[menuPrincipalSelection].setFillColor(Color::White);
        menuPrincipalSelection ++;
        menu[menuPrincipalSelection].setFillColor(Color::Red);
        
    }else if (menuPrincipalSelection==2)
    {
        menu[menuPrincipalSelection].setFillColor(Color::White);  
        menuPrincipalSelection=0;
        menu[menuPrincipalSelection].setFillColor(Color::Red);
    }
    
}


void Menu::initMenu()
{
    if (!tFond.loadFromFile("data/imageMenu.png")) 
    {
        cout << "Error data/imageMenu.png non found" << endl;
    }
    else 
    {
        rsFond.setTexture(&tFond);
    }

    if (!m1_soundbuffer.loadFromFile("data/SonMise.wav")) 
    {
        cout << "Error data/SonMise.wav non found" << endl;
    }
    else {
        sonMise.setBuffer(m1_soundbuffer);

    if (!m2_soundbuffer.loadFromFile("data/sonAmbiance.wav")) 
    {
        cout << "Error data/sonAmbiance.wav non found" << endl;
    }
    else {
        sonAmbiance.setBuffer(m2_soundbuffer);
        sonAmbiance.setLoop(true);
        sonAmbiance.setVolume(50);
    }
    }
}



