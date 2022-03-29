#include <iostream>
#include <cassert>
#include "Jeu.h"
#include "MainDeCarte.h"
Using namespace std; 



char choix;


void jeuTxt::afficherMainDeCarte(MainDeCarte mainJoueur)
{

    int i;
    for (i=0, i<mainJoueur.getNbCarte(), i++)
    {
        cout<<getIemeCarte(i)<<endl;
    }

}



void txtBoucle (jeu & jeu)
{


char nomJoueur;
unsigned int choixJoueur;


cout<<"Prenez place sur notre table. Vous jouerez contre Gérard notre meilleur croupier."<<endl;
cout<<"Vous avez actuellement"<<getBudget()<<"$ de budget, prenez en soins !"<<endl;
cout<<"Combien voulez miser pour cette manche ?"<<endl;


jeu.initialisationMise();
cout<<"Vous avez misé :  "<<mise<<"$"<<endl;
cout<<"Gérard distribue les cartes. "<<endl;


jeu.intialisationJeu();

cout<<"Votre main est la suivante : "<<endl;
afficherMainDeCarte(joueurSolo.mainJoueur);
cout<<"Votre score : "<<joueurSolo.mainJoueur.getSommeValeur()


cout<<"La main du croupier est la suivante : "<<endl;
afficherMainDeCarte(mainCroupier);
cout<<"Score du croupier: "<<mainCroupier.getSommeValeur()




cout<<"Vous pouvez actuellement : rester, tirer ou doubler." <<endl;
cout<<"Pour rester, appuyer sur la touche R de votre clavier"<<endl;
cout<<"Pour tirer, appuyer sur la touche T de votre clavier"<<endl;
cout<<"Pour doubler, appuyer sur la touche D de votre clavier"<<endl;
cout<<endl;

switch (choix)
{
    case 'r':
    
        jeu.actionClavier('r');
        cout<<"vous avez choisi de rester"<<endl;
        cout<<"Votre score ne change pas il est toujours égal à : "<<joueurSolo.mainJoueur.getSommeValeur()<<endl;
    break;

    case 't':
    
        jeu.actionClavier('t');
        cout<<"vous avez choisi de tirer"<<endl;
        cout<<"Voici votre nouvelle main de cartes : "<<endl; 
        afficherMainDeCarte(joueurSolo.mainJoueur)
        cout<<"Votre nouveau score : "<<joueurSolo.mainJoueur.getSommeValeur()
    break;

    case 'd':
    
        jeu.actionClavier('d');
        cout<<"vous avez choisi de doubler"<<endl;
        cout<<"Voici votre nouvelle main de cartes : "<<endl; 
        afficherMainDeCarte(joueurSolo.mainJoueur)
        cout<<"Votre nouveau score : "<<joueurSolo.mainJoueur.getSommeValeur()
     break;
}





switch (choix)
    case 














