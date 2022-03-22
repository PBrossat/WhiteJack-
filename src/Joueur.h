#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <string.h>
#include "MaineDeCartes.h"

using namespace std;

class Joueur
{
	public :

	/**
	 * @brief nom : une chaîne de caractères décrivant le nom du joueur 
	*/
	string nom;

	/**
	 * @brief budget : un réel décrivant le budget du joueur 
	*/
	float budget;
	
	/**
	 * @brief niveauJoueur: un entier entre 0 et 3 définissant le niveau du joueur 
	 * @warning 0 : le joueur est humain
     * @warning 1 : le joueur est amateur
     * @warning 2 : le joueur est intermédiaire
     * @warning 3 : le joueur est expert
	*/
	unsigned int niveauJoueur;

	/**
	 * @brief hand : la main de cartes du joueur
	*/
	MainDeCartes hand;

	 /**
     * @brief  Constructeur de joueur
     * @param[in] nomJ : une chaîne de caractères décrivant le nom du joueur 
     * @param[in] nivJoueur: un entier entre 0 et 3 définissant le niveau du joueur 
     * 
     * Exemple d'utilisation :
     * @code
     * Joueur unJoueur("Pierrick", 0);
     * @endcode     
     * @warning 0 : le joueur est humain
     * @warning 1 : le joueur est amateur
     * @warning 2 : le joueur est intermédiaire
     * @warning 3 : le joueur est expert
    */ 
    Joueur(string nomJ, unsigned int nivJoueur);

    /**
     * @brief  Accesseur : récupère l'identifiant du joueur 
     * @return unsigned int 
     * 
     * Exemple d'utilisation :
     * @code
     * unJoueur.getId();
     * @endcode     
    */ 
    unsigned int getId();

    /**
     * @brief Tester si un joueur a toujours de l'argent ou non
     * @return bool
     * 
     * Exemple d'utilisation :
     * @code
     * unJoueur.testArgentJoueur();
     * @endcode     
    */ 
    bool testArgentJoueur();

     /**
     * @brief Tester la classe et ses fonctionnalités
     * @return void
     * 
     * Exemple d'utilisation :
     * @code
     * unJoueur.testRegression();
     * @endcode     
    */ 
    void testRegression();

	private :

	/**
	 * @brief id : un entier positif servant d'identifiant pour le joueur
	*/
	unsigned int id;

};

#endif

