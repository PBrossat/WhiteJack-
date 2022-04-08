#include <vector>
#include <iostream> 
#include "jeuMulti.h"
#include "Joueur.h"
#include "Deck.h"
#include "jeuTxt.h"
#include <time.h> 
#include <stdlib.h>
#include <cassert>
using namespace std; 




jeuMulti::jeuMulti ()
{

    unDeck.initDeck();
	unDeck.melangerDeck();
    nbPartie=1;
    
}


jeuMulti::jeuMulti (unsigned int NiveauJoueur)
{

	unDeck.initDeck();
	unDeck.melangerDeck();
    tabJoueur.push_back(Joueur("moi",0,2000));
    tabJoueur.push_back(Joueur("IA1",NiveauJoueur,2000));
    tabJoueur.push_back(Joueur("IA2",NiveauJoueur,2000));
    tabJoueur.push_back(Joueur("IA3",NiveauJoueur,2000));
    nbPartie=1;
}



void jeuMulti::eliminationJoueur() //procédure permettant d'eliminer un joueur si : soit il n'as plus de budget, soit il a le moins d'argent à la partie n={3,6,9}
{
unsigned int nbJoueurs=tabJoueur.size(); // nbJoueur= à la taille du tableau 
    for (unsigned int i=0; i<tabJoueur.size(); i++) //pour i parcourant tout le tableau 
    {
        if(tabJoueur[i].getBudget()==0) // si le joueur à l'indice i à 0 de budget 
        {
            tabJoueur.erase(tabJoueur.begin()+i); //on supprime ce joueur 
            nbJoueurs--; // le nombre de joueur est mis à jour (-1)
        }

    }

    if ( ((nbJoueurs==4)&&(nbPartie==3)) || ((nbJoueurs==3)&&(nbPartie==6))  || ((nbJoueurs==2)&&(nbPartie==9))) //si toute les conditions sont réspectées 
        {
            float min=tabJoueur[0].getBudget(); //initialisation de min à la valeur du budget du joueur d'indice 0 
            unsigned int indiceMinimum=0; // initialisation d'indiceMinimum à l'indice 0 par défaut
            for (unsigned int j=1; j<tabJoueur.size() ; j++) //on commence la boucle à 1 pour eviter de tester avec j=0 (inutile)
                {
                    if (tabJoueur[j].getBudget()<min) //si le budget du joueur d'indice j est inférieur à min 
                        {
                            min= tabJoueur[j].getBudget(); // MAJ de min avec l'indice du joueur 
                            indiceMinimum= j; //MAJ de indiceMinimum avec l'indice du joueur 
                        }
                }
            tabJoueur.erase(tabJoueur.begin()+indiceMinimum); //on supprime le joueur avec le budget le plus bas
            nbJoueurs--; // le nombre de joueur est mis à jour (-1)
        }
    nbPartie++;
}
//Attention au cas ou deux joueur ont le meme budget minimum !




void jeuMulti::initialisationMiseMulti()
{


    for (unsigned int i=0; i<tabJoueur.size(); i++) //parcours du tableau de joueurs
    {
        tabJoueur[i].setGain(0);//initialisation des gains de tout les joueurs à 0
    }

    vector<unsigned int>misePossible; //création d'un tableau avec les valeurs des mises possibles dedans
    misePossible.push_back(100);
    misePossible.push_back(200);
    misePossible.push_back(300);   
    misePossible.push_back(500);
    misePossible.push_back(1000);
    srand (time(NULL));
   // unsigned int aleatoire = rand() % 5; //on tire un nombre entre 0 et 4 compris qui correspond a l'indice du tab que l'on vient de créer 

	for (unsigned int i=0; i<tabJoueur.size(); i++) //parcours du tableau de joueurs
    {
        if(tabJoueur[i].getNiveau()!=0) //si le niveau du joueur est different de 0 (c'est une IA)
        {
            do
            {
                unsigned int aleatoire = rand() % 5; //on tire un nombre entre 0 et 4 compris qui correspond a l'indice du tab que l'on vient de créer 
                tabJoueur[i].setMise(misePossible[aleatoire]); //mise aléatoire 
            }while (tabJoueur[i].getBudget()<=tabJoueur[i].getMise()); //tant que c'est possible (par rapport à budget)
        }
        // else Jeu.tabJoueur[i].initialisationMise(touche);               cas du joueur reel (Attention à comment rentrer la mise que l'on veut avec la version graphique)

    }

}





