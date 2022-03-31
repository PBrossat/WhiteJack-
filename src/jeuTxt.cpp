#include <iostream>
#include <cassert>
#include "Jeu.h"
//#include "jeuTxt.h"

using namespace std; 





void afficherMainDeCarte(MainDeCarte mainJoueur)
{

    int i;
    for (i=0; i<mainJoueur.getNbCartes(); i++)
    {
        cout<<mainJoueur.getIemeCarte(i)<<endl;
    }

}



void txtBoucle (Jeu& jeu)
{
bool veutJouer=1; //initilaisation du booléen à vrai. 
char choix1;
char choix2;
cout<<"Bonjour, soyez le bienvenue ! Nous verifions votre carte d'identité ... Tout est bon vous êtes bien majeur"<<endl;
cout<<"Prenez place sur notre table. Vous jouerez contre Gérard notre meilleur croupier."<<endl;
do 
{
         
        cout<<"Vous avez actuellement"<<jeu.joueurSolo.getBudget()<<"$ de budget, prenez en soins !"<<endl<<endl;
        cout<<"Combien voulez miser pour cette manche ?"<<endl;


        jeu.initialisationMise();
        cout<<"Vous avez misé :  "<<jeu.mise<<"$"<<endl;
        cout<<"Gérard distribue les cartes. "<<endl<<endl;


        jeu.initialisationJeu();

        cout<<"Votre main est la suivante : "<<endl<<endl;
        afficherMainDeCarte(jeu.joueurSolo.mainJoueur);
        cout<<"Votre score : "<<jeu.joueurSolo.mainJoueur.getSommeValeur()<<endl<<endl;


        cout<<"La main du croupier est la suivante : "<<endl<<endl;
        afficherMainDeCarte(jeu.mainCroupier);
        cout<<"Score du croupier: "<<jeu.mainCroupier.getSommeValeur()<<endl<<endl;
       

        do
        {
            do 
            {
                cout<<"Vous pouvez actuellement : rester, tirer ou doubler." <<endl;
                cout<<"Pour rester, appuyer sur la touche R de votre clavier"<<endl;
                cout<<"Pour tirer, appuyer sur la touche T de votre clavier"<<endl;
                if((jeu.joueurSolo.mainJoueur.getNbCartes()==2) && (jeu.joueurSolo.getBudget()>=jeu.mise))
                {
                    cout<<"Pour doubler, appuyer sur la touche D de votre clavier"<<endl;
                }
                cout<<endl;
                cin>>choix1;
            }while((choix1!='t')&&(choix1!='r')&&(choix1!='d'));  
                
            switch (choix1)
            {
                case 'r':
                    
                    jeu.actionClavier('r');
                    cout<<"vous avez choisi de rester"<<endl;
                    cout<<"Votre score ne change pas il est toujours égal à : "<<jeu.joueurSolo.mainJoueur.getSommeValeur()<<endl;
                    cout<<"Au tour du croupier de jouer, bonne chance! "<<endl;
                break;

                case 't':
                    
                    cout<<"vous avez choisi de tirer"<<endl;
                    cout<<"Voici votre nouvelle main de cartes : "<<endl; 
                    jeu.actionClavier('t');
                    afficherMainDeCarte(jeu.joueurSolo.mainJoueur);
                    cout<<"Votre nouveau score : "<<jeu.joueurSolo.mainJoueur.getSommeValeur()<<endl;
                    break;

                case 'd':
                    
                    cout<<"vous avez choisi de doubler"<<endl;
                    cout<<"Voici votre nouvelle main de cartes : "<<endl; 
                    jeu.actionClavier('d');
                    afficherMainDeCarte(jeu.joueurSolo.mainJoueur);
                    cout<<"Votre nouveau score : "<<jeu.joueurSolo.mainJoueur.getSommeValeur()<<endl;
                    cout<<"Au tour du croupier de jouer, bonne chance! "<<endl;
                    break;
            }
        }while (jeu.joueurSolo.mainJoueur.getJoueToujours());


        cout<<"Petit rappel, voici la main du croupier avant qu'il joue : "<<endl;
        afficherMainDeCarte(jeu.mainCroupier);
        cout<<"Score du croupier: "<<jeu.mainCroupier.getSommeValeur()<<endl;

        jeu.actionCroupier();

        cout<<"Voici la nouvelle main du croupier : "<<endl;
        afficherMainDeCarte(jeu.mainCroupier);
        cout<<"Score du croupier: "<<jeu.mainCroupier.getSommeValeur()<<endl;

        jeu.resultat();

        if (jeu.gain==0)
        {
            cout<<" Vous venez de perdre contre le croupier, retentez votre chance !"<<endl;
            cout<<" Votre budget est maintenant de "<<jeu.joueurSolo.getBudget()<<endl;
        }


        if (jeu.gain==2*jeu.mise)
        {
            cout<<" Bravo vous avez battu le croupier, vous remportez 2 fois votre mise !!"<<endl;
            cout<<" Votre budget est maintenant de "<<jeu.joueurSolo.getBudget()<<endl;
        }

        if (jeu.gain==(2.5)*jeu.mise)
        {
            cout<<" Bravo vous avez battu le croupier avec un BlackJack, vous remportez 2 fois et demie votre mise !!"<<endl;
            cout<<" Votre budget est maintenant de "<<jeu.joueurSolo.getBudget()<<endl;
        }

        if (jeu.gain==jeu.mise)
        {
            cout<<" Vous n'avez ni perdu, ni gagné contre la banque. Vous avez exactement le même score qu'elle, vous êtes remboursé de votre mise !!"<<endl;
            cout<<" Votre budget est maintenant de "<<jeu.joueurSolo.getBudget()<<endl;
        }

        do
        {
            cout<<"Voulez vous refaire une partie? Si oui tapez Y sur votre clavier, sinon tapez N sur votre clavier "<<endl;
            cin>>choix2;
        }while((choix2!='y')&&(choix2!='n'));

    if (choix2=='n') // si le joueur a appuyé sur n, il ne veut plus jouer et on chnage le booléen, sinon on fait rien.
    {
        veutJouer=0;
    }

    jeu.finJeu();

}while ((veutJouer==1)&&(jeu.joueurSolo.testArgentJoueur()==1));



cout<<endl<<endl<<endl<<"A bientot !!"<<endl<<endl<<endl;

}















