#ifndef MENUSFML_H
#define MENUSFML_H
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#define Max_menu_principal 4

class Menu 
{

public :

    MenuPrincipal(float longueur, float largeur );

    void dessiner (RenderWindow& window);
    void monter();
    void descendre()

    int MenuPrincipalAppuyer()
    {
        return MenuPrincipalSelection;
    }

    ~MenuPrincipal();


private :
    int MenuPrincipalSelection;
    Font police;
    Text texteMenu[Max_main_menu];

};
#endif