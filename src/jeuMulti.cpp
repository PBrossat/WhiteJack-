#include <vector>
#include <iostream> 
#include "JeuMulti.h"
#include "Joueur.h"
#include "Deck.h"
#include <time.h> 
#include <stdlib.h>
#include <cassert>
using namespace std; 




JeuMulti::JeuMulti ()
{

    unDeck.initDeck();
	unDeck.melangerDeck();
    nbManches=1;
    
}

JeuMulti::JeuMulti (unsigned int NiveauJoueur)
{

	unDeck.initDeck();
	unDeck.melangerDeck();
    tabJoueur.push_back(Joueur("Vous",0,2000));
    tabJoueur.push_back(Joueur("IA1",NiveauJoueur,2000));
    tabJoueur.push_back(Joueur("IA2",NiveauJoueur,2000));
    tabJoueur.push_back(Joueur("IA3",NiveauJoueur,2000));
    nbManches=1;
    nbJoueurs=4;
}


void JeuMulti::remplirJoueurs(unsigned int NiveauJoueur)
{
    assert(NiveauJoueur>0 && NiveauJoueur<4);
    if(tabJoueur.empty())
    {
        tabJoueur.push_back(Joueur("Vous",0,2000));
        tabJoueur.push_back(Joueur("IA1",NiveauJoueur,2000));
        tabJoueur.push_back(Joueur("IA2",NiveauJoueur,2000));
        tabJoueur.push_back(Joueur("IA3",NiveauJoueur,2000));
        nbJoueurs=4;
    }
}


JeuMulti::~JeuMulti()
{
    tabJoueur.clear();
}


void JeuMulti::eliminationJoueur() //procédure permettant d'eliminer un joueur si :
// soit il n'as plus de budget, soit il a le moins d'argent à la partie n={3,6,9}
{
    for (unsigned int i=0; i<tabJoueur.size(); i++) //pour i parcourant tout le tableau 
    {
        if(tabJoueur[i].getBudget()==0) // si le joueur à l'indice i à 0 de budget 
        {
            tabJoueur.erase(tabJoueur.begin()+i); //on supprime ce joueur 
            nbJoueurs--; // le nombre de joueur est mis à jour (-1)
        }

    }
    //si toute les conditions sont réspectées 
    if ( ((nbJoueurs==4)&&(nbManches==3)) || ((nbJoueurs==3)&&(nbManches==6))  || ((nbJoueurs==2)&&(nbManches==9))) 
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
    nbManches++;
}
//Attention au cas ou deux joueur ont le meme budget minimum !




void JeuMulti::initialisationMiseMulti()
{
    for (unsigned int i=0; i<tabJoueur.size(); i++) //parcours du tableau de joueurs
    {
        tabJoueur[i].setGain(0);//initialisation des gains de tout les joueurs à 0
    }

    vector<unsigned int>misePossible; //création d'un tableau avec les valeurs des mises possibles dedans
    misePossible.push_back(1);
    misePossible.push_back(10);
    misePossible.push_back(100);   
    misePossible.push_back(250);
    misePossible.push_back(500);
    srand (time(NULL));

	for (unsigned int i=0; i<tabJoueur.size(); i++) //parcours du tableau de joueurs
    {
        if(tabJoueur[i].getNiveau()!=0) //si le niveau du joueur est different de 0 (c'est une IA)
        {
            do
            {   //on tire un nombre entre 0 et 4 compris qui correspond a l'indice du tab que l'on vient de créer 
                unsigned int aleatoire = rand() % 5; 
                tabJoueur[i].setMise(misePossible[aleatoire]); //mise aléatoire 
            }while (tabJoueur[i].getBudget()<=tabJoueur[i].getMise()); //tant que c'est possible (par rapport à budget)
        }
       

    }

}

void JeuMulti::initialisationMise(const char touche)
{
	tabJoueur[0].setGain(0);
	switch(touche)
	{
		case 'a' :
			if(tabJoueur[0].getBudget()>=1) tabJoueur[0].setMise(1);
			break;

		case 'z' :
			if(tabJoueur[0].getBudget()>=10) tabJoueur[0].setMise(10);
			break;

		case 'e' :
			if(tabJoueur[0].getBudget()>=100) tabJoueur[0].setMise(100);
			break;

		case 'r' :
			if(tabJoueur[0].getBudget()>=250) tabJoueur[0].setMise(250);
			break;

		case 't' :
			if(tabJoueur[0].getBudget()>=500) tabJoueur[0].setMise(500);
			break;
	}
}


