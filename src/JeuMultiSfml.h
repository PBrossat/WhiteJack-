#ifndef _SFMLMULTI_H
#define _SFMLMULTI_H

#include "JeuMulti.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class JeuMultiSfml{

public :

    /**
    * @brief Constructeur de JeuMultiSfml
    * 
    * Exemple d'utilisation :
    * @code
    * JeuMultiSfml unJeuMulti;
    * @endcode
    */
    JeuMultiSfml ();

    /**
    * @brief Destructeur de JeuMultiSfml
    */
    ~JeuMultiSfml ();

    /**
    * @brief Procédure permettant d'initialiser toute les images, sons et polices utilisées
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMultiSfml.sfmlInit();
    * @endcode
    */  
    void sfmlInit();

    /**
    * @brief Procédure permettant de faire tourner la boucle du jeu 
    * @return unsigned int
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMultiSfml.sfmlBoucle();
    * @endcode
    */ 
    unsigned int sfmlBoucle();

    /**
    * @brief Procédure permettant d'afficher toute les images à l'écran
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMultiSfml.sfmlAff();
    * @endcode
    */ 
    void sfmlAff();


private :
    
    JeuMulti jeu;

    unsigned int dimx;
    unsigned int dimy;
    bool actionMiser;
    bool finManche;
    unsigned int choixNiv;
    bool top1;
    bool elimine;
    unsigned int res;

	sf::RenderWindow * window;

    sf::Texture t1deCoeur;
    sf::Texture t1deCarreau;
    sf::Texture t1dePiques;
    sf::Texture t1deTrefles;

    sf::Texture t2deCoeur;
    sf::Texture t2deCarreau;
    sf::Texture t2dePiques;
    sf::Texture t2deTrefles;

    sf::Texture t3deCoeur;
    sf::Texture t3deCarreau;
    sf::Texture t3dePiques;
    sf::Texture t3deTrefles;

    sf::Texture t4deCoeur;
    sf::Texture t4deCarreau;
    sf::Texture t4dePiques;
    sf::Texture t4deTrefles;

    sf::Texture t5deCoeur;
    sf::Texture t5deCarreau;
    sf::Texture t5dePiques;
    sf::Texture t5deTrefles;

    sf::Texture t6deCoeur;
    sf::Texture t6deCarreau;
    sf::Texture t6dePiques;
    sf::Texture t6deTrefles;

    sf::Texture t7deCoeur;
    sf::Texture t7deCarreau;
    sf::Texture t7dePiques;
    sf::Texture t7deTrefles;

    sf::Texture t8deCoeur;
    sf::Texture t8deCarreau;
    sf::Texture t8dePiques;
    sf::Texture t8deTrefles;

    sf::Texture t9deCoeur;
    sf::Texture t9deCarreau;
    sf::Texture t9dePiques;
    sf::Texture t9deTrefles;

    sf::Texture t10deCoeur;
    sf::Texture t10deCarreau;
    sf::Texture t10dePiques;
    sf::Texture t10deTrefles;

    sf::Texture t11deCoeur;
    sf::Texture t11deCarreau;
    sf::Texture t11dePiques;
    sf::Texture t11deTrefles;
  
    sf::Texture t12deCoeur;
    sf::Texture t12deCarreau;
    sf::Texture t12dePiques;
    sf::Texture t12deTrefles;
  
    sf::Texture t13deCoeur;
    sf::Texture t13deCarreau;
    sf::Texture t13dePiques;
    sf::Texture t13deTrefles;

    sf::Texture tCardBack;
    sf::Texture tDeck;
    sf::Texture tFond;
    sf::Texture t1;
    sf::Texture t10;
    sf::Texture t100;
    sf::Texture t250;
    sf::Texture t500;
    sf::Texture tTirer;
    sf::Texture tDoubler;
    sf::Texture tRester;
    sf::Texture tChanger;
    sf::Texture tBlackjack;
    sf::Texture tGagne;
    sf::Texture tPerdu;
    sf::Texture tEgalite;
    sf::Texture tExit;
    sf::Texture tAmateur;
    sf::Texture tIntermediaire;
    sf::Texture tExpert;
    sf::Texture tBigWin;
    sf::Texture tElimine;
  
    sf::Sprite s1deCoeur;
    sf::Sprite s1deCarreau;
    sf::Sprite s1dePiques;
    sf::Sprite s1deTrefles;

    sf::Sprite s2deCoeur;
    sf::Sprite s2deCarreau;
    sf::Sprite s2dePiques;
    sf::Sprite s2deTrefles;

    sf::Sprite s3deCoeur;
    sf::Sprite s3deCarreau;
    sf::Sprite s3dePiques;
    sf::Sprite s3deTrefles;
    sf::Sprite s4deCoeur;
    sf::Sprite s4deCarreau;
    sf::Sprite s4dePiques;
    sf::Sprite s4deTrefles;

    sf::Sprite s5deCoeur;
    sf::Sprite s5deCarreau;
    sf::Sprite s5dePiques;
    sf::Sprite s5deTrefles;

    sf::Sprite s6deCoeur;
    sf::Sprite s6deCarreau;
    sf::Sprite s6dePiques;
    sf::Sprite s6deTrefles;

    sf::Sprite s7deCoeur;
    sf::Sprite s7deCarreau;
    sf::Sprite s7dePiques;
    sf::Sprite s7deTrefles;

    sf::Sprite s8deCoeur;
    sf::Sprite s8deCarreau;
    sf::Sprite s8dePiques;
    sf::Sprite s8deTrefles;

    sf::Sprite s9deCoeur;
    sf::Sprite s9deCarreau;
    sf::Sprite s9dePiques;
    sf::Sprite s9deTrefles;


    sf::Sprite s10deCoeur;
    sf::Sprite s10deCarreau;
    sf::Sprite s10dePiques;
    sf::Sprite s10deTrefles;

    sf::Sprite s11deCoeur;
    sf::Sprite s11deCarreau;
    sf::Sprite s11dePiques;
    sf::Sprite s11deTrefles;
  
    sf::Sprite s12deCoeur;
    sf::Sprite s12deCarreau;
    sf::Sprite s12dePiques;
    sf::Sprite s12deTrefles;
  
    sf::Sprite s13deCoeur;
    sf::Sprite s13deCarreau;
    sf::Sprite s13dePiques;
    sf::Sprite s13deTrefles;

    sf::Sprite s1;
    sf::Sprite s10;
    sf::Sprite s100;
    sf::Sprite s250;
    sf::Sprite s500;
    sf::Sprite sTirer;
    sf::Sprite sDoubler;
    sf::Sprite sRester;
    sf::Sprite sChanger;
    sf::Sprite sBlackjack;
    sf::Sprite sGagne;
    sf::Sprite sPerdu;
    sf::Sprite sEgalite;
    sf::Sprite sExit;
    sf::Sprite sAmateur;
    sf::Sprite sIntermediaire;
    sf::Sprite sExpert;
    sf::Sprite sBigWin;
    sf::Sprite sElimine;

    sf::RectangleShape rsFond;

    sf::Font m1_font;
    sf::Font m2_font;
    sf::Text txtScoreJoueur;
    sf::Text txtScore1;
    sf::Text txtScore2;
    sf::Text txtScore3;
    sf::Text txtNom;
    sf::Text txtNom1;
    sf::Text txtNom2;
    sf::Text txtNom3;
    sf::Text txtManche;
    sf::Text txtMise;
    sf::Text txtBudget;
    sf::Text txtBudget1;
    sf::Text txtBudget2;
    sf::Text txtBudget3;
    sf::Text txtScoreCroupier;

    sf::SoundBuffer m1_soundbuffer;
    sf::SoundBuffer m2_soundbuffer;
    sf::SoundBuffer m3_soundbuffer;
    sf::SoundBuffer m4_soundbuffer;
    sf::SoundBuffer m5_soundbuffer;
    sf::Sound sonMise;
    sf::Sound sonCarte;
    sf::Sound sonJackpot;
    sf::Sound sonGagne;
    sf::Sound sonPerdu;

    //Procédure permettant d'afficher à l'écran les main de cartes
    void afficherMainDeCarte(const MainDeCartes& mainJoueur, unsigned int x, unsigned int y)const;

    //Procédure permettant d'initialiser la partie une fois que le joueur a misé  
    void initPartie();

    //Procédure permettant de gérer la fin d'une manche dès que le joueur a terminé de jouer  
    void finPartie();

    //Procédure permettant de gérer l'affichage au cours d'une manche suivant le nombre de joueurs
    void affichageManche(unsigned int nbJoueurs);
    
};

#endif