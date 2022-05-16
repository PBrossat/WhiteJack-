#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif 
#include "WinTxt.h"
#include "JeuSolo.h"
#include "MainDeCartes.h"
#include <cassert>

using namespace std;

JeuSolo::JeuSolo():joueurSolo("JoueurSOLO", 0, 2000),unDeck()
{
	unDeck.initDeck();
	unDeck.melangerDeck();
}


void JeuSolo::initialisationMise(const char touche)
{
	joueurSolo.setGain(0);
	switch(touche)
	{
		case 'a' :
			if(joueurSolo.getBudget()>=1) joueurSolo.setMise(1);
			break;

		case 'z' :
			if(joueurSolo.getBudget()>=10) joueurSolo.setMise(10);
			break;

		case 'e' :
			if(joueurSolo.getBudget()>=100) joueurSolo.setMise(100);
			break;

		case 'r' :
			if(joueurSolo.getBudget()>=250) joueurSolo.setMise(250);
			break;

		case 't' :
			if(joueurSolo.getBudget()>=500) joueurSolo.setMise(500);
			break;
	}
}


void JeuSolo::initialisationJeu()
{
	joueurSolo.miser(joueurSolo.getMise());
	Carte carteTiree;
	carteTiree = unDeck.distribuerCarte();
	joueurSolo.mainJoueur.tirerCarte(carteTiree);
	carteTiree = unDeck.distribuerCarte();
	mainCroupier.tirerCarte(carteTiree);
	carteTiree = unDeck.distribuerCarte();
	joueurSolo.mainJoueur.tirerCarte(carteTiree);
	deuxiemeCarteCroupier = unDeck.distribuerCarte();
}


void JeuSolo::finJeu()
{
	joueurSolo.mainJoueur.vider();
	mainCroupier.vider();
	joueurSolo.setMise(0);
	joueurSolo.setGain(0);
}


void JeuSolo::actionClavier(const char touche)
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
			assert((joueurSolo.mainJoueur.getNbCartes()==2) && (joueurSolo.getBudget()>=joueurSolo.getMise()));
			joueurSolo.miser(joueurSolo.getMise());
			joueurSolo.setMise(joueurSolo.getMise()*2);
			Carte carteTiree = unDeck.distribuerCarte();
			joueurSolo.mainJoueur.doubler(carteTiree);
			break;
		}
		case 'r' :
		{
			joueurSolo.mainJoueur.rester();
			break;
		}
		case 'c' :
		{
			assert((joueurSolo.mainJoueur.getNbCartes()==2) && (joueurSolo.getBudget()>=joueurSolo.getMise()));
			assert((joueurSolo.mainJoueur.getIemeCarte(0).getValeur()==joueurSolo.mainJoueur.getIemeCarte(1).getValeur())
			||(joueurSolo.mainJoueur.getIemeCarte(0).getRang()==joueurSolo.mainJoueur.getIemeCarte(1).getRang())); 
			joueurSolo.miser(joueurSolo.getMise());
			joueurSolo.setMise(joueurSolo.getMise()*2);
			Carte carteTiree = unDeck.distribuerCarte();
			joueurSolo.mainJoueur.changeCarte(carteTiree);
			break;
		}
	}
}



void JeuSolo::actionCroupier()
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



