#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Carte.h"
#include <vector>

using namespace std;

class Deck
{
	public :
 
	/**
    * @brief Procédure initialisant le deck (création)
    * @return void
    * Exemple d'utilisation :
    * @code
    * Deck unDeck;
    * unDeck.initDeck();
    * @endcode
    */
	void initDeck();

	/**
    * @brief Procédure mélangeant le deck 
    * Exemple d'utilisation :
    * @code
    * Deck unDeck;
    * unDeck.initDeck();
    * unDeck.melangerDeck();
    * @endcode
    * @warning Attention avant de mélanger le deck il faut l'initialiser !
    */
	void melangerDeck();

	/**
    * @brief Fonction distribuant une carte
    * @return Carte
    * Exemple d'utilisation :
    * @code
    * unDeck.distribuerCarte();
    * @endcode
    * @warning Attention avant de distribuer une carte, intialiser et mélanger le deck une fois au début
    */
	Carte distribuerCarte();


	/**
    * @brief Procédure testant les fonctionnalités de la classe
    * @return void
    * Exemple d'utilisation :
    * @code
    * Deck unDeck
    * unDeck.testRegression()
    * @endcode
    */
	void testRegression() const;


	void afficherDeck() const;	//À METTRE DANS JEU TXT


	private :

	/**
    * @brief Tableau de cartes représentant le deck   
    */
	vector<Carte> deck; 

};

#endif

