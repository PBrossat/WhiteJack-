#include "MenuSfml.h"
#include <iostream>
#include "JeuSoloSfml.h"
using namespace std;


Menu::Menu()
{
    if (!police.loadFromFile("data/Casino3D.ttf"))
    {
        cout<<"pas de police Casino3D dans data"<<endl;
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

unsigned int  Menu::boucleMenu()
{
    sf::RenderWindow * fenetre = new RenderWindow(VideoMode(1400,750), "Menu Principal" , Style::Default);
    rsFond.setSize(Vector2f(fenetre->getSize().x, fenetre->getSize().y));
    
    fenetre->draw(rsFond);

    sonAmbiance.play();


    while (fenetre->isOpen())
    {
        Event evenement; 
        while (fenetre->pollEvent(evenement))
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

                        if(menuPrincipalAppuyer()==0) //choix joueur => jeu Solo 
                        {
                            fenetre->close();    //On ferme la fenetre du menu
                            delete fenetre;
                            fenetre=NULL;
                            return 1; // on renvoie 1 
                        }
                        else if(menuPrincipalAppuyer()==1) //choix joueur => jeu Multi 
                        {
                            cout<<"Jeu Multi selectionné"<<endl;
                            fenetre->close();    //On ferme la fenetre du menu
                            delete fenetre;
                            fenetre=NULL;
                            return 2; // on renvoie 2

                        }
                        else if (menuPrincipalAppuyer()==2)  //choix joueur => Regles du jeu 
                        {
                            cout<<"Règles selectionné"<<endl;
                            fenetre->close();    //On ferme la fenetre du menu
                            delete fenetre;
                            fenetre=NULL;
                            return 3; // on renvoie 3
                        }
                    }
                    break;

                case sf::Event::Closed:
                    fenetre->close();
                    return 0;
                    break;
            }
        }

        fenetre->clear();
        dessiner(*fenetre);
        fenetre->display();
    }
}



void Menu::dessiner(RenderWindow & fenetre)const 
{
    fenetre.draw(rsFond);
    for (unsigned int i=0; i<3; i++)
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
    }
    else if (menuPrincipalSelection==0)
    {

        menu[menuPrincipalSelection].setFillColor(Color::White);
        menuPrincipalSelection=2;
        menu[menuPrincipalSelection].setFillColor(Color::Red);
    }
}



void Menu::descendre()
{

    if (menuPrincipalSelection+1<3)
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
    if (!tRegle.loadFromFile("data/Regles.png")) 
    {
        cout << "Error data/Regles.png non found" << endl;
    }
    else 
    {
        rsRegle.setSize(Vector2f(1400,5000));
        rsRegle.setTexture(&tRegle);

    }
    if (!m1_soundbuffer.loadFromFile("data/SonMise.wav")) 
    {
        cout << "Error data/SonMise.wav non found" << endl;
    }
    else 
    {
        sonMise.setBuffer(m1_soundbuffer);
    }
    if (!m2_soundbuffer.loadFromFile("data/sonAmbiance.wav")) 
    {
        cout << "Error data/sonAmbiance.wav non found" << endl;
    }
    else 
    {
        sonAmbiance.setBuffer(m2_soundbuffer);
        sonAmbiance.setLoop(true);
        sonAmbiance.setVolume(50);
    }
}



