#ifndef JEUMULTI_H
#define JEUMULTI_H
#include <iostream>
#include "MainDeCarte.h"
#include "Carte.h"
#include "Deck.h"
#include "Joueur.h"
#include "Jeu.h"

class jeuMulti{
    public : 


    vector<Joueur>tabJoueur;

    /**
    * @brief Le nombre de partie effectué.
    */
    unsigned int nbPartie;




    /**
    * @brief Le deck du jeu.
    */
	Deck unDeck;


    /**
    * @brief La main de carte du croupier.
    */
	MainDeCarte mainCroupier;



    /**
    * @brief Constructeur sans paramètres de jeuMulti.
    * 
    * Exemple d'utilisation :
    * @code
    * jeuMulti unJeuMulti;
    * @endcode
    */
    jeuMulti ();



    /**
    * @brief Constructeur avec paramètre de jeuMulti.
    * @param[in] NiveauJoueur : le niveau des IA avec lesquelles le joueur jouera sa partie.
    *  
    * Exemple d'utilisation :
    * @code
    * jeuMulti unJeuMulti(1);
    * jeuMulti unJeuMulti(2);
    * jeuMulti unJeuMulti(3);
    * @endcode
    * @warning NiveauJoueur doit être compris entre 1 et 3 compris (1=amateur ; 2=intermédiaire ; 3=expert).
    */
    jeuMulti(unsigned int NiveauJoueur);



    /**
    * @brief Procédure permettant d'éliminer un joueur soit si il n'a plus d'argent, soit si il a le moins d'argent à la partie 3, 6 ou 9.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.eliminationJoueur();
    * @endcode
    */
    void eliminationJoueur();



    /**
    * @brief Procédure permettant de faire miser aléaoirement les IA, celles-ci peuvent miser les mises suivantes: 100, 200, 300, 500 ou 1000.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.initialisationMiseMulti();
    * @endcode
    */
    void initialisationMiseMulti();



    /**
    * @brief Procédure permettant de distribuer 2 cartes aux joueurs (le joueur physique derrière son écran et les IA) et 1 carte au croupier.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.initialisationJeuMulti();
    * @endcode
    */
    void initialisationJeuMulti();


    /**
    * @brief Procédure permettant d'effectuer les actions des IAs si NiveauJoueur est égal à 3.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.actionExpert();
    * @endcode
    */   
    void actionExpert();


    /**
    * @brief Procédure permettant d'effectuer les actions des IAs si NiveauJoueur est égal à 2.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.actionIntermediaire();
    * @endcode
    */   
    void actionIntermediaire();

    /**
    * @brief Procédure permettant d'effectuer les actions des IAs si NiveauJoueur est égal à 1. 
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.actionAmateur();
    * @endcode
    */   
    void actionAmateur();



    /**
    * @brief Procédure permettant d'effectuer les actions des IAs selon NiveauJoueur.
    * @return void
    * @param[in] NiveauJoueur : le niveau des IA avec lesquelles le joueur jouera sa partie.
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.actionIA(1);
    * unJeuMulti.actionIA(2);
    * unJeuMulti.actionIA(3);
    * @endcode
    * @warning NiveauJoueur doit être compris entre 1 et 3 compris (1=amateur ; 2=intermédiaire ; 3=expert).
    */      
    void actionIA(unsigned int NiveauJoueur);



    /**
    * @brief Procédure permettant de tester les fonctionnalités de la classe.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.testRegression();
    * @endcode
    */
    void testRegression() const; 


    private:

    /**
    * @brief Le niveau choisi au hasard dans la fonction actionIntermediaire().
    */
    unsigned int nvHasard;

    /**
    * @brief Le pourcentage (entre 40 et 60) pour determiner le ratio/le niveau du joueur.
    */
	unsigned int randPourcentage;
};
#endif
