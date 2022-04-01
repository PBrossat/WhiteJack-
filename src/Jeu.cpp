#include <iostream>
#include "Jeu.h"
#include "MainDeCarte.h"
#include <cassert>

using namespace std;

Jeu::Jeu():joueurSolo("JoueurSOLO", 0, 2000),unDeck()
{
	unDeck.initDeck();
	unDeck.melangerDeck();
}

void Jeu::actionClavier(const char touche)
{
	switch(touche) 
	{
		case 't' :{
			Carte carteTiree = unDeck.distribuerCarte();
			joueurSolo.mainJoueur.tirerCarte(carteTiree);
			break;}
		case 'd' :{
			joueurSolo.miser(mise);
			mise=mise*2;
			Carte carteTiree = unDeck.distribuerCarte();
			joueurSolo.mainJoueur.doubler(carteTiree);
			break;}
		case 'r' :{
			joueurSolo.mainJoueur.rester();
			break;}
	}
}

void Jeu::initialisationMise()
{
	gain = 0;
	do
	{
		cin>>mise;
	}while(mise>joueurSolo.getBudget());
}


void Jeu::initialisationJeu()
{
	joueurSolo.miser(mise);
	Carte carteTiree;
	carteTiree = unDeck.distribuerCarte();
	joueurSolo.mainJoueur.tirerCarte(carteTiree);
	carteTiree = unDeck.distribuerCarte();
	mainCroupier.tirerCarte(carteTiree);
	carteTiree = unDeck.distribuerCarte();
	joueurSolo.mainJoueur.tirerCarte(carteTiree);
	deuxiemeCarteCroupier = unDeck.distribuerCarte();
}

void Jeu::finJeu()
{
	joueurSolo.mainJoueur.vider();
	mainCroupier.vider();
}

void Jeu::actionCroupier()
{
	mainCroupier.tirerCarte(deuxiemeCarteCroupier);
	if(joueurSolo.mainJoueur.getCrame()==0)
	{
		while(mainCroupier.getSommeValeur()<17)
		{
			Carte carteTiree = unDeck.distribuerCarte();
			mainCroupier.tirerCarte(carteTiree);
		}
	}
	mainCroupier.rester();
}



void Jeu::resultat() 
{
	if(joueurSolo.mainJoueur.verifBlackJack())
	{
		if(mainCroupier.verifBlackJack())
		{
			joueurSolo.setBudget(mise);
			gain = mise;
		}
		else
		{
			joueurSolo.setBudget((2.5)*mise);
			gain = (2.5)*mise;
		}
	}
	if(!joueurSolo.mainJoueur.getCrame())
	{
		if(mainCroupier.getCrame())
		{
			joueurSolo.setBudget(2*mise);
			gain = 2*mise;
		}
		else
		{
			if(joueurSolo.mainJoueur.getSommeValeur() > mainCroupier.getSommeValeur())
			{
				joueurSolo.setBudget(2*mise);	
				gain = 2*mise;
			}
			else if(joueurSolo.mainJoueur.getSommeValeur() == mainCroupier.getSommeValeur())
			{
				joueurSolo.setBudget(mise);	
				gain = mise;
			}
		}
	}
}






void Jeu::testRegression() const
{

}