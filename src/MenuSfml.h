#ifndef MENUSFML_H
#define MENUSFML_H
#pragma once
#include <iostream>
#include "Jeu.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
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
    void sfmlInit();
    sf::RectangleShape rsFond;
    sf::Texture tFond;
    sf::SoundBuffer m1_soundbuffer;
    sf::SoundBuffer m2_soundbuffer;
    sf::Sound sonMise;
    sf::Sound sonAmbiance;


private :

    int menuPrincipalSelection;
    Font police;
    Text menu[Max_menu_principal];


};
#endif