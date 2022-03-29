#include <iostream>
#include <string.h>
#include "Joueur.h"
#include <cassert>

using namespace std;

Joueur::Joueur(string nomJ, unsigned int nivJoueur, float budgetJ)
{
	assert(budget>0);
	assert(nivJoueur < 4 && nivJoueur >= 0);

	nom = nomJ;
	niveauJoueur = nivJoueur;
	budget = budgetJ;
}

bool Joueur::testArgentJoueur()
{
	return (budget>0);
}


float Joueur::getBudget() const
{
	if(budget>0)
	{
		return budget;
	}
	else
	{
		return 0;
	}
}

void Joueur::setBudget(float gain)
{
	float budgetTemp;
	budgetTemp = budget + gain;

	if(budgetTemp>0)
	{
		budget = budgetTemp;
	}
	else
	{
		budget = 0;
	}
}

void Joueur::testRegression()
{
	Joueur unJoueur("Kirikou", 2, 1000);
	assert(nom=="Kirikou");
	assert(niveauJoueur == 2);
	assert(budget == 1000);
	cout<<"Constructeur avec paramètres OK"<<endl;
	unJoueur.setBudget(-100);
	assert(unJoueur.getBudget() == 900);
	unJoueur.setBudget(-1000);
	assert(unJoueur.getBudget() == 0);
	unJoueur.setBudget(100);
	assert(unJoueur.getBudget() == 100);
	cout<<"Accesseur et mutateurs OK"<<endl;
	assert(unJoueur.testArgentJoueur()==1);
	unJoueur.setBudget(-100);
	assert(unJoueur.testArgentJoueur()==0);
	cout<<"Test Argent OK"<<endl;

	cout<<"Test de regression passé avec succès !"<<endl;
}


