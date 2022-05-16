#include <iostream>
#include <cassert>
#include <vector>
#include "Deck.h"
#include <random>
#include <algorithm>

    

using namespace std;


Deck::~Deck()
{
  deck.clear();
}

void Deck::initDeck()
{
  for(int i=0 ; i<4 ; i++)  //boucle sur le nombre de paquets (ici 4)
  {
    for(int k=1 ; k<=4 ; k++) //boucle sur les signes
    {
      for(int l=1 ; l<=13 ; l++)   //boucle sur le rang (nombre de cartes par signe)
      {
        if(l<=10) //si le rang de la carte est <=10 alors valeur=rang
        {
          Carte card(l,l,k);    //rang,valeur,signe
          deck.push_back(card);
        }
        else  //si le rang est >=10 alors valeur=10
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
    random_device rd; //algorithme de mélange aléatoire
    default_random_engine rng(rd());
    shuffle(deck.begin(), deck.end(), rng);
  }
}



Carte Deck::distribuerCarte()
{
  Carte carteDistribuee;
  if(deck.empty())  //si le deck est vide 
  {
    //on reconstruit un nouveau deck (initialisation + mélange)
    initDeck();
    melangerDeck();
    carteDistribuee = deck.back();
    deck.pop_back();
  }
  else  //le deck n'est pas vide
  {
    carteDistribuee = deck.back();
    deck.pop_back();
  }
  return carteDistribuee;
}


void Deck::testRegression() const
{
  cout<<endl;
  Deck unDeck;
  unDeck.initDeck();
  assert(!unDeck.deck.empty() && unDeck.deck.size()==(4*52));
  cout<<"Deck initialisé OK "<<endl;

  vector<Carte> AvantMelange;
  AvantMelange = unDeck.deck;
  unDeck.melangerDeck();
  bool taille = (unDeck.deck.size()==AvantMelange.size());
  assert(taille);
  bool egaux = ((unDeck.deck[0]==AvantMelange[0]) && (unDeck.deck[1]==AvantMelange[1]) 
  && (unDeck.deck[2]==AvantMelange[2]) && (unDeck.deck[3]==AvantMelange[3]) 
  && (unDeck.deck[4]==AvantMelange[4])); 
  assert(!egaux);
  cout<<"Deck mélangé OK "<<endl;

  Carte test1;
  Carte test2;
  test1 = unDeck.deck.back();
  test2 = unDeck.distribuerCarte();
  assert(test1==test2);
  assert(test1.getSigne()==test2.getSigne());
  assert(unDeck.deck.size()==((4*52)-1));
  cout<<"Distribution de cartes OK"<<endl;



  for(unsigned int i=0; i<=208; i++)
  {
    unDeck.distribuerCarte();
  }
  Carte test3;
  test3 = unDeck.distribuerCarte();
  assert(test3.getValeur()!=0);
  cout<<"Reconstruction d'un deck OK"<<endl;

  cout<<"Le test de regression a été passé avec succès"<<endl<<endl;
}
    
