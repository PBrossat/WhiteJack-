#include <cassert>
#include <time.h>
#include "jeuSfml.h"
#include <stdlib.h>
#include <iostream>

using namespace sf;
using namespace std;

sfmlJeu::sfmlJeu () : jeu() { 
    window = new RenderWindow(VideoMode(1400,750), "BlackJack");
    dimx = window->getSize().x;
    dimy = window->getSize().y;
    actionMiser=0;
    finJeu=0;
}

void sfmlJeu::sfmlInit() {

//Chargement images coeur 

    if (!t1deCoeur.loadFromFile("data/1_Coeur.png")) 
    {
        cout << "Error data/1_Coeur.png non found" << endl;
    }
    else 
    {
        s1deCoeur.setTexture(t1deCoeur);
    }
    
    if (!t2deCoeur.loadFromFile("data/2_Coeur.png")) 
    {
        cout << "Error data/2_Coeur.png non found" << endl;
    }
    else 
    {
        s2deCoeur.setTexture(t2deCoeur);
    }
    
    if (!t3deCoeur.loadFromFile("data/3_Coeur.png")) 
    {
        cout << "Error data/3_Coeur.png non found" << endl;
    }
    else 
    {
        s3deCoeur.setTexture(t3deCoeur);
    }
    
    if (!t4deCoeur.loadFromFile("data/4_Coeur.png")) 
    {
        cout << "Error data/4_Coeur.png non found" << endl;
    }
    else 
    {
        s4deCoeur.setTexture(t4deCoeur);
    }
    
    if (!t5deCoeur.loadFromFile("data/5_Coeur.png")) 
    {
        cout << "Error data/5_Coeur.png non found" << endl;
    }
    else 
    {
        s5deCoeur.setTexture(t5deCoeur);
    }
    
    if (!t6deCoeur.loadFromFile("data/6_Coeur.png")) 
    {
        cout << "Error data/6_Coeur.png non found" << endl;
    }
    else 
    {
        s6deCoeur.setTexture(t6deCoeur);
    }
    
    if (!t7deCoeur.loadFromFile("data/7_Coeur.png")) 
    {
        cout << "Error data/7_Coeur.png non found" << endl;
    }
    else 
    {
        s7deCoeur.setTexture(t7deCoeur);
    }
    
    if (!t8deCoeur.loadFromFile("data/8_Coeur.png")) 
    {
        cout << "Error data/8_Coeur.png non found" << endl;
    }
    else 
    {
        s8deCoeur.setTexture(t8deCoeur);
    }
    
    if (!t9deCoeur.loadFromFile("data/9_Coeur.png")) 
    {
        cout << "Error data/9_Coeur.png non found" << endl;
    }
    else 
    {
        s9deCoeur.setTexture(t9deCoeur);
    }
    
    if (!t10deCoeur.loadFromFile("data/10_Coeur.png")) 
    {
        cout << "Error data/10_Coeur.png non found" << endl;
    }
    else 
    {
        s10deCoeur.setTexture(t10deCoeur);
    }
    
    if (!t11deCoeur.loadFromFile("data/11_Coeur.png")) 
    {
        cout << "Error data/11_Coeur.png non found" << endl;
    }
    else 
    {
        s11deCoeur.setTexture(t11deCoeur);
    }
    
    if (!t12deCoeur.loadFromFile("data/12_Coeur.png")) 
    {
        cout << "Error data/12_Coeur.png non found" << endl;
    }
    else 
    {
        s12deCoeur.setTexture(t12deCoeur);
    }
    
    if (!t13deCoeur.loadFromFile("data/13_Coeur.png")) 
    {
        cout << "Error data/13_Coeur.png non found" << endl;
    }
    else 
    {
        s13deCoeur.setTexture(t13deCoeur);
    }




//Chargement images carreau

    if (!t1deCarreau.loadFromFile("data/1_Carreau.png")) 
    {
        cout << "Error data/1_Carreau.png non found" << endl;
    }
    else 
    {
        s1deCarreau.setTexture(t1deCarreau);
    }
    
    if (!t2deCarreau.loadFromFile("data/2_Carreau.png")) 
    {
        cout << "Error data/2_Carreau.png non found" << endl;
    }
    else 
    {
        s2deCarreau.setTexture(t2deCarreau);
    }
    
    if (!t3deCarreau.loadFromFile("data/3_Carreau.png")) 
    {
        cout << "Error data/3_Carreau.png non found" << endl;
    }
    else 
    {
        s3deCarreau.setTexture(t3deCarreau);
    }
    
    if (!t4deCarreau.loadFromFile("data/4_Carreau.png")) 
    {
        cout << "Error data/4_Carreau.png non found" << endl;
    }
    else 
    {
        s4deCarreau.setTexture(t4deCarreau);
    }
    
    if (!t5deCarreau.loadFromFile("data/5_Carreau.png")) 
    {
        cout << "Error data/5_Carreau.png non found" << endl;
    }
    else 
    {
        s5deCarreau.setTexture(t5deCarreau);
    }
    
    if (!t6deCarreau.loadFromFile("data/6_Carreau.png")) 
    {
        cout << "Error data/6_Carreau.png non found" << endl;
    }
    else 
    {
        s6deCarreau.setTexture(t6deCarreau);
    }
    
    if (!t7deCarreau.loadFromFile("data/7_Carreau.png")) 
    {
        cout << "Error data/7_Carreau.png non found" << endl;
    }
    else 
    {
        s7deCarreau.setTexture(t7deCarreau);
    }
    
    if (!t8deCarreau.loadFromFile("data/8_Carreau.png")) 
    {
        cout << "Error data/8_Carreau.png non found" << endl;
    }
    else 
    {
        s8deCarreau.setTexture(t8deCarreau);
    }
    
    if (!t9deCarreau.loadFromFile("data/9_Carreau.png")) 
    {
        cout << "Error data/9_Carreau.png non found" << endl;
    }
    else 
    {
        s9deCarreau.setTexture(t9deCarreau);
    }
    
    if (!t10deCarreau.loadFromFile("data/10_Carreau.png")) 
    {
        cout << "Error data/10_Carreau.png non found" << endl;
    }
    else 
    {
        s10deCarreau.setTexture(t10deCarreau);
    }
    
    if (!t11deCarreau.loadFromFile("data/11_Carreau.png")) 
    {
        cout << "Error data/11_Carreau.png non found" << endl;
    }
    else 
    {
        s11deCarreau.setTexture(t11deCarreau);
    }
    
    if (!t12deCarreau.loadFromFile("data/12_Carreau.png")) 
    {
        cout << "Error data/12_Carreau.png non found" << endl;
    }
    else 
    {
        s12deCarreau.setTexture(t12deCarreau);
    }
    
    if (!t13deCarreau.loadFromFile("data/13_Carreau.png")) 
    {
        cout << "Error data/13_Carreau.png non found" << endl;
    }
    else 
    {
        s13deCoeur.setTexture(t13deCarreau);
    }
  


  //Chargement images Piques

    if (!t1dePiques.loadFromFile("data/1_Piques.png")) 
    {
        cout << "Error data/1_Piques.png non found" << endl;
    }
    else 
    {
        s1dePiques.setTexture(t1dePiques);
    }
    
    if (!t2dePiques.loadFromFile("data/2_Piques.png")) 
    {
        cout << "Error data/2_Piques.png non found" << endl;
    }
    else 
    {
        s2dePiques.setTexture(t2dePiques);
    }
    
    if (!t3dePiques.loadFromFile("data/3_Piques.png")) 
    {
        cout << "Error data/3_Piques.png non found" << endl;
    }
    else 
    {
        s3dePiques.setTexture(t3dePiques);
    }
    
    if (!t4dePiques.loadFromFile("data/4_Piques.png")) 
    {
        cout << "Error data/4_Piques.png non found" << endl;
    }
    else 
    {
        s4dePiques.setTexture(t4dePiques);
    }
    
    if (!t5dePiques.loadFromFile("data/5_Piques.png")) 
    {
        cout << "Error data/5_Piques.png non found" << endl;
    }
    else 
    {
        s5dePiques.setTexture(t5dePiques);
    }
    
    if (!t6dePiques.loadFromFile("data/6_Piques.png")) 
    {
        cout << "Error data/6_Piques.png non found" << endl;
    }
    else 
    {
        s6dePiques.setTexture(t6dePiques);
    }
    
    if (!t7dePiques.loadFromFile("data/7_Piques.png")) 
    {
        cout << "Error data/7_Piques.png non found" << endl;
    }
    else 
    {
        s7dePiques.setTexture(t7dePiques);
    }
    
    if (!t8dePiques.loadFromFile("data/8_Piques.png")) 
    {
        cout << "Error data/8_Piques.png non found" << endl;
    }
    else 
    {
        s8dePiques.setTexture(t8dePiques);
    }
    
    if (!t9dePiques.loadFromFile("data/9_Piques.png")) 
    {
        cout << "Error data/9_Piques.png non found" << endl;
    }
    else 
    {
        s9dePiques.setTexture(t9dePiques);
    }
    
    if (!t10dePiques.loadFromFile("data/10_Piques.png")) 
    {
        cout << "Error data/10_Piques.png non found" << endl;
    }
    else 
    {
        s10dePiques.setTexture(t10dePiques);
    }
    
    if (!t11dePiques.loadFromFile("data/11_Piques.png")) 
    {
        cout << "Error data/11_Piques.png non found" << endl;
    }
    else 
    {
        s11dePiques.setTexture(t11dePiques);
    }
    
    if (!t12dePiques.loadFromFile("data/12_Piques.png")) 
    {
        cout << "Error data/12_Piques.png non found" << endl;
    }
    else 
    {
        s12dePiques.setTexture(t12dePiques);
    }
    
    if (!t13dePiques.loadFromFile("data/13_Piques.png")) 
    {
        cout << "Error data/13_Piques.png non found" << endl;
    }
    else 
    {
        s13dePiques.setTexture(t13dePiques);
    } 


    //Chargement images Trefles

    if (!t1deTrefles.loadFromFile("data/1_Trèfles.png")) 
    {
        cout << "Error data/1_Trèfles.png non found" << endl;
    }
    else 
    {
        s1deTrefles.setTexture(t1deTrefles);
    }
    
    if (!t2deTrefles.loadFromFile("data/2_Trèfles.png")) 
    {
        cout << "Error data/2_Trèfles.png non found" << endl;
    }
    else 
    {
        s2deTrefles.setTexture(t2deTrefles);
    }
    
    if (!t3deTrefles.loadFromFile("data/3_Trèfles.png")) 
    {
        cout << "Error data/3_Trèfles.png non found" << endl;
    }
    else 
    {
        s3deTrefles.setTexture(t3deTrefles);
    }
    
    if (!t4deTrefles.loadFromFile("data/4_Trèfles.png")) 
    {
        cout << "Error data/4_Trèfles.png non found" << endl;
    }
    else 
    {
        s4deTrefles.setTexture(t4deTrefles);
    }
    
    if (!t5deTrefles.loadFromFile("data/5_Trèfles.png")) 
    {
        cout << "Error data/5_Trèfles.png non found" << endl;
    }
    else 
    {
        s5deTrefles.setTexture(t5deTrefles);
    }
    
    if (!t6deTrefles.loadFromFile("data/6_Trèfles.png")) 
    {
        cout << "Error data/6_Trèfles.png non found" << endl;
    }
    else 
    {
        s6deTrefles.setTexture(t6deTrefles);
    }
    
    if (!t7deTrefles.loadFromFile("data/7_Trèfles.png")) 
    {
        cout << "Error data/7_Trèfles.png non found" << endl;
    }
    else 
    {
        s7deTrefles.setTexture(t7deTrefles);
    }
    
    if (!t8deTrefles.loadFromFile("data/8_Trèfles.png")) 
    {
        cout << "Error data/8_Trèfles.png non found" << endl;
    }
    else 
    {
        s8deTrefles.setTexture(t8deTrefles);
    }
    
    if (!t9deTrefles.loadFromFile("data/9_Trèfles.png")) 
    {
        cout << "Error data/9_Trèfles.png non found" << endl;
    }
    else 
    {
        s9deTrefles.setTexture(t9deTrefles);
    }
    
    if (!t10deTrefles.loadFromFile("data/10_Trèfles.png")) 
    {
        cout << "Error data/10_Trèfles.png non found" << endl;
    }
    else 
    {
        s10deTrefles.setTexture(t10deTrefles);
    }
    
    if (!t11deTrefles.loadFromFile("data/11_Trèfles.png")) 
    {
        cout << "Error data/11_Trèfles.png non found" << endl;
    }
    else 
    {
        s11deTrefles.setTexture(t11deTrefles);
    }
    
    if (!t12deTrefles.loadFromFile("data/12_Trèfles.png")) 
    {
        cout << "Error data/12_Trèfles.png non found" << endl;
    }
    else 
    {
        s12deTrefles.setTexture(t12deTrefles);
    }
    
    if (!t13deTrefles.loadFromFile("data/13_Trèfles.png")) 
    {
        cout << "Error data/13_Trèfles.png non found" << endl;
    }
    else 
    {
        s13deTrefles.setTexture(t13deTrefles);
    } 


//Chargement des autres images nécessaires

    if (!tCardBack.loadFromFile("data/cardBack.png")) 
    {
        cout << "Error data/cardBack.png non found" << endl;
    }
    else 
    {
        sCardBack.setTexture(tCardBack);
    }

    if (!tDeck.loadFromFile("data/Deck.png")) 
    {
        cout << "Error data/Deck.png non found" << endl;
    }
    else 
    {
        sDeck.setTexture(tDeck);
    } 

    if (!tFond.loadFromFile("data/fond.png")) 
    {
        cout << "Error data/fond.png non found" << endl;
    }
    else 
    {
        rsFond.setTexture(&tFond);
    }

    if (!t1.loadFromFile("data/1.png")) 
    {
        cout << "Error data/1.png non found" << endl;
    }
    else 
    {
        s1.setTexture(t1);
    }

    if (!t10.loadFromFile("data/10.png")) 
    {
        cout << "Error data/10.png non found" << endl;
    }
    else 
    {
        s10.setTexture(t10);
    }

    if (!t100.loadFromFile("data/100.png")) 
    {
        cout << "Error data/100.png non found" << endl;
    }
    else 
    {
        s100.setTexture(t100);
    }

    if (!t250.loadFromFile("data/250.png")) 
    {
        cout << "Error data/250.png non found" << endl;
    }
    else 
    {
        s250.setTexture(t250);
    }

    if (!t500.loadFromFile("data/500.png")) 
    {
        cout << "Error data/500.png non found" << endl;
    }
    else 
    {
        s500.setTexture(t500);
    }

    if (!tDoubler.loadFromFile("data/doubler.png")) 
    {
        cout << "Error data/doubler.png non found" << endl;
    }
    else 
    {
        sDoubler.setTexture(tDoubler);
    }

    if (!tRester.loadFromFile("data/rester.png")) 
    {
        cout << "Error data/rester.png non found" << endl;
    }
    else 
    {
        sRester.setTexture(tRester);
    }

    if (!tTirer.loadFromFile("data/tirer.png")) 
    {
        cout << "Error data/tirer.png non found" << endl;
    }
    else 
    {
        sTirer.setTexture(tTirer);
    }

    if (!tChanger.loadFromFile("data/changer.png")) 
    {
        cout << "Error data/changer.png non found" << endl;
    }
    else 
    {
        sChanger.setTexture(tChanger);
    }


    // if (!m_font.loadFromFile("data/DejaVuSansCondensed.ttf")) {cout << "Error data/DejaVuSansCondensed.ttf non found" << endl;}
    // else {
    //     m_text.setFont(m_font);
    //     m_text.setString("Pacman");
    //     m_text.setCharacterSize(30);
    //     m_text.setFillColor(Color::Blue);
    //     m_text.setPosition(Vector2f(270,30));
    // }
    // if (!m_soundbuffer.loadFromFile("data/son.wav")) {cout << "Error data/son.wav non found" << endl;}
    // else {
    //     m_sound.setBuffer(m_soundbuffer);
    // }

}


