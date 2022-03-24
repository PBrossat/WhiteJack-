#include <iostream>
#include <string.h>
#include "Joueur.h"
#include <cassert>

using namespace std;

Joueur::Joueur(string nomJ, unsigned int nivJoueur, float budgetJ)
{
	assert(budget>0);
	assert(nivJoueur < 4 && nivJoueur >= 0)

	nom = nomJ;
	niveauJoueur = nivJoueur;
	budget = budgetJ;
}

bool Joueur::testArgentJoueur()
{
	return (budget>0);
}

void Joueur::ajouterMainDeCartes(MainDeCarte hand)
{
	tabMainDeCartes.push_back(hand);
	nbMainDeCartes++;
}

void Joueur::supprimerMainDeCartes()
{
	if(nbMainDeCartes > 0)
	{
		tabMainDeCartes.pop_back(hand);
		nbMainDeCartes--;
	}
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

	//tester MainDeCartes

	cout<<"Test de regression passé avec succès !"<<endl
}

