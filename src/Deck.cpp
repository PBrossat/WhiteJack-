#include <iostream>
#include <vector>
#include <stack>
#include "Deck.h"

using namespace std;

Deck::Deck(unsigned int nombrePaquets)
{
	nbPaquets = nombrePaquets;
 	vector<Carte>tabTemp(nbPaquets*52);
 	for(int i=1; i<=nbPaquets; i++)
 	{
 		for(int k=1; k<=52; k++)
 		{
 			for(int k=0; k<=3; k++)
 			{
 				for(int l=1; l<=10; l++)
 				{
 					tabTemp.push_back(Carte(l,k));
 				}
 			}
 		}
 	}

 	random_device rd;
    default_random_engine rng(rd());
    shuffle(begin(tabTemp), end(tabTemp), rng);

    for(int i=0; i<nbPaquets*52; i++)
    {
    	deck.push(tabTemp[i]);
    }

}

//Toutes les données en privé quasiment --> ce qui intéresse c'est juste les fonctionnalités, ce qu'on peut faire