unsigned int JeuSolo::resultat() 
{
	if(joueurSolo.mainJoueur.verifBlackJack())
	{
		if(mainCroupier.verifBlackJack())
		{
			joueurSolo.setBudget(joueurSolo.getMise());
			joueurSolo.setGain(joueurSolo.getMise());
			return 1;
		}
		else
		{
			joueurSolo.setBudget((2.5)*joueurSolo.getMise());
			joueurSolo.setGain((2.5)*joueurSolo.getMise());
			return 3;
		}
	}
	else if(!joueurSolo.mainJoueur.getCrame())
	{
		if(mainCroupier.getCrame())
		{
			joueurSolo.setBudget(2*joueurSolo.getMise());
			joueurSolo.setGain(2*joueurSolo.getMise());
			return 2;
		}
		else
		{
			if(joueurSolo.mainJoueur.getSommeValeur() > mainCroupier.getSommeValeur())
			{
				joueurSolo.setBudget(2*joueurSolo.getMise());	
				joueurSolo.setGain(2*joueurSolo.getMise());
				return 2;
			}
			else if(joueurSolo.mainJoueur.getSommeValeur() == mainCroupier.getSommeValeur())
			{
				joueurSolo.setBudget(joueurSolo.getMise());	
				joueurSolo.setGain(joueurSolo.getMise());
				return 1;
			}
			else if(joueurSolo.mainJoueur.getSommeValeur() < mainCroupier.getSommeValeur())
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	
}






void JeuSolo::testRegression() const
{
	cout<<endl;

	JeuSolo unJeu;
	unJeu.initialisationMise('a');
	assert((unJeu.joueurSolo.getGain()==0)&&(unJeu.joueurSolo.getMise()==1));
	unJeu.initialisationMise('z');
	assert((unJeu.joueurSolo.getGain()==0)&&(unJeu.joueurSolo.getMise()==10));
	unJeu.initialisationMise('e');
	assert((unJeu.joueurSolo.getGain()==0)&&(unJeu.joueurSolo.getMise()==100));
	unJeu.initialisationMise('r');
	assert((unJeu.joueurSolo.getGain()==0)&&(unJeu.joueurSolo.getMise()==250));
	unJeu.initialisationMise('t');
	assert((unJeu.joueurSolo.getGain()==0)&&(unJeu.joueurSolo.getMise()==500));
	cout<<"Initialisation de la mise OK"<<endl;


	unJeu.initialisationJeu();
	assert(unJeu.joueurSolo.getBudget()==1500); // budget selon la derniere mise (2000-500)
	assert(unJeu.joueurSolo.mainJoueur.getNbCartes()==2);
	assert(unJeu.mainCroupier.getNbCartes()==1);
	assert(unJeu.deuxiemeCarteCroupier.getValeur()!=0);
	cout<<"Initialisation du jeu OK"<<endl;

	unJeu.actionClavier('d');
	assert (unJeu.joueurSolo.mainJoueur.getNbCartes()==3); // on double donc on pioche une et une seule carte
	assert (unJeu.joueurSolo.mainJoueur.getJoueToujours()==0);
	cout<<"Test de actionClavier(d) OK"<<endl;
	

	unJeu.finJeu();
	assert(unJeu.joueurSolo.mainJoueur.getNbCartes()==0);
	assert(unJeu.mainCroupier.getNbCartes()==0);
	assert((unJeu.joueurSolo.getMise()==0)&&(joueurSolo.getGain()==0));
	cout<<"Fin de jeu OK"<<endl;


	JeuSolo unAutreJeu; //création d'un autre jeu.
	unAutreJeu.initialisationMise('a');//choix d'une mise arbitraire 
	unAutreJeu.initialisationJeu();
	unAutreJeu.actionClavier('t');
	assert (unAutreJeu.joueurSolo.mainJoueur.getNbCartes()==3); // on tire donc on pioche une carte
	unAutreJeu.actionClavier('r');
	assert (unAutreJeu.joueurSolo.mainJoueur.getNbCartes()==3); // le nombre de cartes ne change pas
	assert (unAutreJeu.joueurSolo.mainJoueur.getJoueToujours()==0);
	cout<<"Test de actionCalvier (t) et actionClavier(r) OK"<<endl;


	JeuSolo jeuBlackJack;
	Carte carteAs(1,11,2);
	Carte carte10(10,10,2);
	jeuBlackJack.initialisationMise('e');//choix d'une mise arbitraire (ici 100$)
	jeuBlackJack.joueurSolo.mainJoueur.tirerCarte(carteAs);
	jeuBlackJack.joueurSolo.mainJoueur.tirerCarte(carte10);
	Carte carte1(2,2,2); //création d'une carte random pour le croupier (hors as ou dix)
	Carte caret2(3,3,3);// création d'une carte random pour le croupier (hors as ou dix)
	jeuBlackJack.mainCroupier.tirerCarte(carte1);
	jeuBlackJack.resultat();
	assert (jeuBlackJack.joueurSolo.getGain()==250); //gain = 2,5 fois la mise 
	cout<<"Test résultat sur blackjack OK"<<endl;


	JeuSolo jeu2; //création d'un jeu pour faire les test de resultat()
	Carte carte3(2,2,2);
	Carte carte4(3,3,3);
	jeu2.initialisationMise('e');//choix d'une mise arbitraire (ici 100$)
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte3);//meme main pour le joueur et pour le croupier 
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte4);
	jeu2.mainCroupier.tirerCarte(carte3);
	jeu2.mainCroupier.tirerCarte(carte4);
	jeu2.resultat();
	assert (jeu2.joueurSolo.getGain()==100); //gain = mise
	cout<<"Test résultat sur score identique OK"<<endl;

	jeu2.joueurSolo.mainJoueur.tirerCarte(carte3); //on fait tirer une carte au joueur 
	jeu2.resultat();
	assert (jeu2.joueurSolo.getGain()==200); //gain = 2 fois la mise 
	cout<<"Test résultat sur jeu superieur que croupier OK"<<endl;

	jeu2.joueurSolo.setGain(0); //remise à 0 du gain.
	jeu2.mainCroupier.tirerCarte(carte4); //on fait tirer un nouvelle carte au croupier (carte4>carte3)
	jeu2.resultat();
	assert (jeu2.joueurSolo.getGain()==0); //gain = 0 car score croupier > score joueur
	jeu2.finJeu();//vider jeu2
	cout<<"Test résultat sur jeu inférieur que croupier OK"<<endl;	
	cout<<"Test de resultat() OK"<<endl;

	jeu2.joueurSolo.mainJoueur.tirerCarte(carte3); //on tirer des cartes qui ne fait pas cramer le joueur 
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte4);
	jeu2.mainCroupier.tirerCarte(carte3); //on fait tirer des cartes tel que la somme des valeurs des cartes inferieur à 17
	jeu2.mainCroupier.tirerCarte(carte4);
	jeu2.actionCroupier();
	assert (jeu2.mainCroupier.getNbCartes()>=3); //le croupier tire bien tant que son score est < à 17 et que le joueur n'a pas cramé
	jeu2.finJeu();//vider jeu2
	cout<<"Test de actionCroupier() quand le joueur est toujours en jeu OK"<<endl;
	

	Carte carte5(10,10,1);// création d'une "grosse carte"
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte3); //sommeValeur =2
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte4);//sommeValeur =5
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte5); //sommeValeur=15 	
	jeu2.joueurSolo.mainJoueur.tirerCarte(carte5); //sommeValeur = 25>21 (il a cramé)	
	jeu2.mainCroupier.tirerCarte(carte3);
	jeu2.actionCroupier();
	assert (jeu2.mainCroupier.getNbCartes()==2); //le croupier ne récupère que sa deuxième carte et ne pioche pas car le joueur a cramé
	cout<<"Test de actionCroupier() quand le joueur crame OK"<<endl;
	cout<<"Test de régression passé avec succès"<<endl<<endl;

}
