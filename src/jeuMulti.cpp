﻿#include <vector>
#include <iostream> 
#include "jeuMulti.h"
#include "Joueur.h"
#include "Deck.h"
#include <time.h> 
#include <stdlib.h>
#include <cassert>
using namespace std; 




jeuMulti::jeuMulti ()
{

    unDeck.initDeck();
	unDeck.melangerDeck();
    nbPartie=1;
    
}


jeuMulti::jeuMulti (unsigned int NiveauJoueur)
{

	unDeck.initDeck();
	unDeck.melangerDeck();
    tabJoueur.push_back(Joueur("moi",0,2000));
    tabJoueur.push_back(Joueur("IA1",NiveauJoueur,2000));
    tabJoueur.push_back(Joueur("IA2",NiveauJoueur,2000));
    tabJoueur.push_back(Joueur("IA3",NiveauJoueur,2000));
    nbPartie=1;
}



void jeuMulti::eliminationJoueur() //procédure permettant d'eliminer un joueur si : soit il n'as plus de budget, soit il a le moins d'argent à la partie n={3,6,9}
{
unsigned int nbJoueurs=tabJoueur.size(); // nbJoueur= à la taille du tableau 
    for (unsigned int i=0; i<tabJoueur.size(); i++) //pour i parcourant tout le tableau 
    {
        if(tabJoueur[i].getBudget()==0) // si le joueur à l'indice i à 0 de budget 
        {
            tabJoueur.erase(tabJoueur.begin()+i); //on supprime ce joueur 
            nbJoueurs--; // le nombre de joueur est mis à jour (-1)
        }

    }

    if ( ((nbJoueurs==4)&&(nbPartie==3)) || ((nbJoueurs==3)&&(nbPartie==6))  || ((nbJoueurs==2)&&(nbPartie==9))) //si toute les conditions sont réspectées 
        {
            float min=tabJoueur[0].getBudget(); //initialisation de min à la valeur du budget du joueur d'indice 0 
            unsigned int indiceMinimum=0; // initialisation d'indiceMinimum à l'indice 0 par défaut
            for (unsigned int j=1; j<tabJoueur.size() ; j++) //on commence la boucle à 1 pour eviter de tester avec j=0 (inutile)
                {
                    if (tabJoueur[j].getBudget()<min) //si le budget du joueur d'indice j est inférieur à min 
                        {
                            min= tabJoueur[j].getBudget(); // MAJ de min avec l'indice du joueur 
                            indiceMinimum= j; //MAJ de indiceMinimum avec l'indice du joueur 
                        }
                }
            tabJoueur.erase(tabJoueur.begin()+indiceMinimum); //on supprime le joueur avec le budget le plus bas
            nbJoueurs--; // le nombre de joueur est mis à jour (-1)
        }
    nbPartie++;
}



void jeuMulti::initialisationMiseMulti()
{


    for (unsigned int i=0; i<tabJoueur.size(); i++) //parcours du tableau de joueurs
    {
        tabJoueur[i].setGain(0);//initialisation des gais de tout les joueurs à 0
    }

    vector<unsigned int>misePossible; //création d'un tableau avec les valeurs des mises possibles dedans
    misePossible[0]=100;
    misePossible[1]=200;
    misePossible[2]=300;   
    misePossible[3]=500;
    misePossible[4]=1000;
    srand (time(NULL));
    unsigned int aleatoire = rand() % 5; //on tire un nombre entre 0 et 4 compris qui correspond a l'indice du tab que l'on vient de créer 

	for (unsigned int i=0; i<tabJoueur.size(); i++) //parcours du tableau de joueurs
    {
        if(tabJoueur[i].getNiveau()!=0) //si le niveau du joueur est different de 0 (c'est une IA)
        {
            do
            {
                tabJoueur[i].setMise(misePossible[aleatoire]); //mise aléatoire 
            }while (tabJoueur[i].getBudget()>=tabJoueur[i].getMise()); //tant que c'est possible (par rapport à budget)
        }
        // else Jeu.tabJoueur[i].initialisationMise(touche);               cas du joueur reel (Attention à comment rentrer la mise que l'on veut avec la version graphique)

    }




}





void jeuMulti::initialisationJeuMulti()
{   

    Carte carteTiree;
    for (unsigned int i=0; i<tabJoueur.size(); i++) //distribution d'un carte à chaque joueur 
        {   

            tabJoueur[i].miser(tabJoueur[i].getMise());
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

   	carteTiree = unDeck.distribuerCarte(); //distribution d'une carte au croupier 
	mainCroupier.tirerCarte(carteTiree);

    for (unsigned int i=0; i<tabJoueur.size(); i++) //distribution d'une deuxième carte à chaque joueur 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

     deuxiemeCarteCroupier = unDeck.distribuerCarte(); //création d'une deuxième carte pour le croupier (invisible à cet instant précis)
}



void jeuMulti::testRegression() const
{

    jeuMulti unJeuMultiParDefaut; // création d'un jeu multi par défaut 
    assert (unJeuMultiParDefaut.tabJoueur.size()==0); // taille =0   
    assert(unJeuMultiParDefaut.nbPartie==1);
    Joueur joueurParDefaut; //création d'un joueur par défaut
    unJeuMultiParDefaut.tabJoueur.push_back(joueurParDefaut); //on ajoute ce joueur au jeu
    assert (unJeuMultiParDefaut.tabJoueur.size()==1); // taille =1
    cout<<"Test constructeur par défaut OK"<<endl;
    
    jeuMulti unJeuMulti(3);
    assert (unJeuMulti.tabJoueur.size()==4); // taille =4
    assert (unJeuMulti.tabJoueur[0].nom=="moi"); //test sur le joueur reel
    assert (unJeuMulti.tabJoueur[0].getNiveau() ==0);
    assert (unJeuMulti.tabJoueur[0].getBudget()==2000);
    assert (unJeuMulti.tabJoueur[1].nom=="IA1");
    assert (unJeuMulti.tabJoueur[2].nom=="IA2");
    assert (unJeuMulti.tabJoueur[3].nom=="IA3");
    for (int i=1; i<4; i++) //test sur les IA
    {
    assert (unJeuMulti.tabJoueur[i].getNiveau() ==3);
    assert (unJeuMulti.tabJoueur[i].getBudget()==2000);
    }
    cout<<"Test du constructeur avec paramètre OK"<<endl;


    unJeuMulti.tabJoueur[1].setBudget(-2000);
    unJeuMulti.tabJoueur[2].setBudget(1);
    unJeuMulti.tabJoueur[3].setBudget(2);
    unJeuMulti.eliminationJoueur();
    assert (unJeuMulti.tabJoueur.size()==3);
    for (unsigned int i=0; i<unJeuMulti.tabJoueur.size(); i++)
    {
        cout<<unJeuMulti.tabJoueur[i].nom<<endl;
    }



}
