#include <iostream>
#include <cassert>
#include "JeuSolo.h"
#include "Joueur.h"
#include "WinTxt.h"

using namespace std; 


ostream& operator << (ostream& flux, const Carte& carteAffichee)
{
    flux<<endl<<endl<<"======"<<endl;
    flux<<"|";
    if(carteAffichee.rang == 11) flux<<"J ";
    else if (carteAffichee.rang == 12) flux<<"Q ";
    else if(carteAffichee.rang == 13) flux<<"K ";
    else if(carteAffichee.rang == 1) flux<<"A ";
    else if(carteAffichee.rang == 2) flux<<"2 ";
    else if(carteAffichee.rang == 3) flux<<"3 ";
    else if(carteAffichee.rang == 4) flux<<"4 ";
    else if(carteAffichee.rang == 5) flux<<"5 ";
    else if(carteAffichee.rang == 6) flux<<"6 ";
    else if(carteAffichee.rang == 7) flux<<"7 ";
    else if(carteAffichee.rang == 8) flux<<"8 ";
    else if(carteAffichee.rang == 9) flux<<"9 ";
    else if(carteAffichee.rang == 10) flux<<"10";
    if(carteAffichee.signe == 1) flux<<"♠";
    else if (carteAffichee.signe == 2) flux<<"♥";
    else if(carteAffichee.signe == 3) flux<<"♣";
    else if(carteAffichee.signe == 4) flux<<"♦";
    flux<<"  |"<<endl;
    flux<<"|     |"<<endl;
    flux<<"|     |"<<endl;
    flux<<"|  ";
    if(carteAffichee.rang == 11) flux<<" J";
    else if (carteAffichee.rang == 12) flux<<" Q";
    else if(carteAffichee.rang == 13) flux<<" K";
    else if(carteAffichee.rang == 1) flux<<" A";
    else if(carteAffichee.rang == 2) flux<<" 2";
    else if(carteAffichee.rang == 3) flux<<" 3";
    else if(carteAffichee.rang == 4) flux<<" 4";
    else if(carteAffichee.rang == 5) flux<<" 5";
    else if(carteAffichee.rang == 6) flux<<" 6";
    else if(carteAffichee.rang == 7) flux<<" 7";
    else if(carteAffichee.rang == 8) flux<<" 8";
    else if(carteAffichee.rang == 9) flux<<" 9";
    else if(carteAffichee.rang == 10) flux<<"10";
    if(carteAffichee.signe == 1) flux<<"♠";
    else if (carteAffichee.signe == 2) flux<<"♥";
    else if(carteAffichee.signe == 3) flux<<"♣";
    else if(carteAffichee.signe == 4) flux<<"♦";
    flux<<"|"<<endl;
    flux<<"======";
    return flux;
}



void afficherMainDeCarte(const MainDeCartes& mainJoueur)
{
    for (unsigned int i=0; i<mainJoueur.getNbCartes(); i++)
    {
        cout<<mainJoueur.getIemeCarte(i)<<endl;
    }

}



