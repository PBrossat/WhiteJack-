#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Carte.h"
#include <vector>

using namespace std;

class Deck
{
	public :

	vector<Carte> deck;  
	
	void initDeck();
	void melangerDeck();
	void testRegression() const;

	void afficherDeck() const;

	private :

	unsigned int nbPaquets;
};

#endif