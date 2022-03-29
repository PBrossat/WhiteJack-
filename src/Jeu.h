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


	private :

	Deck unDeck;
	Joueur joueurSolo; 
	MainDeCarte mainJoueurSolo;
};

#endif