sfmlJeu::~sfmlJeu () 
{
    if (window != NULL) delete window;
}





//ATTENTION AFFICHAGE DE CERTAINES CARTES NE FONCTIONNE PAS

void sfmlJeu::afficherMainDeCarteCroupier(MainDeCarte mainJoueur)
{
    unsigned int positionx = dimx/2-150;
    unsigned int positiony = dimy/2-230;

    for (unsigned int i=0; i<mainJoueur.getNbCartes(); i++)
    {
        Sprite carte;
            if (mainJoueur.getIemeCarte(i).getRang()== 1)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s1dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s1deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s1deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s1deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 2)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s2dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s2deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s2deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s2deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 3)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s3dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s3deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s3deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s3deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 4)
			{
			    if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s4dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s4deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s4deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s4deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 5)
			{
                if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s5dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s5deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s5deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s5deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 6)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s6dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s6deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s6deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s6deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 7)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s7dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s7deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s7deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s7deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 8)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s8dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s8deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s8deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s8deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 9)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s9dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s9deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s9deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s9deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 10)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s10dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s10deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s10deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s10deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 11)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s11dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s11deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s11deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s11deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 12)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s12dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s12deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s12deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s12deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 13)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s13dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s13deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s13deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s13deCarreau;
				}
			}
			carte.setPosition(positionx, positiony);
            carte.setScale(1.5,1.5);
			positionx += 150;
            positiony -= 50;
			window->draw(carte);
    }
}

