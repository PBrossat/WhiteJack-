#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <string.h>
#include "MainDeCarte.h"

using namespace std;

class Joueur
{
	public :

	/**
	 * @brief nom : une chaîne de caractères décrivant le nom du joueur 
	*/
	string nom;

	/**
	 * @brief hand : main de carte du joueur
	*/
	MainDeCarte mainJoueur;

	 /**
     * @brief  Constructeur de joueur
     * @param[in] nomJ : une chaîne de caractères décrivant le nom du joueur 
     * @param[in] nivJoueur: un entier entre 0 et 3 définissant le niveau du joueur 
     * @param[in] budgetJ: un réel > 0 représentant le budget du joueur 
     * 
     * Exemple d'utilisation :
     * @code
     * Joueur unJoueur("Pierrick", 0, 1000);
     * @endcode     
     * @warning 0 : le joueur est humain
     * @warning 1 : le joueur est amateur
     * @warning 2 : le joueur est intermédiaire
     * @warning 3 : le joueur est expert
    */ 
    Joueur(string nomJ, unsigned int nivJoueur, float budgetJ);

   
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
     * @brief Accesseur de budget
     * @return float 
     * 
     * Exemple d'utilisation :
     * @code
     * unJoueur.getBudget();
     * @endcode     
    */ 
    float getBudget() const;


     /**
     * @brief Mutateur de budget
     * @param[in] gain : l'argent que le joueur a gagné (ou perdu)
     * @return void 
     * 
     * Exemple d'utilisation :
     * @code
     * unJoueur.setBudget(100);
     * unJoueur.setBudget(-100);
     * @endcode     
    */ 
    void setBudget(float gain);

    /**
     * @brief Accesseur du niveau de joueur 
     * @return usigned int 
     * 
     * Exemple d'utilisation :
     * @code
     * unJoueur.getNiveau();
     * @endcode     
    */ 
    unsigned int getNiveau() const;


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


    /**
     * @brief Fonction permettant au joueur de miser 
     * @param[in] mise : la mise du joueur 
     * @return unsigned int
     * 
     * Exemple d'utilisation :
     * @code
     * unJoueur.miser(100);
     * @endcode     
     * @warning Attention la mise du joueur ne peut être supérieur à son budget 
    */ 
    unsigned int miser(unsigned int mise);

    private :

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

    //  *
    //  * @brief nbMainDeCartes : entier positif représentant le nombre de mains de cartes que le joueur est en train de jouer 
    
    // unsigned int nbMainDeCartes;



};

//fonction splitter pour joeur qui appel splitter de main de cartes

#endif

