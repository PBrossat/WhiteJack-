#include "MainDeCartes.h"
#include <iostream>
#include <cassert>


Carte::Carte(unsigned int Rang, unsigned int Valeur, unsigned int Signe )
{
    assert((Rang>=1)&&(Rang<=13));
    rang=Rang;
    assert((Valeur>=1)&&(Valeur<=11));
    valeur=Valeur;
    assert((Signe>=1)&&(Signe<=4));
    signe=Signe;
}

Carte::Carte()  //initialise les données à 0
{
    rang=0;
    valeur=0;
    signe=0;
}

unsigned int Carte::getRang() const
{
    return rang;
}

unsigned int Carte::getSigne() const
{
    return signe;
}

unsigned int Carte::getValeur() const
{
    return valeur;
}


void Carte::setValeur(unsigned int Valeur)
{
    assert((Valeur>=1)&&(Valeur<=11));
    valeur = Valeur;
}


void Carte::testRegression() const
{
    cout<<endl;
    //Test du constructeur avec paramètres
    Carte card1(5,5,2);
    assert(card1.rang==5);
    assert(card1.valeur==5);
    assert(card1.signe==2);
    cout<<"Constructeur avec paramètres OK"<<endl;
    //Test du constructeur sans paramètres
    Carte card2;
    assert(card2.rang==0);
    assert(card2.valeur==0);
    assert(card2.signe==0);
    cout<<"Constructeur sans paramètres OK"<<endl;
    //Test de l'opérateur =
    card2 = card1;
    assert(card2.rang==5);
    assert(card2.valeur==5);
    assert(card2.signe==2);
    cout<<"Opérateur = OK"<<endl;
    //Test des accesseurs
    assert(card2.getRang()==5);
    assert(card2.getValeur()==5);
    assert(card2.getSigne()==2);
    cout<<"Accesseurs OK"<<endl;
    //Test du mutateur
    Carte card3(1,1,1);
    card3.setValeur(11);
    assert(card3.getValeur()==11);
    cout<<"Mutateur OK"<<endl;
    //Test de l'opérateur ==
    Carte card4(1,11,2);
    assert(card3==card4);
    assert(!(card2==card4));
    cout<<"Opérateur == OK"<<endl;
    cout<<"Test regression passé avec succès"<<endl<<endl;
}


Carte& Carte::operator = (const Carte& operandeDroite)
{
    rang = operandeDroite.rang;
    valeur = operandeDroite.valeur;
    signe = operandeDroite.signe;
    return *this;
}


bool Carte::operator == (const Carte& operandeDroite)
{
   return((rang==operandeDroite.rang)&&(valeur==operandeDroite.valeur));
}