void sfmlJeu::afficherMainDeCarteJoueur(MainDeCarte mainJoueur)
{
    unsigned int positionx = dimx/2-150;
    unsigned int positiony = dimy-700;

    for (unsigned int i=0; i<mainJoueur.getNbCartes(); i++)
    {
        Sprite carte;
            if (mainJoueur.getIemeCarte(i).getRang()== 1)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s1dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s1deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s1deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s1deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 2)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s2dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s2deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s2deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s2deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 3)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s3dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s3deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s3deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s3deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 4)
			{
			    if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s4dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s4deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s4deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s4deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 5)
			{
                if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s5dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s5deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s5deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s5deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 6)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s6dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s6deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s6deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s6deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 7)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s7dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s7deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s7deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s7deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 8)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s8dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s8deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s8deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s8deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 9)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s9dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s9deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s9deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s9deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 10)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s10dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s10deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s10deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s10deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 11)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s11dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s11deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s11deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s11deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 12)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s12dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s12deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s12deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s12deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 13)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s13dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s13deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s13deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s13deCarreau;
				}
			}
			carte.setPosition(positionx, positiony);
            carte.setScale(1.5,1.5);
			positionx += 150;
            positiony -= 50;
			window->draw(carte);
    }
}




void sfmlJeu::sfmlAff() 
{
    window->clear(Color(230, 240, 255, 255)); 
    rsFond.setSize(Vector2f(dimx,dimy));
    window->draw(rsFond);

    s1.setScale(1.75,1.75);
    s10.setScale(1.75,1.75);
    s100.setScale(1.75,1.75);
    s250.setScale(1.75,1.75);
    s500.setScale(1.75,1.75);


    if(actionMiser==1)
    {
        afficherMainDeCarteCroupier(jeu.mainCroupier);
        afficherMainDeCarteJoueur(jeu.joueurSolo.mainJoueur);
        sRester.setPosition(dimx-200,dimy-100);
        window->draw(sRester);
        sTirer.setPosition(dimx-200,dimy-200);
        window->draw(sTirer);
        if((jeu.joueurSolo.mainJoueur.getNbCartes()==2) && (jeu.joueurSolo.getBudget()>=jeu.joueurSolo.getMise())) //si le joueur peut doubler (2 cartes et peut doubler sa mise)
        {
            sDoubler.setPosition(dimx-200,dimy-300);
            window->draw(sDoubler);
            sChanger.setPosition(dimx-200,dimy-400);
            window->draw(sChanger);
        }
        else    //on déplace le sprite de doubler hors de la fenetre pour s'assurer que le joueur ne puisse doubler
        {
            sDoubler.setPosition(dimx+1,dimy+1);
            sChanger.setPosition(dimx+1,dimy+1);
            window->draw(sDoubler);
            window->draw(sChanger);
        }
    }
    else if(jeu.joueurSolo.getBudget()>=500)
    {
        s1.setPosition(dimx/2-225,dimy-200);
        window->draw(s1);

        s10.setPosition(dimx/2-75,dimy-200);
        window->draw(s10);

        s100.setPosition(dimx/2+75,dimy-200);
        window->draw(s100);

        s250.setPosition(dimx/2+225,dimy-200);
        window->draw(s250);

        s500.setPosition(dimx/2+375,dimy-200);
        window->draw(s500);
    }
    else if(jeu.joueurSolo.getBudget()>=250)
    {
        s1.setPosition(dimx/2-150,dimy-200);
        window->draw(s1);

        s10.setPosition(dimx/2-75,dimy-200);
        window->draw(s10);

        s100.setPosition(dimx/2+75,dimy-200);
        window->draw(s100);

        s250.setPosition(dimx/2+225,dimy-200);
        window->draw(s250);
    }
    else if(jeu.joueurSolo.getBudget()>=100)
    {
        s1.setPosition(dimx/2-150,dimy-200);
        window->draw(s1);

        s10.setPosition(dimx/2,dimy-200);
        window->draw(s10);

        s100.setPosition(dimx/2+150,dimy-200);
        window->draw(s100);
    }
    else if(jeu.joueurSolo.getBudget()>=10)
    {
        s1.setPosition(dimx/2-150,dimy-200);
        window->draw(s1);

        s10.setPosition(dimx/2+150,dimy-200);
        window->draw(s10);
    }
    else if(jeu.joueurSolo.getBudget()>=1)
    {
        s1.setPosition(dimx/2,dimy-200);
        window->draw(s1);
    }
   


    //Largeur d'une carte = environ 230
    //Hauteur d'une carte = environ 150

    // Test affichage de deux cartes 
    // unsigned int positionx = dimx/2-150;
    // unsigned int positiony = dimy-700;
    // s1deTrefles.setScale(1.5,1.5);
    // s1deTrefles.setPosition(positionx, positiony);
	// positionx += 150;
    // positiony -= 50;
	// window->draw(s1deTrefles);
    // s1deTrefles.setPosition(positionx, positiony);
    // positionx += 150;
    // positiony -= 50;
    // window->draw(s1deTrefles);
    

    // // Ecrire un titre par dessus
    // m_window->draw(m_text);

    window->display();
}



