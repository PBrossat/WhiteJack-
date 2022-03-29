#ifndef JEU_H
#define JEU_H

#include <iostream>
#include "MainDeCarte.h"
#include "Carte.h"
#include "Deck.h"
#include "Joueur.h"

using namespace std;

class Jeu
{
	public :

	unsigned int mise;
	Jeu();
	void actionCroupier();
    void actionClavier(const char touche);
	void initialisation();  
	void resultat(); 


	private :

	Deck unDeck;
	Joueur joueurSolo; 
	MainDeCarte mainCroupier;
	Carte deuxiemeCarteCroupier 

};

#endif