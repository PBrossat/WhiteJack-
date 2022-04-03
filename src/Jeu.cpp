#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"
#include "Jeu.h"
#include <cassert>

using namespace std;

Jeu::Jeu():unDeck(),joueurSolo("JoueurSOLO", 0, 2000)
{
	unDeck.initDeck();
	unDeck.melangerDeck();
}


void Jeu::initialisationMise(const char touche)
{
	gain = 0;
	switch(touche)
	{
		case 'a' :
			if(joueurSolo.getBudget()>=100) mise = 100;
			break;

		case 'z' :
			if(joueurSolo.getBudget()>=200) mise = 200;
			break;

		case 'e' :
			if(joueurSolo.getBudget()>=300) mise = 300;
			break;

		case 'r' :
			if(joueurSolo.getBudget()>=500) mise = 500;
			break;

		case 't' :
			if(joueurSolo.getBudget()>=1000) mise = 1000;
			break;
	}
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
	mise=0;
	gain=0;
}


void Jeu::actionClavier(const char touche)
{
	switch(touche) 
	{
		case 't' :
		{
			Carte carteTiree = unDeck.distribuerCarte();
			joueurSolo.mainJoueur.tirerCarte(carteTiree);
			break;
		}
		case 'd' :
		{
			assert((joueurSolo.mainJoueur.getNbCartes()==2) && (joueurSolo.getBudget()>=mise));
			joueurSolo.miser(mise);
			mise=mise*2;
			Carte carteTiree = unDeck.distribuerCarte();
			joueurSolo.mainJoueur.doubler(carteTiree);
			break;
		}
		case 'r' :
		{
			joueurSolo.mainJoueur.rester();
			break;
		}
	}
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
	else if(!joueurSolo.mainJoueur.getCrame())
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
	cout<<endl;

	Jeu unJeu;
	unJeu.initialisationMise('a');
	assert((unJeu.gain==0)&&(unJeu.mise==100));
	unJeu.initialisationMise('z');
	assert((unJeu.gain==0)&&(unJeu.mise==200));
	unJeu.initialisationMise('e');
	assert((unJeu.gain==0)&&(unJeu.mise==300));
	unJeu.initialisationMise('r');
	assert((unJeu.gain==0)&&(unJeu.mise==500));
	unJeu.initialisationMise('t');
	assert((unJeu.gain==0)&&(unJeu.mise==1000));
	cout<<"Initialisation de la mise OK"<<endl;
	unJeu.initialisationJeu();
	assert(unJeu.joueurSolo.getBudget()==1000);
	assert(unJeu.joueurSolo.mainJoueur.getNbCartes()==2);
	assert(unJeu.mainCroupier.getNbCartes()==1);
	assert(unJeu.deuxiemeCarteCroupier.getValeur()!=0);
	cout<<"Initialisation du jeu OK"<<endl;
	unJeu.finJeu();
	assert(unJeu.joueurSolo.mainJoueur.getNbCartes()==0);
	assert(unJeu.mainCroupier.getNbCartes()==0);
	assert((unJeu.mise==0)&&(unJeu.gain==0));
	cout<<"Fin de jeu OK"<<endl<<endl;

}
