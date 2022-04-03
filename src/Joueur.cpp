#include <iostream>
#include <string.h>
#include "Joueur.h"
#include <cassert>

using namespace std;

Joueur::Joueur(string nomJ, unsigned int nivJoueur, float budgetJ)
{
	assert(budgetJ>0);
	assert(nivJoueur < 4 && nivJoueur >= 0);

	nom = nomJ;
	niveauJoueur = nivJoueur;
	budget = budgetJ;
}

bool Joueur::testArgentJoueur() const
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

unsigned int Joueur::getNiveau() const
{
	return niveauJoueur;
}


void Joueur::miser(unsigned int mise)
{
	assert(mise<=budget);
	budget = budget - mise;
}


void Joueur::testRegression() const
{
	cout<<endl;

	Joueur unJoueur("Kirikou", 2, 10000);
	assert(unJoueur.nom=="Kirikou");
	assert(unJoueur.niveauJoueur == 2);
	assert(unJoueur.budget == 10000);
	cout<<"Constructeur avec paramètres OK"<<endl;

	unJoueur.setBudget(-1000);
	assert(unJoueur.budget == 9000);
	unJoueur.setBudget(-10000);
	assert(unJoueur.budget == 0);
	assert(unJoueur.getBudget()==0);
	cout<<"Mutateur de budget OK"<<endl;

	unJoueur.setBudget(100);
	assert(unJoueur.getBudget() == 100);
	unJoueur.miser(50);
	assert(unJoueur.budget == 50 );
	assert(unJoueur.getBudget()==50);
	cout<<"Accesseur de budget OK"<<endl;
	cout<<"Miser OK"<<endl;

	assert(unJoueur.testArgentJoueur()==1);
	unJoueur.setBudget(-50);
	assert(unJoueur.testArgentJoueur()==0);
	cout<<"Test Argent OK"<<endl;

	assert(unJoueur.getNiveau()==2);
	cout<<"Accesseur de niveau OK"<<endl;

	cout<<"Test de regression passé avec succès !"<<endl<<endl;
}