void jeuMulti::initialisationJeuMulti()
{   
    Carte carteTiree; //initilisation des cartes qui vont être tirées
    Carte carteCroupier;
    Carte deuxiemeCarteCroupier;
    for (unsigned int i=0; i<tabJoueur.size(); i++) //distribution d'une carte à chaque joueur 
        {   
            tabJoueur[i].miser(tabJoueur[i].getMise());
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

   	carteCroupier = unDeck.distribuerCarte(); //distribution d'une carte au croupier 
	mainCroupier.tirerCarte(carteCroupier);

    for (unsigned int i=0; i<tabJoueur.size(); i++) //distribution d'une deuxième carte à chaque joueur 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

     deuxiemeCarteCroupier = unDeck.distribuerCarte(); //création d'une deuxième carte pour le croupier (invisible à cet instant précis)
}




void jeuMulti::actionAmateur()
{
    Carte carteTiree;  
    for (unsigned int i=1; i<=tabJoueur.size(); i++)
    {
        do{
        if (tabJoueur[i].mainJoueur.getSommeValeur()<17) 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }
        else
        {   
            tabJoueur[i].mainJoueur.rester();
        }
        }while(tabJoueur[i].mainJoueur.getCrame()==0);
    }
}


void jeuMulti::actionMedium()
{
    Carte carteTiree;  
    for (unsigned int i=1; i<=tabJoueur.size(); i++)
    {









    }

}





