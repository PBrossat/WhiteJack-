#ifndef MENUSFML_H
#define MENUSFML_H
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jeu.h"
using namespace std;
using namespace sf;

#define Max_menu_principal 3

class Menu 
{

public :

    Menu(float longueur, float largeur);
    ~Menu();
    void dessiner (RenderWindow& window);
    void monter();
    void descendre();

    int menuPrincipalAppuyer()
    {
        return menuPrincipalSelection;
    }
 

private :

    int menuPrincipalSelection;
    Font police;
    Text menu[Max_menu_principal];


};
#endif