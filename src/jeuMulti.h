#ifndef JEUMULTI_H
#define JEUMULTI_H
#include <iostream>
#include "MainDeCarte.h"
#include "Carte.h"
#include "Deck.h"
#include "Joueur.h"
#include "Jeu.h"

class jeuMulti{
    public : 

    unsigned int nbPartie;
    
    vector<Joueur>tabJoueur;
    
    void initialisationNiveau (unsigned int NiveauJoueur);

    void eliminationJoueur(unsigned int nbPartie);

    void initialisationMiseMulti();

    void initialisationJeuMulti();

    void testRegression() const; 
};
#endif
