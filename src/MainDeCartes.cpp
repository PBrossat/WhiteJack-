#include "MainDeCartes.h"
#include <iostream>
#include <cassert>
#include <vector>


using namespace std;


MainDeCartes::MainDeCartes ()
{

    nbCartes=0; // le nombre de carte est initialisé à 0
    sommeValeur=0; //la somme des valeurs est initialisé à 0
    joueToujours=1; // initialisation du booléen à VRAI (1)
    crame=0; //le joueur à moins de 22
}



MainDeCartes::MainDeCartes (const Carte& carte1, const Carte& carte2)
{   
    joueToujours=1; // initialisation du booléen à VRAI (1)
    crame=0; //le joueur à moins de 22
    nbCartes=0; // le nombre de carte est initialisé à 0
    sommeValeur=0; //initialisation de sommeValeur à 0
    tirerCarte(carte1);// ajoute carte 1 à la main 
    tirerCarte(carte2);// ajoute carte 2 à la main 

}



MainDeCartes::~MainDeCartes()
{
    mainDeJoueur.clear();
}



void MainDeCartes::verifScore()
{
    if (sommeValeur>21) 
    {
        crame=1; // passage de crame à vrai , le joueur a cramé
        joueToujours=0; // passage de joueToujours à faux , le joueur ne peut plus jouer
    }
}



bool MainDeCartes::verifBlackJack ()
{
    if ((nbCartes==2)&&(sommeValeur==21)) // si on a deux cartes et que la somme des valeurs des deux cartes est = 21 (BlackJack)
    {
        joueToujours=0; // le joueur ne peut plus jouer
        return true;
    }
    else
    {
        return false;
    }
}



Carte MainDeCartes::getIemeCarte(unsigned int indice) const
{
    assert((indice< mainDeJoueur.size())&&(mainDeJoueur.size()!=0));
    return mainDeJoueur[indice];
}



void MainDeCartes::tirerCarte (const Carte& carteAjoutee)
{
    if ((joueToujours)&&(! crame)) //tant que le joueur est encore en lice et qu'il n'a pas cramé 
    {
        nbCartes++; // son nb de carte augmente de 1 
        mainDeJoueur.push_back (carteAjoutee); // on ajoute la carte tirée à sa main 
        sommeValeur=sommeValeur+ carteAjoutee.getValeur(); // MAJ de la sommeValeur

    }
    verifAs();
    verifScore(); // permet de changer les booléen en fonction du score du joueur 
}



void MainDeCartes::doubler (const Carte& carteAjoutee)
{
    if ( nbCartes==2) // on peut doubler que quand on a uniquement 2 cartes
    {
        nbCartes++; // son nb de carte augmente de 1 
        mainDeJoueur.push_back (carteAjoutee); // on ajoute la carte tirée à sa main 
        sommeValeur=sommeValeur+ carteAjoutee.getValeur(); // MAJ de la sommeValeur    
        verifAs();
        verifScore(); // permet de changer les booléens crame et joueToujours en fonction du score du joueur
        rester (); // reste si le joueur n'as pas cramé

    }

}   



void MainDeCartes::changeCarte (const Carte& carteAjoutee)
{
    if ((nbCartes==2)&&((getIemeCarte(0).getValeur()==getIemeCarte(1).getValeur())||(getIemeCarte(0).getRang()==getIemeCarte(1).getRang())))
    {
            sommeValeur=sommeValeur-getIemeCarte(1).getValeur(); //maj de sommeValeur
            mainDeJoueur.pop_back(); //on supprime la deuxieme carte de la main
            nbCartes--;
            tirerCarte(carteAjoutee); // on obtient une nouvelle carte
    }
}



void MainDeCartes::rester()
{
    joueToujours=0; // booléen = FAUX   (le joueur passe son tour)      
}




unsigned int MainDeCartes::getSommeValeur () const
{
    return sommeValeur;
}



void MainDeCartes::setSommeValeur (unsigned int SommeValeur) 
{
    sommeValeur=SommeValeur;
}



unsigned int MainDeCartes::getNbCartes () const
{
    return nbCartes;
}



bool MainDeCartes::getJoueToujours () const
{
    return joueToujours;
}



bool MainDeCartes::getCrame () const
{
    return crame;
}



void MainDeCartes::vider()
{
    mainDeJoueur.clear();
    nbCartes=0;
    crame=0;
    sommeValeur=0;
    joueToujours=1;
}