void sfmlJeu::sfmlBoucle() {

    while ((window->isOpen())&&(jeu.joueurSolo.testArgentJoueur())) //jeu.joueurSolo.getBudget()>=1
    {
        Event event;

        while(window->pollEvent(event))
        {
            if (event.type == Event::Closed)   
            window->close();

            if(event.type == Event::MouseButtonPressed)
            {
                if(event.key.code == Mouse::Left)
                {
                    float x = Mouse::getPosition(*window).x;
                    float y = Mouse::getPosition(*window).y;

                      if(finJeu==1)
                    {
                        jeu.resultat();
                        jeu.finJeu();
                        actionMiser=0;
                        finJeu=0;
                    }

                    switch(actionMiser)
                    {
                        case 0 :
                            if(s1.getGlobalBounds().contains(x,y))  //on appuie sur le jeton de valeur 1 
                            {
                                jeu.initialisationMise('a');    //correspond pour l'instant à une mise de 100
                                jeu.initialisationJeu();
                                actionMiser=1;
                            }
                            else if(s10.getGlobalBounds().contains(x,y))  //on appuie sur le jeton de valeur 10 
                            {
                                jeu.initialisationMise('z');    //correspond pour l'instant à une mise de 200
                                jeu.initialisationJeu();
                                actionMiser=1;
                            }
                            else if(s100.getGlobalBounds().contains(x,y))  //on appuie sur le jeton de valeur 100 
                            {
                                jeu.initialisationMise('e');    //correspond pour l'instant à une mise de 500
                                jeu.initialisationJeu();
                                actionMiser=1;
                            }
                            else if(s250.getGlobalBounds().contains(x,y))  //on appuie sur le jeton de valeur 1000 
                            {
                                jeu.initialisationMise('r');    //correspond pour l'instant à une mise de 1000
                                jeu.initialisationJeu();
                                actionMiser=1;
                            }
                            else if(s500.getGlobalBounds().contains(x,y))  //on appuie sur le jeton de valeur 1000 
                            {
                                jeu.initialisationMise('t');    //correspond pour l'instant à une mise de 1000
                                jeu.initialisationJeu();
                                actionMiser=1;
                            }
                            break;
                        
                        case 1 :
                            if(jeu.joueurSolo.mainJoueur.getJoueToujours())
                            {
                                if(sDoubler.getGlobalBounds().contains(x,y))  //on appuie sur le bouton doubler
                                {
                                    jeu.actionClavier('d');    //on double
                                    if(!jeu.joueurSolo.mainJoueur.getJoueToujours())
                                    {
                                        jeu.actionCroupier();
                                        finJeu=1;
                                    }
                                }
                                else if(sTirer.getGlobalBounds().contains(x,y))  //on appuie sur le bouton tirer
                                {
                                    jeu.actionClavier('t');    //on tire
                                    if(!jeu.joueurSolo.mainJoueur.getJoueToujours())
                                    {
                                        jeu.actionCroupier();
                                        finJeu=1;
                                    }
                                }
                                else if(sRester.getGlobalBounds().contains(x,y))  //on appuie sur le bouton rester
                                {
                                    jeu.actionClavier('r'); 
                                    if(!jeu.joueurSolo.mainJoueur.getJoueToujours())
                                    {
                                        jeu.actionCroupier();
                                        finJeu=1;
                                    } 
                                }
                                // else if(sChanger.getGlobalBounds().contains(x,y))  //on appuie sur le bouton rester
                                // {
                                //     jeu.actionClavier('r'); 
                                //     if(!jeu.joueurSolo.mainJoueur.getJoueToujours())
                                //     {
                                //         jeu.actionCroupier();
                                //         finJeu=1;
                                //     } 
                                // }
                            }
                            break;
                    }
                }
            }
            sfmlAff();
        }
    }
}

//une classe application qui contient un menu (classe) et un jeu (une classe)