void JeuMulti::actionClavier(const char touche)
{
	switch(touche) 
	{
		case 't' :
		{
			Carte carteTiree = unDeck.distribuerCarte();
			tabJoueur[0].mainJoueur.tirerCarte(carteTiree);
			break;
		}
		case 'd' :
		{
			assert((tabJoueur[0].mainJoueur.getNbCartes()==2) && (tabJoueur[0].getBudget()>=tabJoueur[0].getMise()));
			tabJoueur[0].miser(tabJoueur[0].getMise());
			tabJoueur[0].setMise(tabJoueur[0].getMise()*2);
			Carte carteTiree = unDeck.distribuerCarte();
			tabJoueur[0].mainJoueur.doubler(carteTiree);
			break;
		}
		case 'r' :
		{
			tabJoueur[0].mainJoueur.rester();
			break;
		}
		case 'c' :
		{
			assert((tabJoueur[0].mainJoueur.getNbCartes()==2) && (tabJoueur[0].getBudget()>=tabJoueur[0].getMise()));
			assert((tabJoueur[0].mainJoueur.getIemeCarte(0).getValeur()==tabJoueur[0].mainJoueur.getIemeCarte(1).getValeur())
            ||(tabJoueur[0].mainJoueur.getIemeCarte(0).getRang()==tabJoueur[0].mainJoueur.getIemeCarte(1).getRang())); 
			tabJoueur[0].miser(tabJoueur[0].getMise());
			tabJoueur[0].setMise(tabJoueur[0].getMise()*2);
			Carte carteTiree = unDeck.distribuerCarte();
			tabJoueur[0].mainJoueur.changeCarte(carteTiree);
			break;
		}
	}
}