void MainDeCartes::verifAs()
{
    for (unsigned int i=0; i<getNbCartes (); i++) //parcours de la main de cartes
    {
        if (mainDeJoueur[i].getRang()==1) // si la carte est un as (rang=1)
        {
            if (mainDeJoueur[i].getValeur()==1) //si l'as à une valeur de 1 alors
            {
                if ((sommeValeur+10)<=21) // si la somme des valeurs des cartes +10 est inf ou egal à 21 alors
                {
                mainDeJoueur[i].setValeur(11); //on passe la valeur de l'as à 11
                setSommeValeur(sommeValeur+10); // on passe la somme des valeurs des cartes à (getSommeValeur()+10) 
                } // sinon on fait rien 
            }
            if (mainDeJoueur[i].getValeur()==11) //si l'as à une valeur de 11 alors
            {
                if (sommeValeur>21) // si la somme des valeurs des cartes est sup à 21 (joueur a cramé)  alors
                    {
                    mainDeJoueur[i].setValeur(1); //on passe la valeur de l'as à 1
                    setSommeValeur(sommeValeur-10); // on passe la somme des valeurs des cartes à (getSommeValeur()-10) 
                    } // sinon on fait rien 
            }
        }
    }	
}



void MainDeCartes::testRegression() const
{
    MainDeCartes mainVide; //creation d'une main de base main1
    assert (mainVide.getNbCartes()==0);
    assert (mainVide.getSommeValeur()==0);
    assert (mainVide.getJoueToujours()==1);
    assert (mainVide.getCrame()==0);
    cout<<"Constructeur sans paramètres OK"<<endl;



    Carte carte1(2,2,1); //creation de deux cartes (carte1 et carte2)
    Carte carte2(3,3,2);
    MainDeCartes main(carte1,carte2); //creation d'une main de deux cartes (carte1 et carte2)
    assert (main.getNbCartes()==2); // test du nombre de cartes 
    assert (main.getSommeValeur()==5);// test de la somme des valeur 
    assert (main.getJoueToujours()==1); //test du booléen joueToujours?
    assert (main.getCrame()==0); // test du booléen crame
    assert (carte1==main.mainDeJoueur[0]); // test si carte1 est bien la même carte que la carte d'indice 0 du tableau de la main de joueur.
    assert (carte2==main.mainDeJoueur[1]); // test si carte2 est bien la même carte que la carte d'indice 1 du tableau de la main de joueur.
    assert (carte1.getSigne()==1); // test si le signe de la nouvelle carte est bien celui attribué 
    assert (carte2.getSigne()==2); // test si le signe de la nouvelle carte est bien celui attribué  
    cout<<"Constructeur avec paramètres OK"<<endl;
    cout<<"Accesseur de nbCartes OK"<<endl;
    cout<<"Accesseur de sommeValeur OK"<<endl;



    Carte carteAjoutee(8,8,4); //création d'une carte à ajouter
    main.tirerCarte(carteAjoutee); 
    assert (main.getNbCartes()==3); // test du nombre de cartes 
    assert (main.getSommeValeur()==13);// test de la somme des valeur 
    assert (main.getJoueToujours()==1); //test du booléen joueToujours
    assert (main.getCrame()==0); // test du booléen crame
    assert (carteAjoutee==main.mainDeJoueur[2]); // test si carteAjoutee est bien la même carte que la carte d'indice 2 du tableau de la main de joueur.
    assert (carteAjoutee.getSigne()==4); // test si le signe de la nouvelle carte est bien celui attribué 
    cout<<"Test de la procédure tirerCarte(carte) réalisé avec succès"<<endl;



    Carte carteAjoutee2(11,10,1);
    main.tirerCarte(carteAjoutee2);
    assert (main.getNbCartes()==4); // test du nombre de cartes 
    assert (main.getSommeValeur()==23);// test de la somme des valeur
    assert (main.getJoueToujours()==0); //test du booléen joueToujours qui doit être =0 car 23>21
    assert (main.getCrame()==1); // test du booléen crame qui doit être =1 car 23>21
    assert (carteAjoutee2==main.mainDeJoueur[3]); // test si carteAjoutee2 est bien la même carte que la carte d'indice 3 du tableau de la main de joueur.
    assert (carteAjoutee2.getSigne()==1); // test si le signe de la nouvelle carte est bien celui attribué
    cout<<"La carte ajoutée a fait cramer le joueur "<<endl;
    cout<<"Accesseur de joueToujours OK"<<endl;
    cout<<"Accesseur de crame OK"<<endl;



    Carte carte3 (7,7,3); // création de deux nouvelles cartes (carte3 et carte4)
    Carte carte4 (4,4,3); 
    Carte carteAjouteeDouble (11, 10, 1); // création d'une carte à ajouter nommée carteAjouteeDouble (valet de pique)
    MainDeCartes main3 (carte3, carte4); // création d'une nouvelle main nommée main3 de deux cartes (carte3 et carte4)
    main3.doubler (carteAjouteeDouble); 
    assert (main3.getNbCartes()==3); // test du nombre de cartes 
    assert (main3.getSommeValeur()==21);// test de la somme des valeur
    assert (main3.getJoueToujours()==0); //test du booléen joueToujours qui doit être =1 car 21<=21
    assert (main3.getCrame()==0); // test du booléen crame qui doit être =0 car la joueur n'a pas cramé
    Carte carteAjouteeDouble2 (1,1,4); // création d'une carte à ajouter nommée carteAjouteeDouble2 (as de carreau)
    main3.doubler (carteAjouteeDouble2);   // ajout d'une carte pour voir si on peut doubler avec 3 carte (ce qui n'est pas possible)
    assert (main3.getNbCartes()==3); // test du nombre de cartes 
    assert (main3.getSommeValeur()==21);// test de la somme des valeur
    assert (main3.getJoueToujours()==0); //test du booléen joueToujours qui doit être =1 car 21<=21
    assert (main3.getCrame()==0); // test du booléen crame qui doit être =0 car la joueur n'a pas cramé
    cout <<"Test de la procédure doubler(carte) réalisé avec succès"<<endl;



    Carte carteAs (1,1,1); // création de deux nouvelles cartes (carteAs et carteBuche)
    Carte carteBuche (13,10,1); 
    MainDeCartes mainBlackJack(carteAs, carteBuche); // création d'une main BlackJack (10 et as)
    assert (carteAs.getValeur()==1); // test si la valeur de l'as est bien passé à 1 (valeur de base d'un as)   
    assert (mainBlackJack.getSommeValeur()==21); // test de la somme des valeur égal à 11 car l'as n'est pas encore égal à 11
    assert(mainBlackJack.verifBlackJack ()==1); // vérifie que la main n'est pas un BlackJack     
    assert(mainBlackJack.getIemeCarte(0).getValeur()==11); //verifie que la premiere carte du tableau est bien l'as 
    assert(mainBlackJack.getIemeCarte(1)==carteBuche);//verifie que la premiere carte du tableau est bien la buche 
    cout<<"Test de la procédure getIemeCarte(indice) réalisé avec succès"<<endl;



    mainBlackJack.verifAs();
    assert (mainBlackJack.mainDeJoueur[0].getValeur()==11); // test si la valeur de l'as est bien passé à 11 
    assert(mainBlackJack.verifBlackJack ()==1); // vérifie si la main est bien un BlackJack
    cout<<"Test de la procédure verifAs() et verifBlackJack() réalisé avec succès"<<endl;



    Carte carteAjouteeChange (6,6,1);
    Carte carteAsChange (1,1,1);
    MainDeCartes mainChange;
    mainChange.tirerCarte(carteAsChange);
    mainChange.tirerCarte(carteAsChange);// création d'une main avec deux as
    mainChange.changeCarte(carteAjouteeChange);
    assert (mainChange.getSommeValeur()==17);
    assert (mainChange.getNbCartes()==2);
    assert(mainChange.getIemeCarte(1)==carteAjouteeChange);
    assert (carteAjouteeChange==mainChange.mainDeJoueur[1]); // test si carte2 est bien la même carte que la carte d'indice 1 du tableau de la main de joueur.
    
    Carte carteAjouteeChange2 (7,7,1);
    Carte  carteDouble2(2,2,1);
    MainDeCartes mainChange2(carteDouble2,carteDouble2);
    mainChange2.changeCarte(carteAjouteeChange2);
    assert (mainChange2.getSommeValeur()==9);
    assert (mainChange2.getNbCartes()==2);
    assert(mainChange2.getIemeCarte(1)==carteAjouteeChange2);
    // test si carteAjouteeChange2 est bien la même carte que la carte d'indice 1 du tableau de la main de joueur.
    assert (carteAjouteeChange2==mainChange2.mainDeJoueur[1]); 
    cout<<"Test de la procédure changeCarte() réalisé avec succès"<<endl;

    mainChange2.vider();
    assert(mainChange2.getNbCartes()==0);
    assert(mainChange2.getSommeValeur()==0);
    cout<<"Test de la procédure vider() réalisé avec succès"<<endl;
    mainChange2.setSommeValeur(17);
    assert(mainChange2.getSommeValeur()==17);
    cout<<"Mutateur de sommeValeur OK"<<endl;
    assert(mainChange2.getJoueToujours()==1);
    mainChange2.rester();
    assert(mainChange2.getJoueToujours()==0);

    cout<<"Test de regression passé avec succès"<<endl;
    
}











