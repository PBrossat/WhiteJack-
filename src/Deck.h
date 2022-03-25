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
	Carte distribuerCarte();
	void afficherDeck() const;

	void testRegression() const;

	private :


};

#endif

