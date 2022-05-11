#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "jeuSfml.h"
#include "MenuSfml.h"
#include "MultiSfml.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class application{
    
    private :

        Menu menu;
        unsigned int choixMenu;
        unsigned int choixRetour;
        sf::Texture tExit;
        sf::Sprite sExit;
    
    public :

        application();
        ~application();
        unsigned int afficherRegles();
        void boucleApplication();

};

#endif