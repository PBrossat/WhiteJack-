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

	stack<Carte>deck;  
	// unsigned int getNbPaquets() const;
	// void setNbPaquets(unsigned int nombrePaquets);
	Deck(unsigned int nombrePaquets);
	void testRegression();

	private :

	unsigned int nbPaquets;
};

#endif