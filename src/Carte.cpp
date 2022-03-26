#include "MainDeCarte.h"
#include <iostream>
#include <cassert>


Carte::Carte(RANK r, unsigned int Valeur, unsigned int Signe )
{
    valeur=Valeur;
    signe=Signe;
    rang=r;
}

Carte::Carte()
{
    valeur=-1;
    signe=-1;
}

void Carte::testRegression() const
{
    Carte card(Carte::CINQ, 5,2);
    assert(card.valeur==5);
    assert(card.signe==2);
    cout<<card<<endl;
    cout<<"Test regression passé avec succès"<<endl;
}







ostream& operator << (ostream& flux, const Carte& carteAffichee)
{
    flux << "Valeur : "<<carteAffichee.valeur;
    flux << " / Signe : "<<carteAffichee.signe;
    flux << " / Rang : "<<carteAffichee.rang;
    return flux;
}



Carte& Carte::operator = (const Carte& operandeDroite)
{
    valeur = operandeDroite.valeur;
    signe = operandeDroite.signe;
    return *this;
}


