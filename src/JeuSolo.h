#ifndef JEU_H
#define JEU_H

#include <iostream>
#include "MainDeCartes.h"
#include "Carte.h"
#include "Deck.h"
#include "Joueur.h"

using namespace std;

class JeuSolo
{
	public :

    /**
     * @brief Le joueur 
    */
	Joueur joueurSolo; 


    /**
     * @brief La main de carte du croupier
    */
	MainDeCartes mainCroupier;


    /**
     * @brief La mise du joueur
    */
	unsigned int mise;


    /**
     * @brief L'éventuel gain du joueur 
    */
	unsigned int gain;


	/**
     * @brief Constructeur sans paramètre de Jeu 
     * 
     * Exemple d'utilisation :
     * @code
     * Jeu unJeu;
     * @endcode
    */
	JeuSolo();


	/**
     * @brief Procédure permettant de saisir la mise de départ
     * @param[in] touche : la touche saisie par l'utilisateur
     * @return void
     * 
     * Exemple d'utilisation :
      * unJeu.initialisationMise('a');
     * @endcode
     * @warning La mise saisie doit être inférieur au budget du joueur (2000)
     * @warning Le parametre touche doit etre obligatoirement 'a' pour 1, 'z' pour 10, 'e' pour 100, 'r' pour 250 ou 't' pour 500
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
     * unJeu.actionClavier('t');
     * @endcode
     * @warning Le parametre touche doit etre obligatoirement 't', 'd', 'r', 'c' 
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
     * @brief Fonction permettant de déterminer les gains du joueur et renvoyant un entier déterminant le résultat
     * (gagné,perdu,blackjack...)
     * @return unsigned int : 0 pour perdu, 1 pour égalité, 2 pour gagné, 3 pour blackjack
     * 
     * Exemple d'utilisation :
     * @code
     * unJeu.resultat();
     * @endcode
     * @warning À faire qu'à la fin de la partie
    */
	unsigned int resultat(); 



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

    private :

    //La deuxième carte du croupier (cachée lorsque le joueur joue)
	Carte deuxiemeCarteCroupier;

    //Le deck du jeu
	Deck unDeck;

};

#endif