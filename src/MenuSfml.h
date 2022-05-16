#ifndef _MENUSFML_H
#define _MENUSFML_H
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;


class Menu 
{

    public :

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
        * @brief Procédure permettant de faire tourner la boucle du menu
        * @return void
        * 
        * Exemple d'utilisation :
        * @code
        * unMenu.boucleMenu();
        * @endcode
        */  
        unsigned int boucleMenu();



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



        sf::RectangleShape rsRegle; 


    private :

        sf::RectangleShape rsFond;
        sf::Texture tFond;
        sf::Texture tRegle;
        sf::SoundBuffer m1_soundbuffer;
        sf::SoundBuffer m2_soundbuffer;
        sf::Sound sonMise;
        sf::Sound sonAmbiance;
        //la selection du joueur 
        int menuPrincipalSelection;
        // la police utilisée
        Font police;
        //Tableau représentant le menu
        Text menu[3];


        //Fonction permettant de renvoyer la selection du joueur      
        int menuPrincipalAppuyer()
        {
            return menuPrincipalSelection;
        }



        //Procédure permettant de "descendre" avec les flèches du clavier dans le menu 
        void descendre();



        //Procédure permettant de "monter" avec les flèches du clavier dans le menu 
        void monter();



        //Procédure permettant d'afficher le menu 
        void dessiner (RenderWindow& window)const ;

};
#endif