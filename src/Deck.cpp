#include <iostream>
#include <cassert>
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
 		for(int j=1; j<=52; j++)
 		{
 			for(int k=0; k<=3; k++)
 			{
 				for(int l=1; l<=10; l++)
 				{
 					tabTemp.push_back(Carte carte(l,k));    //ATTENTION CAS DE L'AS 
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

void Deck::testRegression()
{
    Deck unDeck(2);
    assert(unDeck.deck.size()==104);
    cout << "Nombre d'éléments dans la pile : " << unDeck.deck.size() << endl;

    for(int i=0; i<unDeck.deck.size(); i++)
    {
        cout << unDeck.deck.top() << endl;  // accès au dernier élément
        unDeck.deck.pop();  // suppression du dernier élément
    }
}


// unsigned int Deck::getNbPaquets() const
// {
//     return nbPaquets;
// }

// void Deck::setNbPaquets(unsigned int nombrePaquets)
// {
//     nbPaquets = nombrePaquets;

// }



//Toutes les données en privé quasiment --> ce qui intéresse c'est juste les fonctionnalités, ce qu'on peut faire

//objet en param --> const& objet