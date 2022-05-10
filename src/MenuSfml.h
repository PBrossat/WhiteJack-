#ifndef MENUSFML_H
#define MENUSFML_H
#pragma once
#include <iostream>
#include "Jeu.h"
#include "jeuSfml.h"
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

    
    sf::RectangleShape rsFond;
    sf::Texture tFond;
    sf::SoundBuffer m1_soundbuffer;
    sf::SoundBuffer m2_soundbuffer;
    sf::Sound sonMise;
    sf::Sound sonAmbiance;



    /**
    * @brief Constructeur sans paramètres de Menu.
    * 
    * Exemple d'utilisation :
    * @code
    * Menu unMenu;
    * @endcode
    */
    Menu();



    /**
    * @brief Destructeur de Menu.
    */
    ~Menu();



    /**
    * @brief Procédure permettant d'afficher le menu
    * @return void
    * @param[in out] window la fenetre 
    * 
    * Exemple d'utilisation :
    * @code
    * unMenu.dessiner(window);
    * @endcode
    */   
    void dessiner (RenderWindow& window)const ;



    /**
    * @brief Procédure permettant de "monter" avec les flèches du clavier dans le menu
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unMenu.monter();
    * @endcode
    */   
    void monter();



    /**
    * @brief Procédure permettant de "descendre" avec les flèches du clavier dans le menu
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unMenu.descendre();
    * @endcode
    */  
    void descendre();



    /**
    * @brief Procédure permettant de faire tourner la boucle du menu
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unMenu.boucleMenu();
    * @endcode
    */  
    void boucleMenu();


    /**
    * @brief fonction permettant de renvoyer la selection du joueur 
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unMenu.menuPrincipalAppuyer();
    * @endcode
    */      
    int menuPrincipalAppuyer()
    {
        return menuPrincipalSelection;
    }


    /**
    * @brief Procédure permettant d'initialiser toute les images, son et polices utilisées
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unMenu initMenu();
    * @endcode
    */ 
    void initMenu();



private :

    //la selection du joueur 
    int menuPrincipalSelection;

    // la police utilisée
    Font police;


    Text menu[Max_menu_principal];


};
#endif