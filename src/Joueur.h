#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <string.h>

using namespcae std;

class Joueur
{
	public :

	string nom;
	float budget;
	unsigned int niveauJoueur;
	MainDeCartes hand;

	 /**
     * @brief  Constructeur de joueur
     * @param[in] nom : une chaîne de caractères décrivant le nom du joueur 
     * @param[in] niveauJoueur: un entier entre 0 et 3 définissant le niveau du joueur 
     * 
     * Exemple d'utilisation :
     * @code
     *Joueur unJoueur("Pierrick", 0);
     * @endcode     
     * @warning 0 : le joueur est humain
     * @warning 1 : le joueur est amateur
     * @warning 2 : le joueur est intermédiaire
     * @warning 3 : le joueur est expert
    */ 
    Joueur(string nom, unsigned int niveauJoueur);

    /**
     * @brief  Constructeur
     * @param[in] 
     * @return void 
     * 
     * Exemple d'utilisation :
     * @code
     *
     * @endcode     
     * @warning 
    */ 
    unsigned int getId();

    /**
     * @brief  Constructeur
     * @param[in] 
     * @return void 
     * 
     * Exemple d'utilisation :
     * @code
     *
     * @endcode     
     * @warning 
    */ 
    bool testArgentJoueur();

	private :

	unsigned int id;

};

