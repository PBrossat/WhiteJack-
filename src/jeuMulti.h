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


    jeuMulti ();
    
    
    jeuMulti(unsigned int NiveauJoueur);

    /**
    * @brief Le deck du jeu
    */
	Deck unDeck;

    /**
    * @brief Le joueur 
    */
	Joueur joueurSolo; 

    /**
    * @brief La main de carte du croupier
    */
	MainDeCarte mainCroupier;

    /**
    * @brief La deuxième carte du croupier  
    */
	Carte deuxiemeCarteCroupier;
    
    void initialisationNiveau (unsigned int NiveauJoueur);

    void eliminationJoueur(unsigned int nbPartie);

    void initialisationMiseMulti();

    void initialisationJeuMulti();

    void testRegression() const; 
};
#endif
