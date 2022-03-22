#include <iostream>
#include <string.h>
#include "Joueur.h"

using namespace std;

Joueur::Joueur(string nomJ, unsigned int nivJoueur, float budgetJ)
{
	nom = nomJ;
	niveauJoueur = nivJoueur;
	budget = budgetJ;
}

unsigned int Joueur::getId()
{
	return id;
}

bool Joueur::testArgentJoueur()
{
	return (budget>0);
}

void Joueur::testRegression()
{
	//belleck
}