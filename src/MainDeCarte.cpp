#include "MainDeCarte.h"
#include <iostream>
#include <cassert>
#include <vector>


using namespace std;

MainDeCarte::MainDeCarte ()
{
    //vector<Carte>mainDeJoueur(0);

    nbCartes=0; // le nombre de carte est initialisé à 0
    sommeValeur=0; //la somme des valeurs est initialisé à 0
    joueToujours=1; // initialisation du booléen à VRAI (1)
    crame=0; //le joueur à moins de 22
}



MainDeCarte::MainDeCarte (const Carte& carte1, const Carte& carte2)
{   
    
    //vector<Carte>mainDeJoueur(0);

    mainDeJoueur.push_back (carte1);// ajoute carte 1 à la main 
    mainDeJoueur.push_back (carte2);// ajoute carte 2 à la main 
    nbCartes=2; // le nombre de carte est initialisé à 2 
    sommeValeur=carte1.getValeur()+carte2.getValeur(); // somme des valeur mise à jour 
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




bool MainDeCarte::verifBlackJack ()
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


Carte MainDeCarte::getIemeCarte(unsigned int indice) const
{
    assert((indice< mainDeJoueur.size())&&(mainDeJoueur.size()!=0));
    return mainDeJoueur[indice];
}




void MainDeCarte::tirerCarte (const Carte& carteAjoutee)
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
   



void MainDeCarte::doubler (const Carte& carteAjoutee)
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


void MainDeCarte::vider()
{
    mainDeJoueur.clear();
    nbCartes=0;
    crame=0;
    sommeValeur=0;
    joueToujours=1;
}



void MainDeCarte::verifAs()
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




//TESTER VERIFAS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! DOUBLER 

void MainDeCarte::testRegression() const
{
    MainDeCarte mainVide; //creation d'une main de base main1
    assert (mainVide.getNbCartes()==0);
    assert (mainVide.getSommeValeur()==0);
    assert (mainVide.getJoueToujours()==1);
    assert (mainVide.getCrame()==0);
    cout<<"Création de la main par défaut OK"<<endl;


    Carte carte1(2,2,1); //creation de deux cartes (carte1 et carte2)
    Carte carte2(3,3,2);
    MainDeCarte main(carte1,carte2); //creation d'une main de deux cartes (carte1 et carte2)
    assert (main.getNbCartes()==2); // test du nombre de cartes 
    assert (main.getSommeValeur()==5);// test de la somme des valeur 
    assert (main.getJoueToujours()==1); //test du booléen joueToujours?
    assert (main.getCrame()==0); // test du booléen crame
    assert (carte1==main.mainDeJoueur[0]); // test si carte1 est bien la même carte que la carte d'indice 0 du tableau de la main de joueur.
    assert (carte2==main.mainDeJoueur[1]); // test si carte2 est bien la même carte que la carte d'indice 1 du tableau de la main de joueur.
    assert (carte1.getSigne()==1); // test si le signe de la nouvelle carte est bien celui attribué 
    assert (carte2.getSigne()==2); // test si le signe de la nouvelle carte est bien celui attribué  
    cout<<"Création de main2 réaliser avec succès"<<endl;



    Carte carteAjoutee(8,8,4); //création d'une carte à ajouter
    main.tirerCarte(carteAjoutee); 
    assert (main.getNbCartes()==3); // test du nombre de cartes 
    assert (main.getSommeValeur()==13);// test de la somme des valeur 
    assert (main.getJoueToujours()==1); //test du booléen joueToujours
    assert (main.getCrame()==0); // test du booléen crame
    assert (carteAjoutee==main.mainDeJoueur[2]); // test si carteAjoutee est bien la même carte que la carte d'indice 2 du tableau de la main de joueur.
    assert (carteAjoutee.getSigne()==4); // test si le signe de la nouvelle carte est bien celui attribué 
    cout<<"Ajout d'une carte réaliser avec succès"<<endl;



    Carte carteAjoutee2(11,10,1);
    main.tirerCarte(carteAjoutee2);
    assert (main.getNbCartes()==4); // test du nombre de cartes 
    assert (main.getSommeValeur()==23);// test de la somme des valeur
    assert (main.getJoueToujours()==0); //test du booléen joueToujours qui doit être =0 car 23>21
    assert (main.getCrame()==1); // test du booléen crame qui doit être =1 car 23>21
    assert (carteAjoutee2==main.mainDeJoueur[3]); // test si carteAjoutee2 est bien la même carte que la carte d'indice 3 du tableau de la main de joueur.
    assert (carteAjoutee2.getSigne()==1); // test si le signe de la nouvelle carte est bien celui attribué
    cout<<"La carte ajoutée a fait cramer le joueur avec succès"<<endl;


    Carte carte3 (7,7,3); // création de deux nouvelles cartes (carte3 et carte4)
    Carte carte4 (4,4,3); 
    Carte carteAjouteeDouble (11, 10, 1); // création d'une carte à ajouter nommée carteAjouteeDouble (valet de pique)
    MainDeCarte main3 (carte3, carte4); // création d'une nouvelle main nommée main3 de deux cartes (carte3 et carte4)
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
    cout <<"Teste de la procédure doubler réaliser avec succès"<<endl;

    Carte carteAs (1,1,1); // création de deux nouvelles cartes (carteAs et carteBuche)
    Carte carteBuche (13,10,1); 
    MainDeCarte mainBlackJack(carteAs, carteBuche); // création d'une main BlackJack (10 et as)
    assert (carteAs.getValeur()==1); // test si la valeur de l'as est bien passé à 1 (valeur de base d'un as)   
    assert (mainBlackJack.getSommeValeur()==11); // test de la somme des valeur égal à 11 car l'as n'est pas encore égal à 11
    assert(mainBlackJack.verifBlackJack ()==0); // vérifie que la main n'est pas un BlackJack 
    mainBlackJack.verifAs();
    assert (mainBlackJack.mainDeJoueur[0].getValeur()==11); // test si la valeur de l'as est bien passé à 11 
    assert(mainBlackJack.verifBlackJack ()==1); // vérifie si la main est bien un BlackJack
    cout<<"Teste de la procédure verifAs() et verifBlackJack() réaliser avec succès"<<endl;


    cout<<"Test de regression passé avec succès"<<endl;
    
}




//fonction vérifAs à faire à chaque tirage de carte (pour le croupier aussi) et au début du jeu (si jamais deux as)

// boucle parcours la main du joueur
//     si on rencontre une carte avec un rang de 1 (un as)

//         si la valeur de l'as est 1
//             si score + 10 <= 21
//             alors setValeur de as pour passer de 1 à 11
//             et setSommeValeur(getSommeValeur+10)
//             sinon rien
//         si la valeur de l'as est 11
//             si j'ai cramé alors
//                 set valeur de as pour passer sa valeur à 1
//                 et setSommeValeur(getSommeValeur-10)







