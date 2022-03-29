#include <iostream>
#include <cassert>
#include "Jeu.h"
#include "MainDeCarte.h"
Using namespace std; 

void txtBoucle (jeu & jeu)
{


char nomJoueur;
unsigned int choixJoueur;
unsigned int mise;

//cout<<"Bonjour à vous, veuillez tout d'abord nous indiquer votre nom de joueur : "<<endl; 
//cin>>nomJoueur;

//cout<<"Bienvenue "<<nomJoueur<<"  !! "<<endl;

cout<<"Prenez place sur notre table. Vous jouerez contre Gérard notre meilleur croupier."<<endl;
cout<<"Vous avez actuellement 2000$ de budget, prenez en soins !"<<endl;

do
{   cout<<"Combien voulez miser pour cette manche ?"<<endl;
    cin>>mise;
}
while(mise>2000);



jeu.distribution();

cout<<"Votre main est la suivante :  "<<afficherMainDeCarte(mainJoueur)<<endl; 
cout<<"La main de Gérard est la suivant "<<afficherMainDeCarte(mainCroupier)<<endl;

if (verifBlackJack())
    {
        cout<<"BRAVO vous avez un BlackJack, votre mise est multiplié par 2,5"<<endl;
        mise=mise*2,5;
        cout<<"Vous avez maintenant  "<<budget+mise  <<"$ de budget"
    }



cout<<"Vous pouvez actuellement : rester, tirer ou doubler." <<endl;
cout<<"Pour rester, appuyer sur la touche R de votre clavier"<<endl;
cout<<"Pour tirer, appuyer sur la touche T de votre clavier"<<endl;
cout<<"Pour doubler, appuyer sur la touche D de votre clavier"<<endl;

