void txtBoucle (JeuSolo& jeu)
{
    bool veutJouer=1; //initilaisation du booléen à vrai. 
    char choix1;
    char choix2;
    char choix3;
    cout<<"Bonjour, soyez le,la bienvenu(e) ! Nous verifions votre carte d'identité ... Tout est bon vous êtes bien majeur(e)"<<endl<<endl;
    cout<<"Prenez place sur notre table. Vous jouerez contre Gérard notre meilleur croupier."<<endl;
    do 
    {
         
        cout<<"Vous avez actuellement:  "<<jeu.joueurSolo.getBudget()<<"$ de budget, prenez en soins !"<<endl<<endl;
        cout<<"Combien voulez miser pour cette manche ?"<<endl;

        if(jeu.joueurSolo.getBudget()>=500)
        {
            cout<<"1$ (entrez 'a')  |   10$ (entrez 'z') |   100$ (entrez 'e') |   250$ (entrez 'r') |   500$ (entrez 't')"<<endl;
            do
            {
                cin>>choix3;
            }while((choix3!='a')&&(choix3!='z')&&(choix3!='e')&&(choix3!='r')&&(choix3!='t'));
        }
        else if(jeu.joueurSolo.getBudget()>=250)
        {
            cout<<"1$ (entrez 'a')  |   10$ (entrez 'z') |   100$ (entrez 'e') |   250$ (entrez 'r')"<<endl;
            do
            {
                cin>>choix3;
            }while((choix3!='a')&&(choix3!='z')&&(choix3!='e')&&(choix3!='r'));
        }
        else if(jeu.joueurSolo.getBudget()>=100)
        {
            cout<<"1$ (entrez 'a')  |   10$ (entrez 'z') |   100$ (entrez 'e')"<<endl;
            do
            {
                cin>>choix3;
            }while((choix3!='a')&&(choix3!='z')&&(choix3!='e'));
        }
        else if(jeu.joueurSolo.getBudget()>=10)
        {
            cout<<"1$ (entrez 'a')  |   10$ (entrez 'z')"<<endl;
            do
            {
                cin>>choix3;
            }while((choix3!='a')&&(choix3!='z'));
        }
        else
        {
            cout<<"1$ (entrez 'a')"<<endl;
            do
            {
                cin>>choix3;
            }while((choix3!='a'));
        }
        jeu.initialisationMise(choix3);
        cout<<"Vous avez misé :  "<<jeu.joueurSolo.getMise()<<"$"<<endl;
        cout<<"Gérard distribue les cartes. "<<endl<<endl;


        jeu.initialisationJeu();

        cout<<"Votre main est la suivante : "<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        afficherMainDeCarte(jeu.joueurSolo.mainJoueur);
        cout<<endl<<"Votre score : "<<jeu.joueurSolo.mainJoueur.getSommeValeur()<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;


        cout<<"La main du croupier est la suivante : "<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;
        afficherMainDeCarte(jeu.mainCroupier);
        cout<<endl<<"Score du croupier: "<<jeu.mainCroupier.getSommeValeur()<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;

        do
        {
            if((jeu.joueurSolo.mainJoueur.getNbCartes()==2) && (jeu.joueurSolo.getBudget()>=jeu.joueurSolo.getMise()))
            {
                do
                {
                    cout<<"Vous pouvez actuellement : " <<endl;
                    cout<<" ● Rester : appuyer sur la touche R de votre clavier"<<endl;
                    cout<<" ● Tirer : appuyer sur la touche T de votre clavier"<<endl;
                    cout<<" ● Doubler : appuyer sur la touche D de votre clavier"<<endl;
                    cin>>choix1;
                    cout<<endl;
                }while((choix1!='t')&&(choix1!='r')&&(choix1!='d')); 
            }
            else
            {
                do
                {
                    cout<<"Vous pouvez actuellement : " <<endl;
                    cout<<" ● Rester : appuyer sur la touche R de votre clavier"<<endl;
                    cout<<" ● Tirer : appuyer sur la touche T de votre clavier"<<endl;
                    cin>>choix1;
                    cout<<endl;
                }while((choix1!='t')&&(choix1!='r'));  
            }
                
            switch (choix1)
            {
                case 'r':
                    
                    jeu.actionClavier('r');
                    cout<<"Vous avez choisi de rester"<<endl;
                    cout<<"Votre score ne change pas il est toujours égal à : "<<jeu.joueurSolo.mainJoueur.getSommeValeur()<<endl;
                    cout<<"--------------------------------------------------------------------------"<<endl;
                    cout<<"Au tour du croupier de jouer, bonne chance! "<<endl;
                break;

                case 't':
                    
                    cout<<"Vous avez choisi de tirer"<<endl;
                    cout<<"Voici votre nouvelle main de cartes : "<<endl; 
                    cout<<"--------------------------------------------------------------------------"<<endl;
                    jeu.actionClavier('t');
                    afficherMainDeCarte(jeu.joueurSolo.mainJoueur);
                    cout<<endl<<"Votre nouveau score : "<<jeu.joueurSolo.mainJoueur.getSommeValeur()<<endl;
                    cout<<"--------------------------------------------------------------------------"<<endl;
                    break;

                case 'd':
                    
                    cout<<"Vous avez choisi de doubler"<<endl;
                    cout<<"Voici votre nouvelle main de cartes : "<<endl; 
                    cout<<"--------------------------------------------------------------------------"<<endl;
                    jeu.actionClavier('d');
                    afficherMainDeCarte(jeu.joueurSolo.mainJoueur);
                    cout<<endl<<"Votre nouveau score : "<<jeu.joueurSolo.mainJoueur.getSommeValeur()<<endl;
                    cout<<"--------------------------------------------------------------------------"<<endl;
                    cout<<"Au tour du croupier de jouer, bonne chance! "<<endl;
                    break;
            }
        }while (jeu.joueurSolo.mainJoueur.getJoueToujours());

        
        jeu.actionCroupier();

        cout<<"Voici la nouvelle main du croupier : "<<endl;
        afficherMainDeCarte(jeu.mainCroupier);

        cout<<endl<<"Score du croupier: "<<jeu.mainCroupier.getSommeValeur()<<endl;
        cout<<"--------------------------------------------------------------------------"<<endl;

        unsigned int res = jeu.resultat();

        if (res==0/*jeu.joueurSolo.getGain()==0*/)
        {
            cout<<" Vous venez de perdre contre le croupier, retentez votre chance !"<<endl;
            cout<<" Votre budget est maintenant de "<<jeu.joueurSolo.getBudget()<<"$"<<endl;
        }


        if (res==2/*jeu.joueurSolo.getGain()==2*jeu.joueurSolo.getMise()*/)
        {
            cout<<" Bravo vous avez battu le croupier, vous remportez 2 fois votre mise !!"<<endl;
            cout<<" Votre budget est maintenant de "<<jeu.joueurSolo.getBudget()<<"$"<<endl;
        }

        if (res==3/*jeu.joueurSolo.getGain()==(2.5)*jeu.joueurSolo.getMise()*/)
        {
            cout<<" Bravo vous avez battu le croupier avec un BlackJack, vous remportez 2 fois et demie votre mise !!"<<endl;
            cout<<" Votre budget est maintenant de "<<jeu.joueurSolo.getBudget()<<"$"<<endl;
        }

        if (res==1/*jeu.joueurSolo.getGain()==jeu.joueurSolo.getMise()*/)
        {
            cout<<" Vous avez fait le même score que le croupier, vous récupérez votre mise !!"<<endl;
            cout<<" Votre budget est maintenant de "<<jeu.joueurSolo.getBudget()<<"$"<<endl;
        }

        if(jeu.joueurSolo.testArgentJoueur())
        {
            cout<<endl<<endl<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
            cout<<"Voulez vous refaire une partie? Si oui tapez 'o' sur votre clavier, sinon tapez 'n' sur votre clavier "<<endl;
            do
            {
                cin>>choix2;
            }while((choix2!='o') && (choix2!='n'));
            if (choix2=='n') // si le joueur a appuyé sur n, il ne veut plus jouer et on chnage le booléen, sinon on fait rien.
            {
                veutJouer=0;
            }
            termClear();
        }
        jeu.finJeu();

        cout<<endl<<endl<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;

    }while ((veutJouer==1)&&(jeu.joueurSolo.testArgentJoueur()==1));

    cout<<endl<<endl<<endl<<"A bientot !!"<<endl<<endl<<endl;

}















