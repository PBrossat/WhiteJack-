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

Carte Deck::distribuerCarte()
{
  Carte carteDistribuee;
  carteDistribuee = deck.back();
  deck.pop_back();
  if(deck.empty())
  {
    initDeck();
    melangerDeck();
  }
  return carteDistribuee;
}


void Deck::testRegression() const
{
  //FAIRE ASSERT AVEC TAILLE DU DECK / VERIFIER VALEUR INIT
    Deck unDeck;
    unDeck.initDeck();
    cout<<"Deck initialisé :"<<endl;
    unDeck.afficherDeck();
    unDeck.melangerDeck();
    cout<<"Deck mélangé :"<<endl;
    unDeck.afficherDeck();
    Carte test;
    test = unDeck.distribuerCarte();
    cout<<test<<endl;
    unDeck.afficherDeck();
    test = unDeck.distribuerCarte();
    cout<<test<<endl;
    unDeck.afficherDeck();

    cout<<"Le test de regression a été passé avec succès"<<endl;
}
    




//Toutes les données en privé quasiment --> ce qui intéresse c'est juste les fonctionnalités, ce qu'on peut faire

//objet en param --> const& objet