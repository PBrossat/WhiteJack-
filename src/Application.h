#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "JeuSoloSfml.h"
#include "MenuSfml.h"
#include "JeuMultiSfml.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Application{
    
    public :

        /**
        * @brief Constructeur d'Application
        * 
        * Exemple d'utilisation :
        * @code
        * Application uneAppli;
        * @endcode
        */
        Application();



        /**
        * @brief Destructeur d'Application.
        */
        ~Application();



        /**
        * @brief Fonction permettant d'afficher les règles du jeu (et retournant un entier afin de gérer la fin de l'affichage)
        * @return unsigned int 
        * 
        * Exemple d'utilisation :
        * @code
        * uneAppli.afficherRegles();
        * @endcode
        */
        unsigned int afficherRegles();



        /**
        * @brief Procédure permettant de gérer l'application
        * @return void 
        * 
        * Exemple d'utilisation :
        * @code
        * uneAppli.boucleApplication();
        * @endcode
        */
        void boucleApplication();



        private :

        Menu menu;
        unsigned int choixMenu;
        unsigned int choixRetour;
        sf::Texture tExit;
        sf::Sprite sExit;

};

#endif