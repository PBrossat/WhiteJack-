#ifndef JEUMULTI_H
#define JEUMULTI_H
#include <iostream>
#include "MainDeCarte.h"
#include "Carte.h"
#include "Deck.h"
#include "Joueur.h"

class JeuMulti{
    public : 

    unsigned int nbPartie;
    vector<Joueur>tabJoueur;
    
    void eliminationJoueur(unsigned int nbPartie);

    void initialisationMiseMulti();

    void initialisationJeuMulti();

    void testRegression() const; 
};
#endif
