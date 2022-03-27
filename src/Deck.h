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
    * @brief Procédure initialisant le deck 
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * Deck unDeck;
    * unDeck.initDeck();
    * @endcode
    * @warning Initialisez bien le deck une fois au tout début 
    */
	void initDeck();


	/**
    * @brief Procédure mélangeant le deck
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * Deck unDeck;
    * unDeck.melangerDeck();
    * @endcode
    * @warning Initialisez le deck avant de le mélanger
    */
	void melangerDeck();


	/**
    * @brief Fonction distribuant une carte
    * @return Carte 
    * 
    * Exemple d'utilisation :
    * @code
    * unDeck.distribuerCarte();
    * @endcode
    * @warning Initialisez le deck avant de distribuer une carte (et de préférence mélangez le aussi)
    */
	Carte distribuerCarte();


	/**
    * @brief Procédure testant les fonctionnalités de la classe
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * Deck unDeck;
    * unDeck.testRegression();
    * @endcode
    */
	void testRegression() const;


// À METTRE DANS JEU TXT

	/**
    * @brief Procédure affichant le deck
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unDeck.afficherDeck();
    * @endcode
    * @warning Initialisez au moins le deck avant de l'afficher
    */
	void afficherDeck() const;

	private :	//DOXYGEN INUTILE SI PRIVATE

	/**
    * @brief  Tableau dynamique représentant le deck de cartes
    */ 
	vector<Carte> deck;

};

#endif

