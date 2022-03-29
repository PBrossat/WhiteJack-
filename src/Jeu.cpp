#include <iostream>
#include "Jeu.h"
#include <cassert>

using namespace std;

Jeu::Jeu() joueurSolo("JoueurSOLO", 0, 2000) unDeck(), mainJoueurSolo()
{
	unDeck.initDeck();
	unDeck.melangerDeck();
}

void Jeu::actionClavier(const char touche)
{
	switch(touche) {
		case 't' :
			Carte carteTiree = unDeck.distribuerCarte();
			joueurSolo.mainJoueur.tirer(carteTiree);
			break;
		case 'd' :
			Carte carteTiree = unDeck.distribuerCarte();
			joueurSolo.mainJoueur.doubler(carteTiree);
			break;
		case 'r' :
			joueurSolo.mainJoueur.rester();
			break;
	}
}

void Jeu::distribution()
{
	Carte carteTiree;
	Carte carteTiree = unDeck.distribuerCarte();
	joueurSolo.mainJoueur.tirer(carteTiree);
	Carte carteTiree = unDeck.distribuerCarte();
	mainCroupier.tirer(carteTiree);
	Carte carteTiree = unDeck.distribuerCarte();
	joueurSolo.mainJoueur.tirer(carteTiree);
	deuxiemeCarteCroupier = unDeck.distribuerCarte();
}

void Jeu::actionCroupier()
{
	mainCroupier.tirer(deuxiemeCarteCroupier);
	while(mainCroupier.getSommeValeur()<17)
	{
		Carte carteTiree = unDeck.distribuerCarte();
		mainCroupier.tirer(carteTiree);
	}
	mainCroupier.rester();
}

void Jeu::resultat() 
{
	
}