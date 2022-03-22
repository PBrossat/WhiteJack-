#include "MainDeCarte.h"
#include <iostream>
#include <cassert>
#include <vector>


using namespace std;

MainDeCarte::MainDeCarte (Carte carte1, Carte carte2)
{   
    nbCartes=2;
    vector<Carte>Hand(2); //creer un tab dyna de Cartes, nom= hand et taille =2
    Hand.push_back (carte1);// ajoute carte 1 à la main 
    Hand.push_back (carte2);// ajoute carte 2 à la main 
    sommeValeur=carte1.valeur+carte2.valeur; 
}


void MainDeCarte::tirerCarte (unsigned int niveauJoueur, Carte carteAjoutee, unsigned int scoreCroupier);
{
    if (état) //tant que le joueur est encore en lice 
            {
                nbCartes++; // son nb de carte augmente de 1 
                Hand.push_back (carteAjoutee); // on ajoute la carte tirée à sa main 
                sommeValeur=sommeValeur+ carteAjoutee.valeur; // MAJ de la sommeValeur

            }

}
   




//     switch (niveauJoueur)
//     {
//         case 0: //joueur physique 
//         if (sommeValeur<21) //tant que le joueur est encore en lice 
//             {
//                 nbCartes++; // son nb de carte augmente de 1 
//                 Hand.push_back (carteAjoutee); // on ajoute la carte tirée à sa main 
//                 sommeValeur=sommeValeur+ carteAjoutee.valeur; // MAJ de la sommeValeur

//             }
//         break; 


//         case 1: // joueur amateur 
//         if (sommeValeur<21)
//             {
//                 while (sommeValeur<16 ) // tant que le joueur amateur à moins de 16 il tire
//                 nbCartes++;
//                 Hand.push_back (carteAjoutee);
//                 sommeValeur=sommeValeur+ carteAjoutee.valeur;
                
//             }
//         break;


//         case 2: // joueur intermédiaire
//         if (sommeValeur<21)
//             {
                



//             }




//         case 3: // joueur expert 
//         if (sommeValeur<21)
//         {

//             if (nbCartes==2) // si le nombre de cartes est égal à 2 
//             { if (Hand[0].valeur==Hand[1].valeur && Hand[0].valeur==2 ) // si les cartes 
//              {}



//             }



//         }




// }



void MainDeCarte::doubler (unsigned int niveauJoueur);
{
    if ( nbCartes==2)
        {
            nbCartes++; // son nb de carte augmente de 1 
            Hand.push_back (carteAjoutee); // on ajoute la carte tirée à sa main 
            sommeValeur=sommeValeur+ carteAjoutee.valeur; // MAJ de la sommeValeur
            rester(unsigned int niveauJoueur );

        }

}


void MainDeCarte::splitter (unsigned int niveauJoueur);
{
    if ((nbCartes==2)&&(Hand[0].valeur==Hand[1].valeur))
        {
        
            vector<Carte>Hand2(2); //creer un tab dyna de Cartes, nom= "Hand2" et taille = 2
            nbCartes=1; // le nombre de carte de la main du joueur est réduit à 1
            Hand2.push_back (Hand[1].Carte); // on ajoute la deuxieme carte de la main de base au nouveau tab dynamique (Hand2)
            Hand.pop_back();
            sommeValeur=sommeValeur+ carteAjoutee.valeur; // MAJ de la sommeValeur
            rester(unsigned int niveauJoueur );

        }




}




void MainDeCArte::testRegression();
{
    MainDeCarte main1;
    assert (nbCartes==0);
    assert (SommeValeur==0);


}