unsigned int JeuMulti::resultat(unsigned int indiceJoueur) 
{
	if(tabJoueur[indiceJoueur].mainJoueur.verifBlackJack())
	{
		if(mainCroupier.verifBlackJack())
		{
			tabJoueur[indiceJoueur].setBudget(tabJoueur[indiceJoueur].getMise());
			tabJoueur[indiceJoueur].setGain(tabJoueur[indiceJoueur].getMise());
			return 1;
		}
		else
		{
			tabJoueur[indiceJoueur].setBudget((2.5)*tabJoueur[indiceJoueur].getMise());
			tabJoueur[indiceJoueur].setGain((2.5)*tabJoueur[indiceJoueur].getMise());
			return 3;
		}
	}
	else if(!tabJoueur[indiceJoueur].mainJoueur.getCrame())
	{
		if(mainCroupier.getCrame())
		{
			tabJoueur[indiceJoueur].setBudget(2*tabJoueur[indiceJoueur].getMise());
			tabJoueur[indiceJoueur].setGain(2*tabJoueur[indiceJoueur].getMise());
			return 2;
		}
		else
		{
			if(tabJoueur[indiceJoueur].mainJoueur.getSommeValeur() > mainCroupier.getSommeValeur())
			{
				tabJoueur[indiceJoueur].setBudget(2*tabJoueur[indiceJoueur].getMise());	
				tabJoueur[indiceJoueur].setGain(2*tabJoueur[indiceJoueur].getMise());
				return 2;
			}
			else if(tabJoueur[indiceJoueur].mainJoueur.getSommeValeur() == mainCroupier.getSommeValeur())
			{
				tabJoueur[indiceJoueur].setBudget(tabJoueur[indiceJoueur].getMise());	
				tabJoueur[indiceJoueur].setGain(tabJoueur[indiceJoueur].getMise());
				return 1;
			}
			else if(tabJoueur[indiceJoueur].mainJoueur.getSommeValeur() < mainCroupier.getSommeValeur())
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	
}



void JeuMulti::initialisationJeuMulti()
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


void JeuMulti::finManche()
{
    for(unsigned int i=0; i<tabJoueur.size(); i++)
    {
        tabJoueur[i].mainJoueur.vider();
        tabJoueur[i].setMise(0);
        tabJoueur[i].setGain(0);
    }
	mainCroupier.vider();
    eliminationJoueur();    //l'incrémentation du nombre de parties est réalisée dans cette fonction
}


void JeuMulti::actionCroupier()
{
    bool tousCrame=1;
    for(unsigned int i=0; i<tabJoueur.size(); i++)
    {
        if(tabJoueur[i].mainJoueur.getCrame()==0)
        {
            tousCrame=0;
        }
    }
	mainCroupier.tirerCarte(deuxiemeCarteCroupier);
	if(tousCrame==0)
	{
		while(mainCroupier.getSommeValeur()<17)
		{
			Carte carteTiree = unDeck.distribuerCarte();
			mainCroupier.tirerCarte(carteTiree);

		}
	}
	mainCroupier.rester();
}


void JeuMulti::actionAmateur()
{
    Carte carteTiree;  
    for (unsigned int i=1; i<tabJoueur.size(); i++)
    {
        do{
        if (tabJoueur[i].mainJoueur.getSommeValeur()<16) 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }
        else
        {   
            
            tabJoueur[i].mainJoueur.rester();
        }
        }while(tabJoueur[i].mainJoueur.getJoueToujours()==1);
    }
}



void JeuMulti::actionIntermediaire()
{
    Carte carteTiree;  
    srand (time(NULL));
    // création d'une variable aléatoire qui permet de changer le pourcentage de chance de jouer en amateur ou en expert (entre 40 et 60)
    randPourcentage=rand() % 21+40; 
    //nb au hasard entre 1 et 100 qui permettra de definir si l'IA jouera avec un niveau amateur ou expert (55 % de chance de jouer en mode amateur) 
    nvHasard= rand() % 100+1; 
    
    if (nvHasard<=randPourcentage)
    {
        actionAmateur();
    } else 
    {
        actionExpert();
    }
}



void JeuMulti::actionExpert()
{

    Carte carteTiree;
    for (unsigned int i=1; i<tabJoueur.size(); i++)
    {
        while (tabJoueur[i].mainJoueur.getJoueToujours()==1)
        {
        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()>=8))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()>=8)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1))))
        //si la main du joueur est As et 8 (ou 9 ou buche) alors il reste quoi qu'il en soit
        {
            tabJoueur[i].mainJoueur.rester();

        }

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==7))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==7)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&((mainCroupier.getSommeValeur()>=3)&&(mainCroupier.getSommeValeur()<=6))))
        //si la main du joueur est As et 7 et que le croupier à entre 3 et 6 alors il double
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.doubler(carteTiree);
        }

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==7))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==7)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&((mainCroupier.getSommeValeur()==2)||(mainCroupier.getSommeValeur()==7)||(mainCroupier.getSommeValeur()==8))))
        //si la main du joueur est As et 7 et que le croupier a 2 ou 7 ou 8 alors il reste 
        {
            tabJoueur[i].mainJoueur.rester();
        }

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==7))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==7)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&(mainCroupier.getSommeValeur()>=9)))
        //si la main du joueur est As et 7 et que le croupier à 9 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }   

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==6))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==6)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&((mainCroupier.getSommeValeur()>=3)&&(mainCroupier.getSommeValeur()<=6))))
        //main joueur = As et 6 et que le croupier à entre 3 et 6 alors il double 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.doubler(carteTiree); 
        }

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==6))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==6)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&((mainCroupier.getSommeValeur()==2)||(mainCroupier.getSommeValeur()>=7))))
        //main joueur = as et 6 et que le croupier à 2 ou 7 ous plus alors il tire 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==5))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==5)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&(((mainCroupier.getSommeValeur()>=2)&&(mainCroupier.getSommeValeur()<=3))||(mainCroupier.getSommeValeur()>=7))))
        //main joueur = as et 5 et que le croupier à entre 2 et 3 ou plus de 7 alors il tire 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==5))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==5)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&(((mainCroupier.getSommeValeur()>=4)&&(mainCroupier.getSommeValeur()<=6)))))
        //main joueur = as et 5 et que le croupier à entre 4 et 6 alors il double 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.doubler(carteTiree); 
        }

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==4))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==4)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&(((mainCroupier.getSommeValeur()>=2)&&(mainCroupier.getSommeValeur()<=3))||(mainCroupier.getSommeValeur()>=7))))
        //main joueur = as et 4 et que le croupier à entre 2 et 3 ou plus de 7 alors il tire 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }
        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==4))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==4)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&(((mainCroupier.getSommeValeur()>=4)&&(mainCroupier.getSommeValeur()<=6)))))
        //main joueur = as et 4 et que le croupier à entre 4 et 6 alors il double 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.doubler(carteTiree); 
        }

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==3))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==3)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1))
        )&&(((mainCroupier.getSommeValeur()>=2)&&(mainCroupier.getSommeValeur()<=4))||(mainCroupier.getSommeValeur()>=7))))
        //main joueur = as et 3 et que le croupier à entre 2 et 4 ou plus de 7 alors il tire 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==3))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==3)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&(((mainCroupier.getSommeValeur()>=5)&&(mainCroupier.getSommeValeur()<=6)))))
        //main joueur = as et 3 et que le croupier à entre 5 et 6 alors il double 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.doubler(carteTiree); 
        }

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==2))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==2)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&(((mainCroupier.getSommeValeur()>=2)&&(mainCroupier.getSommeValeur()<=4))||(mainCroupier.getSommeValeur()>=7))))
        //main joueur = as et 2 et que le croupier à entre 2 et 4 ou plus de 7 alors il tire 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((tabJoueur[i].mainJoueur.getNbCartes()==2)&&((((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==2))||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==2)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1)))
        &&(((mainCroupier.getSommeValeur()>=5)&&(mainCroupier.getSommeValeur()<=6))))))
        //main joueur = as et 2 et que le croupier à entre 5 et 6 alors il double 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.doubler(carteTiree); 
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==1)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==1))
        ||((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==8)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==8))))
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.changeCarte(carteTiree);
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==10)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==10)))
        //main joueur = 10 et 10 alors il reste
        {
            tabJoueur[i].mainJoueur.rester();
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==9)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==9))
        &&((mainCroupier.getSommeValeur()==7)||(mainCroupier.getSommeValeur()>=10))))
        //main joueur = 9 et 9 et le croupier à 7 ou 10 ou plus alors il reste 
        {
            tabJoueur[i].mainJoueur.rester();
        }
        
        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==9)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==9))
        &&((mainCroupier.getSommeValeur()<=6)||((mainCroupier.getSommeValeur()>=8)
        &&(mainCroupier.getSommeValeur()<=9)))))
        // main joueur = 9 et 9 et que le croupier à 6 ou moins ou 8 ou 9 alors il splitte
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.changeCarte(carteTiree);
        }  

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==7)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==7))
        &&((mainCroupier.getSommeValeur()<=7))))
        // main joueur = 7 et 7 et que le croupier à 7 ou moins alors il splitte
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.changeCarte(carteTiree);
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==7)&&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==7))
        &&((mainCroupier.getSommeValeur()>=8))))
        // main joueur = 7 et 7 et que le croupier à 8 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==6)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==6))
        &&((mainCroupier.getSommeValeur()<=6))))
        // main joueur = 6 et 6 et que le croupier à 6 ou moins alors il splitte
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.changeCarte(carteTiree);
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==6)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==6))
        &&((mainCroupier.getSommeValeur()>=7))))
        // main joueur = 6 et 6 et que le croupier à 7 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
    
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==5)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==5))
        &&((mainCroupier.getSommeValeur()<=9))))
        // main joueur = 5 et 5 et que le croupier à 9 ou moins alors il double 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.doubler(carteTiree); 
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==5)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==5))
        &&((mainCroupier.getSommeValeur()>=10))))
        // main joueur = 5 et 5 et que le croupier à 10 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==4)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==4))
        &&((mainCroupier.getSommeValeur()<=4)||(mainCroupier.getSommeValeur()>=7))))
        // main joueur = 4 et 4 et que le croupier à 4 ou moins ou 7 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree); 
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==4)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==4))
        &&((mainCroupier.getSommeValeur()>=5)&&(mainCroupier.getSommeValeur()<=6))))
        // main joueur = 4 et 4 et que le croupier à 5 ou 6 alors il splitte
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.changeCarte(carteTiree);
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==3)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==3))
        &&(mainCroupier.getSommeValeur()>=8)))
        // main joueur = 3 et 3 et que le croupier à 8 ou plus alors il tire 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree); 
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==3)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==3))
        &&(mainCroupier.getSommeValeur()<=7)))
        // main joueur = 3 et 3 et que le croupier à 7 ou moins il splitte
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.changeCarte(carteTiree);
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==2)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==2))
        &&(mainCroupier.getSommeValeur()>=8)))
        // main joueur = 2 et 2 et que le croupier à 8 ou plus alors il tire 
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree); 
            
        }

        if ((tabJoueur[i].mainJoueur.getNbCartes()==2)
        &&(((tabJoueur[i].mainJoueur.getIemeCarte(0).getRang()==2)
        &&(tabJoueur[i].mainJoueur.getIemeCarte(1).getRang()==2))
        &&(mainCroupier.getSommeValeur()<=7)))
        // main joueur = 2 et 2 et que le croupier à 7 ou moins il splitte
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.changeCarte(carteTiree);
        }

        if (tabJoueur[i].mainJoueur.getSommeValeur()>=17)
        //si le score du joueur est 17 ou plus alors il reste 
        {
        
            tabJoueur[i].mainJoueur.rester(); 
        }

        if ((tabJoueur[i].mainJoueur.getSommeValeur()<=16)
        &&(tabJoueur[i].mainJoueur.getSommeValeur()>=13)
        &&(mainCroupier.getSommeValeur()<=6))
        //si le score du joueur est entre 16 et 13 compris et que le croupier a 6 ou moins alors il reste
        {
            tabJoueur[i].mainJoueur.rester();
        }
        
        if ((tabJoueur[i].mainJoueur.getSommeValeur()==12)
        &&(mainCroupier.getSommeValeur()<=6)
        &&(mainCroupier.getSommeValeur()>=4))
        //si le score du joueur est 12 et que le croupier à entre 4 et 6 compris alors il reste 
        {
            tabJoueur[i].mainJoueur.rester();
        }

        if((tabJoueur[i].mainJoueur.getSommeValeur()<=16)
        &&(tabJoueur[i].mainJoueur.getSommeValeur()>=13)
        &&(mainCroupier.getSommeValeur()>=7))
        //si le score du joueur est entre 16 et 13 compris et que le croupier a 7 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if ((tabJoueur[i].mainJoueur.getSommeValeur()==12)
        &&(mainCroupier.getSommeValeur()<=3))
        //si le score du joueur est de 12 et que le croupier a 3 ou moins alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if ((tabJoueur[i].mainJoueur.getSommeValeur()==12)
        &&(mainCroupier.getSommeValeur()>=7))
        //si le score du joueur est de 12 et que le croupier a 7 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if ((tabJoueur[i].mainJoueur.getSommeValeur()==11)
        &&(mainCroupier.getSommeValeur()<=10))
        //si le score du joueur est de 11 et que le croupier à 10 ou moins alors il double (si il a deux carte) ou il tire
        {
            if(tabJoueur[i].mainJoueur.getNbCartes()==2)
            {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.doubler(carteTiree);
            }else 
                {
                carteTiree = unDeck.distribuerCarte();
                tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
                }
        }

        if((tabJoueur[i].mainJoueur.getSommeValeur()==11)
        &&(mainCroupier.getSommeValeur()==11))
        //si le score du joueur est de 11 et que le croupier à 11 alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if ((tabJoueur[i].mainJoueur.getSommeValeur()==10)
        &&(mainCroupier.getSommeValeur()<=9))
        //si le score du joueur est de 10 et que le croupier à 9 ou moins alors il double (si il a deux carte) ou il tire
        {
            if(tabJoueur[i].mainJoueur.getNbCartes()==2)
            {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.doubler(carteTiree);
            }else 
                {
                carteTiree = unDeck.distribuerCarte();
                tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
                }
        }

        if((tabJoueur[i].mainJoueur.getSommeValeur()==10)
        &&(mainCroupier.getSommeValeur()>=10))
        //si le score du joueur est de 10 et que le croupier à 10 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if((tabJoueur[i].mainJoueur.getSommeValeur()==9)
        &&((mainCroupier.getSommeValeur()==2)
        ||(mainCroupier.getSommeValeur()>=6)))
        //si le score du joueur est de 9 et que le croupier à 2 ou 6 ou plus alors il tire
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }

        if((tabJoueur[i].mainJoueur.getSommeValeur()==9)
        &&((mainCroupier.getSommeValeur()>=3)
        &&(mainCroupier.getSommeValeur()<=5)))
        //si le score du joueur est de 9 et que le croupier à entre 3 et 5 compris alors il double (si il a deux carte) ou il tire
        {
            if(tabJoueur[i].mainJoueur.getNbCartes()==2)
            {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.doubler(carteTiree);
            }else 
                {
                carteTiree = unDeck.distribuerCarte();
                tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
                }
        }

        if((tabJoueur[i].mainJoueur.getSommeValeur()>=5)
        &&(tabJoueur[i].mainJoueur.getSommeValeur()<=8))
        //si le joueur à etre 5 et 8 compris il tire quoi qu'il en soit
        {
            carteTiree = unDeck.distribuerCarte();
            tabJoueur[i].mainJoueur.tirerCarte(carteTiree);
        }
        }
    }
}




