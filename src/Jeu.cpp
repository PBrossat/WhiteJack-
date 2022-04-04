#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"
#include "Jeu.h"
#include "MainDeCarte.h"
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
	assert(unJeu.joueurSolo.getBudget()==1000); // budget selon la derniere mise (2000-1000)
	assert(unJeu.joueurSolo.mainJoueur.getNbCartes()==2);
	assert(unJeu.mainCroupier.getNbCartes()==1);
	assert(unJeu.deuxiemeCarteCroupier.getValeur()!=0);
	cout<<"Initialisation du jeu OK"<<endl;

	unJeu.actionClavier('d');
	assert (unJeu.joueurSolo.mainJoueur.getNbCartes()==3); // on double donc on pioche une et une seule carte
	cout<<"Test de actionClavier(d) OK"<<endl;
	unJeu.finJeu();
	assert(unJeu.joueurSolo.mainJoueur.getNbCartes()==0);
	assert(unJeu.mainCroupier.getNbCartes()==0);
	assert((unJeu.mise==0)&&(unJeu.gain==0));


	Jeu unAutreJeu; //création d'un autre jeu.
	unAutreJeu.initialisationMise('a');//choix d'une mise arbitraire 
	unAutreJeu.initialisationJeu();
	unAutreJeu.actionClavier('t');
	assert (unAutreJeu.joueurSolo.mainJoueur.getNbCartes()==3); // on tire donc on pioche une carte
	unAutreJeu.actionClavier('r');
	assert (unAutreJeu.joueurSolo.mainJoueur.getNbCartes()==3); // le nombre de cartes ne change pas
	cout<<"Test de actionCalvier (t) et actionClavier(r) OK"<<endl;


	unAutreJeu.finJeu();
	assert(unJeu.joueurSolo.mainJoueur.getNbCartes()==0);
	assert(unJeu.mainCroupier.getNbCartes()==0);
	assert((unJeu.mise==0)&&(unJeu.gain==0));
	cout<<"Fin de jeu OK"<<endl;


	Jeu jeuBlackJack;
	Carte carteAs(1,11,2);
	Carte carte10(10,10,2);
	jeuBlackJack.initialisationMise('a');//choix d'une mise arbitraire 	
	jeuBlackJack.joueurSolo.mainJoueur.tirerCarte(carteAs);
	jeuBlackJack.joueurSolo.mainJoueur.tirerCarte(carte10);
	Carte carte1(2,2,2); //création d'une carte random pour le croupier (hors as ou dix)
	Carte caret2(3,3,3);// création d'une carte random pour le croupier (hors as ou dix)
	jeuBlackJack.mainCroupier.tirerCarte(carte1);
	jeuBlackJack.resultat();
	assert (jeuBlackJack.gain==250);
	cout<<"Test mise sur blackjack OK"<<endl;


	Jeu jeu2; //création d'un jeu pour faire les test de resultat()
	Carte carte3(2,2,2);
	Carte carte4(3,3,3);
	jeu2.initialisationMise('a');//choix d'une mise arbitraire 	
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte3);//meme main pour le joueur et pour le croupier 
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte4);
	jeu2.mainCroupier.tirerCarte(carte3);
	jeu2.mainCroupier.tirerCarte(carte4);
	jeu2.resultat();
	assert (jeu2.gain==100);
	cout<<"Test mise sur jeu identique OK"<<endl;

	jeu2.joueurSolo.mainJoueur.tirerCarte(carte3); //on fait tirer une carte au joueur 
	jeu2.resultat();
	assert (jeu2.gain==200);
	cout<<"Test mise sur jeu superieur que croupier OK"<<endl;

	jeu2.gain=0; //remise à 0 du gain.
	jeu2.mainCroupier.tirerCarte(carte4); //on fait tirer un nouvelle carte au croupier (carte4>carte3)
	jeu2.resultat();
	assert (jeu2.gain==0);
	jeu2.finJeu();//vider jeu2
	cout<<"Test mise sur jeu inférieur que croupier OK"<<endl;	
	cout<<"Test de resultat() OK"<<endl;

	jeu2.joueurSolo.mainJoueur.tirerCarte(carte3); //on tirer des cartes qui ne fait pas cramer le joueur 
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte4);
	jeu2.mainCroupier.tirerCarte(carte3); //on fait tirer des cartes tel que la somme des valeurs des cartes inferieur à 17
	jeu2.mainCroupier.tirerCarte(carte4);
	jeu2.actionCroupier();
	assert (jeu2.mainCroupier.getNbCartes()>=3);
	jeu2.finJeu();//vider jeu2
	cout<<"Test de actionCroupier() quand le joueur est toujours en jeu OK"<<endl;
	

	Carte carte5(10,10,1);// création d'une "grosse carte"
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte3); //sommeValeur =2
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte4);//sommeValeur =5
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte5); //sommeValeur=15 	
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte5); //sommeValeur = 25>21 (il a cramé)	
	jeu2.mainCroupier.tirerCarte(carte3);
	jeu2.actionCroupier();
	assert (jeu2.mainCroupier.getNbCartes()==2);
	cout<<"Test de actionCroupier() quand le joueur crame OK"<<endl;


	cout<<"Test de régression passé avec succès"<<endl;

}
