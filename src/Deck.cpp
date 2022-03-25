#include <iostream>
#include <cassert>
#include <vector>
#include "Deck.h"
#include <random>
#include <algorithm>

    

using namespace std;


void Deck::initDeck()
{
  for(int i=0 ; i<1 ; i++)
  {
    for(int k=0 ; k<4 ; k++)
    {
      for(int l=1 ; l<11 ; l++)   //ATTENTION CAS DE L'AS
      {
         Carte card(l,k);
         deck.push_back(card);
      }
    }
  }
}

void Deck::melangerDeck()
{
  random_device rd;
  default_random_engine rng(rd());
  shuffle(deck.begin(), deck.end(), rng);
}



void Deck::afficherDeck() const
{
  for (int i = 0; i < deck.size(); i++) 
  {
    cout << deck[i] << "; ";
  }
    cout << endl;
}



void Deck::testRegression() const
{
    Deck unDeck;
    unDeck.initDeck();
    cout<<"Deck initialisé :"<<endl;
    unDeck.afficherDeck();
    unDeck.melangerDeck();
    cout<<"Deck mélangé :"<<endl;
    unDeck.afficherDeck();
}
    




//Toutes les données en privé quasiment --> ce qui intéresse c'est juste les fonctionnalités, ce qu'on peut faire

//objet en param --> const& objet