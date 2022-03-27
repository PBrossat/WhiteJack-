#include "MainDeCarte.h"
#include <iostream>
#include <cassert>


Carte::Carte(unsigned int Valeur, unsigned int Signe )
{
    valeur=Valeur;
    signe=Signe;
}

Carte::Carte()
{
    valeur=-1;
    signe=-1;
}

void Carte::testRegression() const
{
    Carte card(5,2);
    assert(card.valeur==5);
    assert(card.signe==2);
    cout<<card<<endl;
    cout<<"Test regression passé avec succès"<<endl;
}







ostream& operator << (ostream& flux, const Carte& carteAffichee)
{
    flux << "Valeur : "<<carteAffichee.valeur;
    //flux << " / Signe : "<<carteAffichee.signe;
    return flux;
}



Carte& Carte::operator = (const Carte& operandeDroite)
{
    valeur = operandeDroite.valeur;
    signe = operandeDroite.signe;
    return *this;
}


