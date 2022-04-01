#ifndef JEU_H
#define JEU_H

#include <iostream>
#include "MainDeCarte.h"
#include "Carte.h"
#include "Deck.h"
#include "Joueur.h"

using namespace std;

class Jeu
{
	public :

	Deck unDeck;
	Joueur joueurSolo; 
	MainDeCarte mainCroupier;
	Carte deuxiemeCarteCroupier;
	unsigned int mise;
	unsigned int gain;

	/**
    * @brief Constructeur sans paramètres de Jeu 
    * 
    * Exemple d'utilisation :
    * @code
    * Jeu unJeu;
    * @endcode
    */
	Jeu();

	/**
    * @brief Procédure permettant de saisir la mise de départ
    * @param[in] touche : la touche saisie par l'utilisateur
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeu.initialisationMise();
    * @endcode
    * @warning La mise saisie doit être inférieur au budget du joueur (2000)
    */
    void initialisationMise(const char touche);

    /**
    * @brief Procédure permettant d'initialiser le jeu (distribution des premières cartes)
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeu.initialisationJeu();
    * @endcode
    */
	void initialisationJeu(); 

	/**
    * @brief Procédure permettant de réinitialiser les mains de cartes du joueur et du croupier 
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeu.finJeu();
    * @endcode
    * @warning À faire à chaque fin de partie
    */ 
	void finJeu();

	/**
    * @brief Procédure permettant d'adapter les actions suivant les touches pressées par l'utilisateur
    * @param[in] touche : la touche saisie par l'utilisateur
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeu.actionClavier();
    * @endcode
    */
	void actionClavier(const char touche);

	/**
    * @brief Procédure permettant de gérer automatiquement les actions du croupier 
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeu.actionCroupier();
    * @endcode
    */
	void actionCroupier();

	/**
    * @brief Procédure permettant de déterminer les gains du joueur
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeu.resultat();
    * @endcode
    * @warning À faire qu'à la fin de la partie
    */
	void resultat(); 

	/**
    * @brief Procédure permettant de tester les fonctionnalités de la classe
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeu.testRegression();
    * @endcode
    */
	void testRegression() const; 

};

#endif