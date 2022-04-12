#include <cassert>
#include <time.h>
#include "jeuSfml.h"
#include <stdlib.h>


using namespace sf;

#include <iostream>
using namespace std;

sfmlJeu::sfmlJeu () : jeu() {
    window = new RenderWindow(VideoMode(945, 568), "BlackJack");
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
        sFond.setTexture(tFond);
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

    if (!t1000.loadFromFile("data/1000.png")) 
    {
        cout << "Error data/1000.png non found" << endl;
    }
    else 
    {
        s1000.setTexture(t1000);
    }

    if (!tDoubler.loadFromFile("data/double.png")) 
    {
        cout << "Error data/double.png non found" << endl;
    }
    else 
    {
        sDoubler.setTexture(tDoubler);
    }

    if (!tRester.loadFromFile("data/stand.png")) 
    {
        cout << "Error data/stand.png non found" << endl;
    }
    else 
    {
        sRester.setTexture(tRester);
    }

    if (!tTirer.loadFromFile("data/hit.png")) 
    {
        cout << "Error data/hit.png non found" << endl;
    }
    else 
    {
        sTirer.setTexture(tTirer);
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

void sfmlJeu::sfmlAff() 
{
    window->clear(Color(230, 240, 255, 255));

    window->draw(sFond);

    if(jeu.joueurSolo.getBudget()>=1000)
    {
        s1.setPosition(100,500);
        window->draw(s1);

        s10.setPosition(150,500);
        window->draw(s10);

        s100.setPosition(200,500);
        window->draw(s100);

        s1000.setPosition(250,500);
        window->draw(s1000);
    }

    if(jeu.joueurSolo.getBudget()>=100)
    {
        s1.setPosition(100,500);
        window->draw(s1);

        s10.setPosition(150,500);
        window->draw(s10);

        s100.setPosition(200,500);
        window->draw(s100);
    }

    if(jeu.joueurSolo.getBudget()>=10)
    {
        s1.setPosition(100,500);
        window->draw(s1);

        s10.setPosition(150,500);
        window->draw(s10);
    }

    if(jeu.joueurSolo.getBudget()>=1)
    {
        s1.setPosition(100,500);
        window->draw(s1);
    }

    // unsigned int position = 150;
    // s1deTrefles.setPosition(position, 250);
	// position += 260;
	// window->draw(s1deTrefles);
    

    // // Ecrire un titre par dessus
    // m_window->draw(m_text);

    window->display();
}


void sfmlJeu::afficherMainDeCarte(MainDeCarte mainJoueur)
{
    unsigned int position = 150;

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
			if (mainJoueur.getIemeCarte(i).getRang() == 2)
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
			if (mainJoueur.getIemeCarte(i).getRang() == 3)
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
			if (mainJoueur.getIemeCarte(i).getRang() == 4)
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
			if (mainJoueur.getIemeCarte(i).getRang() == 5)
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
			if (mainJoueur.getIemeCarte(i).getRang() == 6)
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
			if (mainJoueur.getIemeCarte(i).getRang() == 7)
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
			if (mainJoueur.getIemeCarte(i).getRang() == 8)
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
			if (mainJoueur.getIemeCarte(i).getRang() == 9)
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
			if (mainJoueur.getIemeCarte(i).getRang() == 10)
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
			if (mainJoueur.getIemeCarte(i).getRang() == 11)
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
			if (mainJoueur.getIemeCarte(i).getRang() == 12)
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
			if (mainJoueur.getIemeCarte(i).getRang() == 13)
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
			carte.setPosition(position, 100);
			position += 150;
			window->draw(carte);
    }
}


void sfmlJeu::sfmlBoucle () {

    bool actionMiser = 0;
    bool actionJouer = 0;
    bool actionCarte = 0;

    Rect s1Rect = s1.getGlobalBounds();
    Rect s10Rect = s10.getGlobalBounds();
    Rect s100Rect = s100.getGlobalBounds();
    Rect s1000Rect = s1000.getGlobalBounds();

    Rect sRester = sRester.getGlobalBounds();
    Rect sDoublerRect = sDoubler.getGlobalBounds();
    Rect sTirerRect = sTirer.getGlobalBounds();

    while (window->isOpen())
    {
        Event event;

        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
            window->close();

            if (event.type == Event::MouseButtonPressed)
			{

				if (event.key.code == Mouse::Left)
				{
					float x = Mouse::getPosition(window).x;
					float y = Mouse::getPosition(window).y;

                    if(s1Rect.contains(x,y))
                    {

                    }	


            // if (event.type == Event::KeyPressed) 
            // {
    //             switch (event.key.code) 
    //             {
    //                  case Keyboard::Up : 
                            // mangePastille = jeu.actionClavier('b');    // car Y inverse
	// 				        break;
	// 			        case Keyboard::Down : 
    //                      mangePastille = jeu.actionClavier('h');     // car Y inverse
	// 				        break;
	// 			        case Keyboard::Left : 
    //                      mangePastille = jeu.actionClavier('g');
	// 				        break;
	// 			        case Keyboard::Right : 
    //                      mangePastille = jeu.actionClavier('d');
	// 				        break;
    //                  default : break;
    //             }

    //             if (mangePastille) m_sound.play();
                }
            }

        //sfmlAff();
    }

    }
}







