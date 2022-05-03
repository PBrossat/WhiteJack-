#include "MenuSfml.h"
#include <iostream>
using namespace std;


Menu::Menu(float longueur, float largeur )
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
        sonMise.play();
    }else if (menuPrincipalSelection==0)
    {

        menu[menuPrincipalSelection].setFillColor(Color::White);
        menuPrincipalSelection=2;
        menu[menuPrincipalSelection].setFillColor(Color::Red);
        sonMise.play();
    }
    
    
}


void Menu::descendre()
{

    if (menuPrincipalSelection+1<Max_menu_principal)
    {
        
        menu[menuPrincipalSelection].setFillColor(Color::White);
        menuPrincipalSelection ++;
        menu[menuPrincipalSelection].setFillColor(Color::Red);
        sonMise.play();
        
    }else if (menuPrincipalSelection==2)
    {
        menu[menuPrincipalSelection].setFillColor(Color::White);  
        menuPrincipalSelection=0;
        menu[menuPrincipalSelection].setFillColor(Color::Red);
        sonMise.play();
    }
    
}


void Menu::sfmlInit()
{
    if (!tFond.loadFromFile("data/imageMenu.png")) 
    {
        cout << "Error data/imageMenu.png non found" << endl;
    }
    else 
    {
        rsFond.setTexture(&tFond);
    }

    if (!m_soundbuffer.loadFromFile("data/SonMise.wav")) 
    {
        cout << "Error data/SonMise.wav non found" << endl;
    }
    else {
        sonMise.setBuffer(m_soundbuffer);
    }
}




