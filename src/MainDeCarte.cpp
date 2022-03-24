#include "MainDeCarte.h"
#include <iostream>
#include <cassert>
#include <vector>


using namespace std;

MainDeCarte::MainDeCarte (Carte carte1, Carte carte2)
{   

    Hand.push_back (carte1);// ajoute carte 1 à la main 
    Hand.push_back (carte2);// ajoute carte 2 à la main 
    nbCartes=2; // le nombre de carte est initialisé à 2 
    sommeValeur=carte1.valeur+carte2.valeur; // somme des valeur mise à jour (ATTENTION pour la valeur de l'as)
    joueToujours=1; // initialisation du booléen à VRAI (1)
    cramé?=0; //le joueur à moins de 22

}


void MainDeCarte::tirerCarte (Carte carteAjoutee, unsigned int scoreCroupier);
{
    if ((joueToujours)&&(!cramé?)) //tant que le joueur est encore en lice et qu'il n'a pas cramé 
            {
                nbCartes++; // son nb de carte augmente de 1 
                Hand.push_back (carteAjoutee); // on ajoute la carte tirée à sa main 
                sommeValeur=sommeValeur+ carteAjoutee.valeur; // MAJ de la sommeValeur

            }
    if (sommeValeur>21) // si le joueur a cramé
        {
                joueToujours=0; // booléen = FAUX
                cramé?=1; // le joueur a cramé 
        }    
}
   



void MainDeCarte::doubler (Carte carteAjoutee);
{
    if ( nbCartes==2) // on peut doubler que quand on a uniquement 2 cartes
        {
            nbCartes++; // son nb de carte augmente de 1 
            Hand.push_back (carteAjoutee); // on ajoute la carte tirée à sa main 
            sommeValeur=sommeValeur+ carteAjoutee.valeur; // MAJ de la sommeValeur
            

        }

    if (sommeValeur>21) // si le joueur a cramé
            {   
                    cramé?=1; // le joueur a cramé (booléen VRAI)

            } 
    rester ();
}





MainDeCarte MainDeCarte::splitter (Carte carteAjoutee1, Carte carteAjoutee2);
{
    if ((nbCartes==2)&&(Hand[0].valeur==Hand[1].valeur))
        {
            MainDecarte Hand2(Hand[1],carteAjoutee2); // création de la nouvelle main (Hand2)
            Hand[1]=carteAjoutee1; //mise à jour de la main de base
            sommeValeur=Hand[0].valeur+Hand[1].valeur; // somme des valeur mise à jour (ATTENTION pour la valeur de l'as)
            return Hand2; 
        }
}



void MainDeCarte::rester()
{
    joueToujours=0; // booléen = FAUX   (le joueur passe son tour)      
}




unsigned int MainDeCarte::getSommeValeur () const
{
    return sommeValeur;
}



void MainDeCarte::setSommeValeur (int SommeValeur) const
{
    sommeValeur=SommeValeur;
}



void MainDeCArte::testRegression();
{
    MainDeCarte main1;
    assert (nbCartes==0);
    assert (SommeValeur==0);


}