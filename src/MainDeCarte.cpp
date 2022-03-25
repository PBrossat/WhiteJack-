#include "MainDeCarte.h"
#include <iostream>
#include <cassert>
#include <vector>


using namespace std;

MainDeCarte::MainDeCarte ()
{
    nbCartes=0; // le nombre de carte est initialisé à 0
    sommeValeur=0; //la somme des valeurs est initialisé à 0
}



MainDeCarte::MainDeCarte (Carte carte1, Carte carte2)
{   

    Hand.push_back (carte1);// ajoute carte 1 à la main 
    Hand.push_back (carte2);// ajoute carte 2 à la main 
    nbCartes=2; // le nombre de carte est initialisé à 2 
    sommeValeur=carte1.valeur+carte2.valeur; // somme des valeur mise à jour (ATTENTION pour la valeur de l'as)
    joueToujours=1; // initialisation du booléen à VRAI (1)
    crame=0; //le joueur à moins de 22

}


void MainDeCarte::tirerCarte (Carte carteAjoutee)
{
    if ((joueToujours)&&(! crame)) //tant que le joueur est encore en lice et qu'il n'a pas cramé 
            {
                nbCartes++; // son nb de carte augmente de 1 
                Hand.push_back (carteAjoutee); // on ajoute la carte tirée à sa main 
                sommeValeur=sommeValeur+ carteAjoutee.valeur; // MAJ de la sommeValeur

            }
    if (sommeValeur>21) // si le joueur a cramé
        {
                joueToujours=0; // booléen = FAUX
                crame=1; // le joueur a cramé 
        }    
}
   



void MainDeCarte::doubler (Carte carteAjoutee)
{
    if ( nbCartes==2) // on peut doubler que quand on a uniquement 2 cartes
        {
            nbCartes++; // son nb de carte augmente de 1 
            Hand.push_back (carteAjoutee); // on ajoute la carte tirée à sa main 
            sommeValeur=sommeValeur+ carteAjoutee.valeur; // MAJ de la sommeValeur
            

        }

    if (sommeValeur>21) // si le joueur a cramé
            {   
                    crame=1; // le joueur a cramé (booléen VRAI)

            } 
    rester ();
}





// MainDeCarte MainDeCarte::splitter (Carte carteAjoutee1, Carte carteAjoutee2)
// {
//     if ((nbCartes==2)&&(Hand[0].valeur==Hand[1].valeur))
//         {
//             MainDeCarte Hand2(Hand[1],carteAjoutee2); // création de la nouvelle main (Hand2)
//             Hand[1]=carteAjoutee1; //mise à jour de la main de base
//             sommeValeur=Hand[0].valeur+Hand[1].valeur; // somme des valeur mise à jour (ATTENTION pour la valeur de l'as)
//             return Hand2; 
//         }
// }



void MainDeCarte::rester()
{
    joueToujours=0; // booléen = FAUX   (le joueur passe son tour)      
}




unsigned int MainDeCarte::getSommeValeur () const
{
    return sommeValeur;
}



void MainDeCarte::setSommeValeur (int SommeValeur) 
{
    sommeValeur=SommeValeur;
}



void MainDeCarte::testRegression() const
{
    MainDeCarte main1; //creation d'une main de base main1
    assert (main1.nbCartes==0);
    assert (main1.sommeValeur==0);

    Carte carte1(2,2); //creation de deux cartes (carte1 et carte2)
    Carte carte2(3,0);
    MainDeCarte main2(carte1,carte2); //creation d'une main de deux cartes (carte1 et carte2)
    assert (main2.nbCartes==2); // test du nombre de cartes 
    assert (main2.sommeValeur==5);// test de la somme des valeur 
    assert (main2.joueToujours==1); //test du booléen joueToujours?
    assert (main2.crame==0); // test du booléen crame
    assert (carte1.valeur==2); // test si la valeur des cartes est bien celle attribuée 
    assert (carte2.valeur==3);
    assert (carte1.signe==2); // test si le signe des cartes est bien celui attribué 
    assert (carte2.signe==0);


    Carte carteAjoutee(8,1); //création d'une carte à ajouter
    main2.tirerCarte(carteAjoutee); 
    assert (main2.nbCartes==3); // test du nombre de cartes 
    assert (main2.sommeValeur==13);// test de la somme des valeur 
    assert (main2.joueToujours==1); //test du booléen joueToujours
    assert (main2.crame==0); // test du booléen crame
    assert (carteAjoutee.valeur==8); // test si la valeur de la nouvelle carte est bien celle attribuée 
    assert (carteAjoutee.signe==1); // test si le signe de la nouvelle carte est bien celui attribué 


    Carte carteAjoutee2(10,1);
    main2.tirerCarte(carteAjoutee2);
    assert (main2.nbCartes==4); // test du nombre de cartes 
    assert (main2.sommeValeur==23);// test de la somme des valeur
    assert (main2.joueToujours==0); //test du booléen joueToujours qui doit être =0 car 23>21
    assert (main2.crame==1); // test du booléen crame qui doit être =1 car 23>21


    // Carte carte3(10,2); //creation de deux cartes (carte3 et carte4)
    // Carte carte4(10,0);
    // Carte carteAjoutee3(3,0); //création de deux cartes à ajouter (carteAjoutee3 et carteAjoutee4)
    // Carte carteAjoutee4(4,0);
    // MainDeCarte main3(carte3,carte4); //creation d'une main de deux cartes (carte1 et carte2)
    // main3.splitter (Carte carteAjoutee3, Carte carteAjoutee4); 

    cout<<"test de regression passé avec succès"<<endl;
    
}