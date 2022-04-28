#include "MenuSfml.h"
infendf

Menu::MenuPrincipal(float longueur, float largeur )
{
    if (!police.loadFromFile("data/BLACKJAC.ttf"))
    {
        cout<<"pas de police BLACKJAC dans data"<<endl;
    }

    MenuPrincipal[0].setFont(police);
    MenuPrincipal[0].setFillColor(Color::white);
    MenuPrincipal[0].setString ("Mode Solo");
    MenuPrincipal[0].setCharacterSize(70);
    MenuPrincipal[0].setPosition(1200, 100);

    MenuPrincipal[1].setFont(police);
    MenuPrincipal[1].setFillColor(Color::white);
    MenuPrincipal[1].setString ("Mode Multi");
    MenuPrincipal[1].setCharacterSize(70);
    MenuPrincipal[1].setPosition(1200, 200);

    MenuPrincipal[2].setFont(police);
    MenuPrincipal[2].setFillColor(Color::white);
    MenuPrincipal[2].setString ("Règles du jeu");
    MenuPrincipal[2].setCharacterSize(70);
    MenuPrincipal[2].setPosition(1200, 300);

    MenuPrincipal[3].setFont(police);
    MenuPrincipal[3].setFillColor(Color::white);
    MenuPrincipal[3].setString ("Quitter");
    MenuPrincipal[3].setCharacterSize(70);
    MenuPrincipal[3].setPosition(1200, 400);

    MenuPrincipalSelection= -1;
}


Menu::~MenuPrincipal ()
{

}



void Menu::dessiner(RenderWindow & fenetre)
{
    for (unsigned int i=0; i<Max_menu_principal; i++)
    {
        fenetre.dessiner(MenuPrincipal[i]);
    }
}


void Menu::monter()
{
    if (MenuPrincipalSelection-1>=0)
    {
        MenuPrincipal[MenuPrincipalSelection].setFillColor(Color::White);
        MenuPrincipalSelection --;
        if (MenuPrincipalSelection ==-1)
        {
            MenuPrincipalSelection=2;
        }
        MenuPrincipal[MenuPrincipalSelection].setFillColor(Color::Red);
    }
}


void Menu::descendre()
{
    if (MenuPrincipalSelection+1<=Max_menu_principal)
    {
        MenuPrincipal[MenuPrincipalSelection].setFillColor(Color::White);
        MenuPrincipalSelection ++;
        if (MenuPrincipalSelection ==4)
        {
            MenuPrincipalSelection=0;
        }
        MenuPrincipal[MenuPrincipalSelection].setFillColor(Color::Red);
    }
}