void jueMulti::actionExpert()
{

    Carte carteTiree;
    for (unsigned int i=1; i<=tabJoueur.size(); i++)
    {
        do 
        {
        if (tabJoueur[i].mainJoueur.getSommeValeur()>=17)
        //si le score du joueur est 17 ou plus alors il reste 
        {
            tabJoueur[i].mainJoueur.rester(); 
        }
        if ((tabJoueur[i].mainJoueur.getSommeValeur()<=16)&&(tabJoueur[i].mainJoueur.getSommeValeur()>=13)&&(mainCroupier.getSommeValeur()<=6))
        //si le score du joueur est entre 16 et 13 compris et que le croupier a 6 ou moins alors il reste
        {
            tabJoueur[i].mainJoueur.rester();
        }
        if ((tabJoueur[i].mainJoueur.getSommeValeur()==12)&&(mainCroupier.getSommeValeur()<=6)&&(mainCroupier.getSommeValeur()>=4))
        //si le score du joueur est 12 et que le croupier à entre 4 et 6 compris alors il reste 
        {
            tabJoueur[i].mainJoueur.rester();
        }
        if((tabJoueur[i].mainJoueur.getSommeValeur()<=16)&&(tabJoueur[i].mainJoueur.getSommeValeur()>=13)&&(mainCroupier.getSommeValeur()>=7))
        //si le score du joueur est entre 16 et 13 compris et que le croupier a 7 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }
        if ((tabJoueur[i].mainJoueur.getSommeValeur()==12)&&(mainCroupier.getSommeValeur()<=3))
        //si le score du joueur est de 12 et que le croupier a 3 ou moins alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }
        if ((tabJoueur[i].mainJoueur.getSommeValeur()==12)&&(mainCroupier.getSommeValeur()>=7))
        //si le score du joueur est de 12 et que le croupier a 7 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }
        if ((tabJoueur[i].mainJoueur.getSommeValeur()==11)&&(mainCroupier.getSommeValeur()<=10))
        //si le score du joueur est de 11 et que le croupier à 10 ou moins alors il double 
        {
            tabJoueur[i].mainJoueur.doubler();
        }
        if((tabJoueur[i].mainJoueur.getSommeValeur()==11)&&(mainCroupier.getSommeValeur()==11))
        //si le score du joueur est de 11 et que le croupier à 11 alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }
        if ((tabJoueur[i].mainJoueur.getSommeValeur()==10)&&(mainCroupier.getSommeValeur()<=9))
        //si le score du joueur est de 10 et que le croupier à 9 ou moins alors il double 
        {
            tabJoueur[i].mainJoueur.doubler();
        }
         if((tabJoueur[i].mainJoueur.getSommeValeur()==10)&&(mainCroupier.getSommeValeur()>=10))
        //si le score du joueur est de 10 et que le croupier à 10 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }
    }


}




void jeuMulti::testRegression() const
{

    jeuMulti unJeuMultiParDefaut; // création d'un jeu multi par défaut 
    assert (unJeuMultiParDefaut.tabJoueur.size()==0); // taille =0   
    assert(unJeuMultiParDefaut.nbPartie==1);
    Joueur joueurParDefaut; //création d'un joueur par défaut
    unJeuMultiParDefaut.tabJoueur.push_back(joueurParDefaut); //on ajoute ce joueur au jeu
    assert (unJeuMultiParDefaut.tabJoueur.size()==1); // taille =1
    cout<<"Test constructeur par défaut OK"<<endl;
    


    jeuMulti unJeuMulti(3); //3 signifie niveau=expert 
    assert (unJeuMulti.tabJoueur.size()==4); // taille =4
    assert (unJeuMulti.tabJoueur[0].nom=="moi"); //test sur le joueur reel
    assert (unJeuMulti.tabJoueur[0].getNiveau()==0);
    assert (unJeuMulti.tabJoueur[0].getBudget()==2000);
    assert (unJeuMulti.tabJoueur[1].nom=="IA1");
    assert (unJeuMulti.tabJoueur[2].nom=="IA2");
    assert (unJeuMulti.tabJoueur[3].nom=="IA3");
    for (int i=1; i<4; i++) //test sur les IA
    {
    assert (unJeuMulti.tabJoueur[i].getNiveau()==3);
    assert (unJeuMulti.tabJoueur[i].getBudget()==2000);
    }
    cout<<"Test du constructeur avec paramètre OK"<<endl;



    unJeuMulti.tabJoueur[3].setBudget(-2000); //le budget du joueur 4 (indice 3) est nul
    unJeuMulti.eliminationJoueur(); //elimination du du joueur 4 car il n'a plus d'argent
    assert (unJeuMulti.tabJoueur.size()==3); //verification qu'il est bien eliminé

    unJeuMulti.tabJoueur[1].setBudget(-200); //budget du joueur 2 = 1800
    unJeuMulti.tabJoueur[2].setBudget(-300); //budget du joueur 2 = 1700
    unJeuMulti.nbPartie=6; //6 eme partie
    unJeuMulti.eliminationJoueur(); //il reste 3 joueur ET nous sommes a la partie n°6
    assert (unJeuMulti.tabJoueur.size()==2); //elimination du joueur 3 (indice 2)

    unJeuMulti.nbPartie=9; //9 eme partie
    unJeuMulti.eliminationJoueur(); //il reste 2 joueur ET nous sommes a la partie n°9
    assert (unJeuMulti.tabJoueur.size()==1); //elimination du joueur 2(indice 1) car il à 1800 contre 2000 pour le joueur 1 (indice 0)
    cout<<"Test de eliminationJoueur() OK"<<endl;


    jeuMulti unJeuMulti2(3); //création d'un nouveau jeuMulti (jeuMulti2)
    unJeuMulti2.initialisationMiseMulti();
    for (unsigned int i=0; i<unJeuMulti2.tabJoueur.size(); i++)
    {
    assert (unJeuMulti2.tabJoueur[i].getGain()==0); //verification que gain = 0 pour tout les joueurs
    }
   
    for (unsigned int i=1; i<unJeuMulti2.tabJoueur.size(); i++)
    {
        assert ((unJeuMulti2.tabJoueur[i].getMise()==100)||(unJeuMulti2.tabJoueur[i].getMise()==200)||(unJeuMulti2.tabJoueur[i].getMise()==300)||(unJeuMulti2.tabJoueur[i].getMise()==500)||(unJeuMulti2.tabJoueur[i].getMise()==1000));
        //verification que les mises jouées sont valides (100 ou 200 ou 300 ou 500 ou 1000)
    }
    cout<<"Test de initialisationMiseMulti() OK"<<endl;



    unJeuMulti2.initialisationJeuMulti();
    for (unsigned int i=0; i<tabJoueur.size(); i++)
    {
        assert (tabJoueur[i].mainJoueur.getNbCartes()==2);
    }
    assert(unJeuMulti2.mainCroupier.getNbCartes()==1);
    cout<<"Test de initialisationJeuMulti() OK"<<endl;


}
