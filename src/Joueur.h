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
	 * @brief nom une chaîne de caractères décrivant le nom du joueur 
	*/
	string nom;

	/**
	 * @brief mainJoueur main de cartes du joueur
	*/
	MainDeCarte mainJoueur;

	 /**
     * @brief  Constructeur de joueur
     * @param[in] nomJ une chaîne de caractères décrivant le nom du joueur 
     * @param[in] nivJoueur un entier entre 0 et 3 définissant le niveau du joueur 
     * @param[in] budgetJ un réel > 0 représentant le budget du joueur 
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
    bool testArgentJoueur() const;


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
     * @param[in] gain l'argent que le joueur a gagné (ou perdu)
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
     * @return unsigned int 
     * 
     * Exemple d'utilisation :
     * @code
     * unJoueur.getNiveau();
     * @endcode     
    */ 
    unsigned int getNiveau() const;


    /**
     * @brief Procédure testant les fonctionnalités de la classe
     * @return void
     * 
     * Exemple d'utilisation :
     * @code
     * unJoueur.testRegression();
     * @endcode     
    */ 
    void testRegression() const;


    /**
     * @brief Fonction permettant au joueur de miser 
     * @param[in] mise la mise du joueur 
     * @return void
     * 
     * Exemple d'utilisation :
     * @code
     * unJoueur.miser(100);
     * @endcode     
     * @warning Attention la mise du joueur ne peut être supérieur à son budget 
    */ 
    void miser(unsigned int mise);

    private :

    //un réel décrivant le budget du joueur 
    float budget;

    //un entier entre 0 et 3 définissant le niveau du joueur 
    //0 : le joueur est humain
    //1 : le joueur est amateur
    //2 : le joueur est intermédiaire
    //3 : le joueur est expert
    unsigned int niveauJoueur;


};


#endif

