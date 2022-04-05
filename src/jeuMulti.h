#ifndef JEUMULTI_H
#define JEUMULTI_H
#include <iostream>
#include "Jeu.h"

class JeuMulti{
    public : 

    unsigned int nbPartie;
    vector<Joueur>tabJoueur(4);
    
    void eliminationJoueur(unsigned int nbPartie);

 

}