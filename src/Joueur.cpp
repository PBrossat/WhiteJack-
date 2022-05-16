#include <iostream>
#include <string.h>
#include "Joueur.h"
#include <cassert>

using namespace std;

Joueur::Joueur()
{
	nom = " ";
	niveauJoueur = 0;
	budget = 0;
	gain=0;
	mise=0;
}



Joueur::Joueur(string nomJ, unsigned int nivJoueur, float budgetJ)
{
	assert(budgetJ>0);
	assert(nivJoueur < 4 && nivJoueur >= 0);

	nom = nomJ;
	niveauJoueur = nivJoueur;
	budget = budgetJ;
	gain=0;
	mise=0;
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



 float Joueur::getGain() const
 {
	 assert(gain>=0);
	return gain; 
 }



void Joueur::setGain(float Gain)
{
	assert (Gain>=0);
	gain=Gain;
}


unsigned int Joueur::getMise() const
{
	return mise;	
}



void Joueur::setMise(unsigned int Mise)
{
	mise=Mise;
}



void Joueur::testRegression() const
{
	cout<<endl;

	Joueur sansParam;
	assert(sansParam.nom==" ");
	assert(sansParam.niveauJoueur == 0);
	assert(sansParam.budget == 0);
	assert(sansParam.gain== 0);
	assert(sansParam.mise == 0);
	cout<<"Constructeur sans paramètres OK"<<endl;

	Joueur unJoueur("Kirikou", 2, 10000);
	assert(unJoueur.nom=="Kirikou");
	assert(unJoueur.niveauJoueur == 2);
	assert(unJoueur.budget == 10000);
	assert(unJoueur.gain== 0);
	assert(unJoueur.mise == 0);
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

	unJoueur.setGain(500);
	assert(unJoueur.getGain()==500);
	unJoueur.setBudget(100);
	unJoueur.setMise(10);
	assert(unJoueur.getMise()==10);	
	cout<<"Accesseur de Gain et Mise OK"<<endl;	

	

	cout<<"Test de regression passé avec succès !"<<endl<<endl;
}



