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



MainDeCarte::MainDeCarte (const Carte& carte1, const Carte& carte2)
{   

    mainDeJoueur.push_back (carte1);// ajoute carte 1 à la main 
    mainDeJoueur.push_back (carte2);// ajoute carte 2 à la main 
    nbCartes=2; // le nombre de carte est initialisé à 2 
    sommeValeur=carte1.getValeur()+carte2.getValeur(); // somme des valeur mise à jour (ATTENTION pour la valeur de l'as)
    joueToujours=1; // initialisation du booléen à VRAI (1)
    crame=0; //le joueur à moins de 22

}




void MainDeCarte::verifScore()
{
    if (sommeValeur>21) 
        {
            crame=1; // passage de crame à vrai , le joueur a cramé
            joueToujours=0; // passage de joueToujours à faux , le joueur ne peut plus jouer
        }
}



void MainDeCarte::tirerCarte (const Carte& carteAjoutee)
{
    if ((joueToujours)&&(! crame)) //tant que le joueur est encore en lice et qu'il n'a pas cramé 
            {
                nbCartes++; // son nb de carte augmente de 1 
                mainDeJoueur.push_back (carteAjoutee); // on ajoute la carte tirée à sa main 
                sommeValeur=sommeValeur+ carteAjoutee.getValeur(); // MAJ de la sommeValeur

            }
    verifScore(); // permet de changer les booléen en fonction du score du joueur 
}
   



void MainDeCarte::doubler (const Carte& carteAjoutee)
{
    if ( nbCartes==2) // on peut doubler que quand on a uniquement 2 cartes
        {
            nbCartes++; // son nb de carte augmente de 1 
            mainDeJoueur.push_back (carteAjoutee); // on ajoute la carte tirée à sa main 
            sommeValeur=sommeValeur+ carteAjoutee.getValeur(); // MAJ de la sommeValeur
            

        }

        verifScore(); // permet de changer les booléens crame et joueToujours en fonction du score du joueur

        rester (); // reste si le joueur n'as pas cramé
}   





// MainDeCarte MainDeCarte::splitter (Carte carteAjoutee1, Carte carteAjoutee2)
// {
//     if ((nbCartes==2)&&(Hand[0].getValeur==Hand[1].getValeur))
//         {
//             MainDeCarte Hand2(Hand[1],carteAjoutee2); // création de la nouvelle main (Hand2)
//             Hand[1]=carteAjoutee1; //mise à jour de la main de base
//             sommeValeur=Hand[0].getValeur+Hand[1].valeur; // somme des valeur mise à jour (ATTENTION pour la valeur de l'as)
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


unsigned int MainDeCarte::getNbCartes () const
{
    return nbCartes;
}




bool MainDeCarte::getJoueToujours () const
{
    return joueToujours;
}



bool MainDeCarte::getCrame () const
{
    return crame;
}




void MainDeCarte::testRegression() const
{
    MainDeCarte main1; //creation d'une main de base main1
    assert (main1.getNbCartes()==0);
    assert (main1.getSommeValeur()==0);
    cout<<"Création de la main par défaut OK"<<endl;


    Carte carte1(2,2,1); //creation de deux cartes (carte1 et carte2)
    Carte carte2(3,3,2);
    MainDeCarte main2(carte1,carte2); //creation d'une main de deux cartes (carte1 et carte2)
    assert (main2.getNbCartes()==2); // test du nombre de cartes 
    assert (main2.getSommeValeur()==5);// test de la somme des valeur 
    assert (main2.getJoueToujours()==1); //test du booléen joueToujours?
    assert (main2.getCrame()==0); // test du booléen crame
    assert (carte1.getValeur()==2); // test si la valeur des cartes est bien celle attribuée 
    assert (carte2.getValeur()==3);
    assert (carte1.getSigne()==1); // test si le signe des cartes est bien celui attribué 
    assert (carte2.getSigne()==2);
    cout<<"Création de main2 réaliser avec succès"<<endl;



    Carte carteAjoutee(8,8,4); //création d'une carte à ajouter
    main2.tirerCarte(carteAjoutee); 
    assert (main2.getNbCartes()==3); // test du nombre de cartes 
    assert (main2.getSommeValeur()==13);// test de la somme des valeur 
    assert (main2.getJoueToujours()==1); //test du booléen joueToujours
    assert (main2.getCrame()==0); // test du booléen crame
    assert (carteAjoutee.getValeur()==8); // test si la valeur de la nouvelle carte est bien celle attribuée 
    assert (carteAjoutee.getSigne()==4); // test si le signe de la nouvelle carte est bien celui attribué 
    cout<<"Ajout d'une carte réaliser avec succès"<<endl;



    Carte carteAjoutee2(11,10,1);
    main2.tirerCarte(carteAjoutee2);
    assert (main2.getNbCartes()==4); // test du nombre de cartes 
    assert (main2.getSommeValeur()==23);// test de la somme des valeur
    assert (main2.getJoueToujours()==0); //test du booléen joueToujours qui doit être =0 car 23>21
    assert (main2.getCrame()==1); // test du booléen crame qui doit être =1 car 23>21
    cout<<"La carte ajoutée a fait cramer le joueur avec succès"<<endl;


    // Carte carte3(10,2); //creation de deux cartes (carte3 et carte4)
    // Carte carte4(10,0);
    // Carte carteAjoutee3(3,0); //création de deux cartes à ajouter (carteAjoutee3 et carteAjoutee4)
    // Carte carteAjoutee4(4,0);
    // MainDeCarte main3(carte3,carte4); //creation d'une main de deux cartes (carte1 et carte2)
    // main3.splitter (Carte carteAjoutee3, Carte carteAjoutee4); 

    cout<<"Test de regression passé avec succès"<<endl;
    
}