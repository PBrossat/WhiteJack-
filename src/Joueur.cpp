#include <iostream>
#include <string.h>
#include "Joueur.h"
#include <cassert>

using namespace std;

Joueur::Joueur(string nomJ, unsigned int nivJoueur, float budgetJ)
{
	nom = nomJ;
	niveauJoueur = nivJoueur;
	budget = budgetJ;
}

bool Joueur::testArgentJoueur()
{
	return (budget>0);
}

void Joueur::testRegression()
{
	Joueur unJoueur("Kirikou", 2, 1000);
	assert(nom=="Kirikou");
	assert(niveauJoueur == 2);
	assert(budget == 1000);
	unJoueur.budget=0;
	assert(budget == 0);
	assert(unJoueur.testArgentJoueur()==0);

	//belleck
}