void JeuMulti::testRegression() const
{

    JeuMulti unJeuMultiParDefaut; // création d'un jeu multi par défaut 
    assert (unJeuMultiParDefaut.tabJoueur.size()==0); // taille =0   
    assert(unJeuMultiParDefaut.nbManches==1);
    Joueur joueurParDefaut; //création d'un joueur par défaut
    unJeuMultiParDefaut.tabJoueur.push_back(joueurParDefaut); //on ajoute ce joueur au jeu
    assert (unJeuMultiParDefaut.tabJoueur.size()==1); // taille =1
    cout<<"Test constructeur par défaut OK"<<endl;
    


    JeuMulti unJeuMulti(3); //3 signifie niveau=expert 
    assert (unJeuMulti.tabJoueur.size()==4); // taille =4
    assert (unJeuMulti.tabJoueur[0].nom=="Vous"); //test sur le joueur reel
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
    unJeuMulti.nbManches=6; //6 eme partie
    unJeuMulti.eliminationJoueur(); //il reste 3 joueur ET nous sommes a la partie n°6
    assert (unJeuMulti.tabJoueur.size()==2); //elimination du joueur 3 (indice 2)
    unJeuMulti.nbManches=9; //9 eme partie
    unJeuMulti.eliminationJoueur(); //il reste 2 joueur ET nous sommes a la partie n°9
    assert (unJeuMulti.tabJoueur.size()==1); //elimination du joueur 2(indice 1) car il à 1800 contre 2000 pour le joueur 1 (indice 0)
    cout<<"Test de eliminationJoueur() OK"<<endl;


    JeuMulti unJeuRemplir;
    unJeuRemplir.remplirJoueurs(3);
    for (unsigned int i=0; i<tabJoueur.size(); i++)
    {
    assert (unJeuRemplir.tabJoueur[i].getNiveau()==3);
    }
    assert (unJeuRemplir.tabJoueur.size()==4);
    unJeuRemplir.finManche();
    for (unsigned int i=0; i<tabJoueur.size(); i++)
    {
    assert (unJeuRemplir.tabJoueur[i].mainJoueur.getNbCartes()==0);
    assert (unJeuRemplir.tabJoueur[i].getMise()==0);
    assert (unJeuRemplir.tabJoueur[i].getGain()==0);
    }
    cout<<"Test de la procédure remplirJoueur() et finManche() OK"<<endl;



    JeuMulti unJeuMulti2(3); //création d'un nouveau jeuMulti (jeuMulti2)
    unJeuMulti2.initialisationMiseMulti();
    for (unsigned int i=0; i<unJeuMulti2.tabJoueur.size(); i++)
    {
    assert (unJeuMulti2.tabJoueur[i].getGain()==0); //verification que gain = 0 pour tout les joueurs
    }
   
    for (unsigned int i=1; i<unJeuMulti2.tabJoueur.size(); i++)
    {
        assert ((unJeuMulti2.tabJoueur[i].getMise()==1)||(unJeuMulti2.tabJoueur[i].getMise()==10)
        ||(unJeuMulti2.tabJoueur[i].getMise()==100)||(unJeuMulti2.tabJoueur[i].getMise()==250)
        ||(unJeuMulti2.tabJoueur[i].getMise()==500));
        //verification que les mises jouées sont valides (1 ou 10 ou 100 ou 250 ou 500)
    }
    cout<<"Test de initialisationMiseMulti() OK"<<endl;



    unJeuMulti2.initialisationJeuMulti();
    for (unsigned int i=0; i<tabJoueur.size(); i++)
    {
        assert (tabJoueur[i].mainJoueur.getNbCartes()==2);
    }
    assert(unJeuMulti2.mainCroupier.getNbCartes()==1);
    cout<<"Test de initialisationJeuMulti() OK"<<endl;


    
    

    Carte carteAjouteeAs(1,1,1);
    Carte carteAjoutee2(2,2,1);
    Carte carteAjoutee3(3,3,2);
    Carte carteAjoutee4(4,4,1);
    Carte carteAjoutee5(5,5,4);
    Carte carteAjoutee6(6,6,3);
    Carte carteAjoutee7(7,7,3);
    Carte carteAjoutee8(8,8,1);
    Carte carteAjoutee9(9,9,2);
    Carte carteAjoutee10(10,10,3); // definition de chaque carte (de l'as au 10)


    

    JeuMulti jeuIA(1);
    jeuIA.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee8); // test score <17
    jeuIA.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee2);
    assert(jeuIA.tabJoueur[1].mainJoueur.getNbCartes()==2);
    jeuIA.actionAmateur();
    assert(jeuIA.tabJoueur[1].mainJoueur.getNbCartes()>=2);
    cout<<"Test actionAmateur() OK"<<endl;



    JeuMulti jeuIA2(1);
    jeuIA2.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee10); //test score >17
    jeuIA2.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee8);
    assert(jeuIA2.tabJoueur[1].mainJoueur.getNbCartes()==2);
    jeuIA.actionAmateur();
    assert(jeuIA2.tabJoueur[1].mainJoueur.getNbCartes()==2);
    cout<<"Test actionAmateur() OK"<<endl;



    JeuMulti jeuIA3(1);
    jeuIA3.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee10); //test score =17
    jeuIA3.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee7);
    assert(jeuIA3.tabJoueur[1].mainJoueur.getNbCartes()==2);
    jeuIA.actionAmateur();
    assert(jeuIA3.tabJoueur[1].mainJoueur.getNbCartes()==2);
    cout<<"Test actionAmateur() OK"<<endl;



    JeuMulti jeuIAExpert1(3);
    jeuIAExpert1.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee8);
    jeuIAExpert1.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee2);//score joueur=10 => le joueur doit tirer
    jeuIAExpert1.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee8);
    jeuIAExpert1.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee9);// score joueur=17 => le joueur doit rester
    jeuIAExpert1.tabJoueur[3].mainJoueur.tirerCarte(carteAjouteeAs);
    jeuIAExpert1.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee8);// main joueur=as et 8 => le joueur doit rester
    jeuIAExpert1.mainCroupier.tirerCarte(carteAjoutee10); // le croupier à 10 
    jeuIAExpert1.actionExpert();
    assert(jeuIAExpert1.tabJoueur[1].mainJoueur.getNbCartes()>=2);
    assert (jeuIAExpert1.tabJoueur[2].mainJoueur.getNbCartes()==2);
    assert (jeuIAExpert1.tabJoueur[3].mainJoueur.getNbCartes()==2);
    cout<<"Test de jeuIAExpert1() OK"<<endl;



    JeuMulti jeuIAExpert2(3);
    jeuIAExpert2.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee10);
    jeuIAExpert2.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee10);//main joueur = double 10 => il doit rester
    jeuIAExpert2.tabJoueur[2].mainJoueur.tirerCarte(carteAjouteeAs);
    jeuIAExpert2.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee5);// main joueur= as et 5 => le joueur doit tirer
    jeuIAExpert2.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee10);
    jeuIAExpert2.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee4);// score joueur=14  => le joueur doit rester tirer
    jeuIAExpert2.mainCroupier.tirerCarte(carteAjouteeAs);// le croupier a un as 
    jeuIAExpert2.actionExpert();
    assert(jeuIAExpert2.tabJoueur[1].mainJoueur.getNbCartes()==2);
    assert (jeuIAExpert2.tabJoueur[2].mainJoueur.getNbCartes()>=2);
    assert (jeuIAExpert2.tabJoueur[3].mainJoueur.getNbCartes()>=2);
    cout<<"Test de jeuIAExpert2() OK"<<endl;



    JeuMulti jeuIAExpert3(3);
    jeuIAExpert3.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee6);
    jeuIAExpert3.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee6);//main joueur = double 6 => il doit tirer
    jeuIAExpert3.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee2);
    jeuIAExpert3.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee2);// main joueur= double 2 => le joueur doit tirer
    jeuIAExpert3.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee9);
    jeuIAExpert3.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee2);// score joueur=11  => le joueur doit rester
    jeuIAExpert3.mainCroupier.tirerCarte(carteAjoutee9);// le croupier a un 9
    jeuIAExpert3.actionExpert();
    assert(jeuIAExpert3.tabJoueur[1].mainJoueur.getNbCartes()>=2);
    assert (jeuIAExpert3.tabJoueur[2].mainJoueur.getNbCartes()>=2);
    assert (jeuIAExpert3.tabJoueur[3].mainJoueur.getNbCartes()==3);
    cout<<"Test de jeuIAExpert3() OK"<<endl;



    JeuMulti jeuIAExpert4(3);
    jeuIAExpert4.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee5);
    jeuIAExpert4.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee5);//main joueur = double 5 => il doit doubler
    jeuIAExpert4.tabJoueur[2].mainJoueur.tirerCarte(carteAjouteeAs);
    jeuIAExpert4.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee4);// main joueur= as et 4 => le joueur doit doubler
    jeuIAExpert4.tabJoueur[3].mainJoueur.tirerCarte(carteAjouteeAs);
    jeuIAExpert4.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee7);// main joueur= as et 7  => le joueur doit rester doubler
    jeuIAExpert4.mainCroupier.tirerCarte(carteAjoutee6);// le croupier a un 6
    jeuIAExpert4.actionExpert();
    assert(jeuIAExpert4.tabJoueur[1].mainJoueur.getNbCartes()==3);
    assert (jeuIAExpert4.tabJoueur[2].mainJoueur.getNbCartes()==3);
    assert (jeuIAExpert4.tabJoueur[3].mainJoueur.getNbCartes()==3);
    cout<<"Test de jeuIAExpert4() OK"<<endl;



    JeuMulti jeuIAExpert5(3);
    jeuIAExpert5.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee3);
    jeuIAExpert5.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee4);
    jeuIAExpert5.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee3);//le score du joueur est de 10 avec 3 carte => il doit tirer
    //(pas doubler)
    jeuIAExpert5.tabJoueur[2].mainJoueur.tirerCarte(carteAjouteeAs);
    jeuIAExpert5.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee4);// main du joueur = AS et 4 => il doit tirer 
    jeuIAExpert5.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee10);
    jeuIAExpert5.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee2);
    jeuIAExpert5.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee3);  // le score du joueur 15 => il doit tirer
    jeuIAExpert5.mainCroupier.tirerCarte(carteAjoutee10); // le croupier a 10
    jeuIAExpert5.actionExpert();
    assert(jeuIAExpert5.tabJoueur[1].mainJoueur.getNbCartes()>=3);
    assert (jeuIAExpert5.tabJoueur[2].mainJoueur.getNbCartes()>=3);
    assert (jeuIAExpert5.tabJoueur[3].mainJoueur.getNbCartes()>=3);
    cout<<"Test de jeuIAExpert5() OK"<<endl;
    


    JeuMulti jeuIAIntermediaire(2);
    jeuIAIntermediaire.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee10);
    jeuIAIntermediaire.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee7);//score joueur=17
    jeuIAIntermediaire.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee9);
    jeuIAIntermediaire.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee2);// score joueur=11 
    jeuIAIntermediaire.tabJoueur[3].mainJoueur.tirerCarte(carteAjouteeAs);
    jeuIAIntermediaire.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee8);// main joueur=as et 8 
    jeuIAIntermediaire.mainCroupier.tirerCarte(carteAjoutee10); // le croupier à 10 
    jeuIAIntermediaire.actionIntermediaire();
    assert (jeuIAIntermediaire.tabJoueur[1].mainJoueur.getNbCartes()==2); // dans tout les cas il doit rester 
    //(que ce soit en amateur ou en expert)
    if (jeuIAIntermediaire.nvHasard<=jeuIAIntermediaire.randPourcentage) // si l'IA2 est en mode amateur alors elle tire 
    //(moins de 17) sinon elle double 
    {
        assert (jeuIAIntermediaire.tabJoueur[2].mainJoueur.getNbCartes()>=3); // mode amateur 
    }else 
    {
        assert (jeuIAIntermediaire.tabJoueur[2].mainJoueur.getNbCartes()==3); // mode expert
    }
    assert (jeuIAIntermediaire.tabJoueur[3].mainJoueur.getNbCartes()==2); // dans tout les cas il doit rester 
    // (que ce soit en amateur ou en expert)
    cout<<"Test de jeuIAIntermediaire() OK"<<endl;



    JeuMulti jeuIAIntermediaire2(2);
    jeuIAIntermediaire2.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee4);
    jeuIAIntermediaire2.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee6);//score joueur=10
    jeuIAIntermediaire2.tabJoueur[2].mainJoueur.tirerCarte(carteAjouteeAs);
    jeuIAIntermediaire2.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee7);// main du joueur= As et 7 
    jeuIAIntermediaire2.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee5);
    jeuIAIntermediaire2.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee5);// main joueur= double 5
    jeuIAIntermediaire2.mainCroupier.tirerCarte(carteAjoutee2); // le croupier à 10 
    jeuIAIntermediaire2.actionIntermediaire();
    if (jeuIAIntermediaire2.nvHasard<=jeuIAIntermediaire.randPourcentage) // si l'IA1 est en mode amateur alors elle tire 
    //(moins de 17) sinon il double 
    {
        assert (jeuIAIntermediaire2.tabJoueur[1].mainJoueur.getNbCartes()>=3); // mode amateur 
    }else 
    {
        assert (jeuIAIntermediaire2.tabJoueur[1].mainJoueur.getNbCartes()==3); // mode expert
    }

    assert (jeuIAIntermediaire2.tabJoueur[2].mainJoueur.getNbCartes()==2); // dans tout les cas l'IA2 reste

    if (jeuIAIntermediaire2.nvHasard<=jeuIAIntermediaire.randPourcentage) // si l'IA3 est en mode amateur alors elle tire
    // (moins de 17) sinon elle double 
    {
        assert (jeuIAIntermediaire2.tabJoueur[1].mainJoueur.getNbCartes()>=3); // mode amateur 
    }else 
    {
        assert (jeuIAIntermediaire2.tabJoueur[1].mainJoueur.getNbCartes()==3); // mode expert
    }
    cout<<"Test de jeuIAIntermediaire2() OK"<<endl;



    JeuMulti jeuIAIntermediaire3(2);
    jeuIAIntermediaire3.tabJoueur[1].mainJoueur.tirerCarte(carteAjouteeAs);
    jeuIAIntermediaire3.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee2);//main joueur = As et deux 
    jeuIAIntermediaire3.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee7);
    jeuIAIntermediaire3.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee4); // score du joueur = 11 avec 2 cartes
    jeuIAIntermediaire3.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee7);
    jeuIAIntermediaire3.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee2);
    jeuIAIntermediaire3.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee2);  // score du joueur= 11 avec 3 cartes
    jeuIAIntermediaire3.mainCroupier.tirerCarte(carteAjoutee10); // le croupier à 10 
    jeuIAIntermediaire3.actionIntermediaire();
    assert (jeuIAIntermediaire3.tabJoueur[1].mainJoueur.getNbCartes()>=3); // dans tout les cas l'IA tire

    if (jeuIAIntermediaire3.nvHasard<=jeuIAIntermediaire.randPourcentage) // si l'IA3 est en mode amateur alors elle tire 
    //(moins de 17) sinon elle double 
    {
        assert (jeuIAIntermediaire3.tabJoueur[2].mainJoueur.getNbCartes()>=3); // mode amateur 
    }else 
    {
        assert (jeuIAIntermediaire3.tabJoueur[2].mainJoueur.getNbCartes()==3); // mode expert
    }
    
    assert  (jeuIAIntermediaire3.tabJoueur[3].mainJoueur.getNbCartes()>=3); // dans tout les cas l'IA tire
    cout<<"Test de jeuIAIntermediaire3() OK"<<endl;
    

    JeuMulti jeuIAIntermediaire4(2);
    // toute les IA ont le même jeu mais n'auront pas toute le même comportement selon leur niveau
    jeuIAIntermediaire4.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee10);
    jeuIAIntermediaire4.tabJoueur[1].mainJoueur.tirerCarte(carteAjoutee4);//score du joueur= 14 
    jeuIAIntermediaire4.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee10);
    jeuIAIntermediaire4.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee4); // score du joueur = 14
    jeuIAIntermediaire4.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee10);
    jeuIAIntermediaire4.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee4); // score du joueur = 14
    jeuIAIntermediaire4.mainCroupier.tirerCarte(carteAjoutee6); // le croupier à 6
    jeuIAIntermediaire4.actionIntermediaire();
        if (jeuIAIntermediaire4.nvHasard<=jeuIAIntermediaire.randPourcentage) // si l'IA3 est en mode amateur alors elle tire 
        //(moins de 17) sinon elle reste
        {
            assert (jeuIAIntermediaire4.tabJoueur[1].mainJoueur.getNbCartes()>=3); // mode amateur 
        }else 
        {
            assert (jeuIAIntermediaire4.tabJoueur[1].mainJoueur.getNbCartes()==2); // mode expert  
        }
        if (jeuIAIntermediaire4.nvHasard<=jeuIAIntermediaire.randPourcentage) // si l'IA3 est en mode amateur alors elle tire 
        //(moins de 17) sinon elle reste
        {
            assert (jeuIAIntermediaire4.tabJoueur[2].mainJoueur.getNbCartes()>=3); // mode amateur
        }else 
        {
            assert (jeuIAIntermediaire4.tabJoueur[2].mainJoueur.getNbCartes()==2); // mode expert
        }
        if (jeuIAIntermediaire4.nvHasard<=jeuIAIntermediaire.randPourcentage) // si l'IA3 est en mode amateur alors elle tire 
        //(moins de 17) sinon elle reste
        {
            assert (jeuIAIntermediaire4.tabJoueur[3].mainJoueur.getNbCartes()>=3); // mode amateur
        }else 
        {
            assert (jeuIAIntermediaire4.tabJoueur[3].mainJoueur.getNbCartes()==2); // mode expert
        }
        
    JeuMulti jeuIAIntermediaire5(2);
    jeuIAIntermediaire5.tabJoueur[1].mainJoueur.tirerCarte(carteAjouteeAs);
    jeuIAIntermediaire5.tabJoueur[1].mainJoueur.tirerCarte(carteAjouteeAs);//main du joueur = double as
    jeuIAIntermediaire5.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee9);
    jeuIAIntermediaire5.tabJoueur[2].mainJoueur.tirerCarte(carteAjoutee9); // main du joueur = double neuf
    jeuIAIntermediaire5.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee2);
    jeuIAIntermediaire5.tabJoueur[3].mainJoueur.tirerCarte(carteAjoutee2); // main du joueur = double deux
    jeuIAIntermediaire5.mainCroupier.tirerCarte(carteAjoutee2); // le croupier à 2
    jeuIAExpert5.actionExpert();
    assert (jeuIAIntermediaire5.tabJoueur[1].mainJoueur.getNbCartes()>=2);
    assert (jeuIAIntermediaire5.tabJoueur[1].mainJoueur.getIemeCarte(0).getRang()==1);
    assert (jeuIAIntermediaire5.tabJoueur[2].mainJoueur.getNbCartes()>=2);
    assert (jeuIAIntermediaire5.tabJoueur[2].mainJoueur.getIemeCarte(0).getValeur()==9);
    assert (jeuIAIntermediaire5.tabJoueur[3].mainJoueur.getNbCartes()>=2);
    assert (jeuIAIntermediaire5.tabJoueur[3].mainJoueur.getIemeCarte(0).getValeur()==2);

    
    cout<<"Test de jeuIAIntermediaire4() OK"<<endl;
    


}

