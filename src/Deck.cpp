#include <iostream>
#include <cassert>
#include <vector>
#include "Deck.h"
#include <random>
#include <algorithm>

    

using namespace std;


void Deck::initDeck()
{
  for(int i=0 ; i<4 ; i++)
  {
    for(int k=1 ; k<=4 ; k++)
    {
      for(int l=1 ; l<=13 ; l++)   //ATTENTION CAS DE L'AS
      {
        if(l<=10)
        {
          Carte card(l,l,k);    //rang,valeur,signe
          deck.push_back(card);
        }
        else
        {
          Carte card(l,10,k);    //rang,valeur,signe
          deck.push_back(card);
        }
  
      }
    }
  }
}


void Deck::melangerDeck()
{
  if(!deck.empty())
  {
    random_device rd;
    default_random_engine rng(rd());
    shuffle(deck.begin(), deck.end(), rng);
  }
}



Carte Deck::distribuerCarte()
{
  Carte carteDistribuee;
  if(deck.empty())
  {
    initDeck();
    melangerDeck();
    carteDistribuee = deck.back();
    deck.pop_back();
  }
  else
  {
    carteDistribuee = deck.back();
    deck.pop_back();
  }
  return carteDistribuee;
}


void Deck::testRegression() const
{
    Deck unDeck;
    unDeck.initDeck();
    assert(!unDeck.deck.empty() && unDeck.deck.size()==(4*52));
    cout<<"Deck initialisé OK "<<endl;
    //unDeck.afficherDeck();
    vector<Carte> AvantMelange;
    AvantMelange = unDeck.deck;
    unDeck.melangerDeck();
    bool taille = (unDeck.deck.size()==AvantMelange.size());
    assert(taille);
    bool same = ((unDeck.deck[0]==AvantMelange[0]) && (unDeck.deck[1]==AvantMelange[1]) && (unDeck.deck[2]==AvantMelange[2]) && (unDeck.deck[3]==AvantMelange[3]) && (unDeck.deck[4]==AvantMelange[4])); //POUR L'INSTANT J'AI PAS DE MEILLEURES MOYENS DE TESTER == 
    assert(!same);
    cout<<"Deck mélangé OK "<<endl;
    //unDeck.afficherDeck();
    Carte test1;
    Carte test2;
    test1 = unDeck.deck.back();
    test2 = unDeck.distribuerCarte();
    assert(test1.getRang()==test2.getRang());
    assert(test1.getValeur()==test2.getValeur());
    assert(test1.getSigne()==test2.getSigne());
    assert(unDeck.deck.size()==((4*52)-1));
    cout<<"Distribution de cartes OK"<<endl;
    //unDeck.afficherDeck();

    //TESTER QUAND ON ARRIVE À LA FIN DU DECK ET QU'IL FAUT EN RECREER UN POUR DISTRIBUER

    cout<<"Le test de regression a été passé avec succès"<<endl;
}
    

// À METTRE DANS JEU TXT

void Deck::afficherDeck() const
{
  if(!deck.empty())
  {
    for (int i = 0; i < deck.size(); i++) 
    {
      cout << deck[i] <<endl;
    }
      cout << endl;
  }
}


//Toutes les données en privé quasiment --> ce qui intéresse c'est juste les fonctionnalités, ce qu'on peut faire

//objet en param --> const& objet