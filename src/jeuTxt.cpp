#include <iostream>
#include <cassert>
#include "Jeu.h"
#include "JeuTxt.h"
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



void txtBoucle (Jeu & jeu)
{
    do{
    cout<<"Bonjour, soyez le bienvenue ! Nous verifions votre carte d'identité ... Tout est bon vous êtes bien majeur"<<endl;
    cout<<"Vous pouvez donc maintenant jouer au BlackJack ! Si vous êtes prêt taper O sur votre clavier, sinon tapez N sur votre clavier"<<endl;
    cin>>char veutJouer;
    }while ((veutJouer!='o')||(veutJouer!='n'));

    if (veutJouer=='o')
    {

        cout<<"Prenez place sur notre table. Vous jouerez contre Gérard notre meilleur croupier."<<endl;
        cout<<"Vous avez actuellement"<<getBudget()<<"$ de budget, prenez en soins !"<<endl;
        cout<<"Combien voulez miser pour cette manche ?"<<endl;


        jeu.initialisationMise();
        cout<<"Vous avez misé :  "<<mise<<"$"<<endl;
        cout<<"Gérard distribue les cartes. "<<endl;


        jeu.intialisationJeu();

        cout<<"Votre main est la suivante : "<<endl;
        afficherMainDeCarte(joueurSolo.mainJoueur);
        cout<<"Votre score : "<<joueurSolo.mainJoueur.getSommeValeur()<<endl;


        cout<<"La main du croupier est la suivante : "<<endl;
        afficherMainDeCarte(mainCroupier);
        cout<<"Score du croupier: "<<mainCroupier.getSommeValeur()<<endl;




        cout<<"Vous pouvez actuellement : rester, tirer ou doubler." <<endl;
        cout<<"Pour rester, appuyer sur la touche R de votre clavier"<<endl;
        cout<<"Pour tirer, appuyer sur la touche T de votre clavier"<<endl;
        cout<<"Pour doubler, appuyer sur la touche D de votre clavier"<<endl;
        cout<<endl;

        do
        {
        switch (choix)
        {
            case 'r':
            
                jeu.actionClavier('r');
                cout<<"vous avez choisi de rester"<<endl;
                cout<<"Votre score ne change pas il est toujours égal à : "<<joueurSolo.mainJoueur.getSommeValeur()<<endl;
                cout<<"Au tour du croupier de jouer, bonne chance! "<<endl;
            break;

            case 't':
            
                cout<<"vous avez choisi de tirer"<<endl;
                cout<<"Voici votre nouvelle main de cartes : "<<endl; 
                jeu.actionClavier('t');
                afficherMainDeCarte(joueurSolo.mainJoueur);
                cout<<"Votre nouveau score : "<<joueurSolo.mainJoueur.getSommeValeur()<<endl;
            break;

            case 'd':
            
                
                cout<<"vous avez choisi de doubler"<<endl;
                cout<<"Voici votre nouvelle main de cartes : "<<endl; 
                jeu.actionClavier('d');
                afficherMainDeCarte(joueurSolo.mainJoueur)
                cout<<"Votre nouveau score : "<<joueurSolo.mainJoueur.getSommeValeur()
                cout<<"Au tour du croupier de jouer, bonne chance! "<<endl;
            break;
        }
        }while (MainDeCarte.getJoueToujours());


        cout<<"Petit rappel, voici la main du croupier avant qu'il joue : "<<endl;
        afficherMainDeCarte(mainCroupier);
        cout<<"Score du croupier: "<<mainCroupier.getSommeValeur()<<endl;

        actionCroupier();

        cout<<"Voici la nouvelle main du croupier : "<<endl;
        afficherMainDeCarte(mainCroupier);
        cout<<"Score du croupier: "<<mainCroupier.getSommeValeur()<<endl;

        resultat();

        if (gain==0)
        {
            cout<<" Vous venez de perdre contre le croupier, retentez votre chance !"<<endl;
            cout<<" Votre budget est maintenant de "<<getBudget()<<endl;
        }


        if (gain==2*mise)
        {
        cout<<" Bravo vous avez battu le croupier, vous remportez 2 fois votre mise !!"<<endl;
        cout<<" Votre budget est maintenant de "<<getBudget()<<endl;
        }

        if (gain==(2.5)*mise)
        {
        cout<<" Bravo vous avez battu le croupier avec un BlackJack, vous remportez 2 fois et demie votre mise !!"<<endl;
        cout<<" Votre budget est maintenant de "<<getBudget()<<endl;
        }

        if (gain==mise)
        {
        cout<<" Vous n'avez ni perdu, ni gagné contre la banque. Vous avez exactement le même score qu'elle, vous êtes remboursé de votre mise !!"<<endl;
        cout<<" Votre budget est maintenant de "<<getBudget()<<endl;
        }

    }
    else 
        {
            cout<< "Merci et à bientôt"<<endl;
        }

}















