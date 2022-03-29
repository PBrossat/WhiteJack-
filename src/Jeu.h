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

	Jeu();
	void boucleJeu ();
    void actionClavier(const char touche);
	void distribution();   


	private :

	Deck unDeck;
	Joueur joueurSolo; 
	MainDeCarte mainJoueurSolo;
	MainDeCarte mainCroupier;
	Carte deuxiemeCarteCroupier 

};

#endif