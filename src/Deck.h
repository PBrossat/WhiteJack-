#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <stack>
#include "Carte.h"
#include <list>

using namespace std;

class Deck
{
	public :

	stack<Carte> i;  
	unsigned int getNbPaquets();
	Deck(unsigned int nombrePaquets);

	private :

	unsigned int nbPaquets;
};

#endif