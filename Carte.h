#ifndef CARTES_H
#define CARTES_H


#include <iostream>

using namespace std;


class Carte 
{
    public:


    /**
    * @brief  Represente la valeur de la carte 
    * @warning Ce valeur est obligatoirement comprise entre 1 et 11
    */    
    unsigned int valeur;

    /**
    * @brief  Represente la signe de la carte (pique=0 , coeur =1, trèfle=2, carreau=3) 
    * @warning Ce valeur est obligatoirement comprise entre 0 et 3 
    */    
    unsigned int signe;


    /**
    * @brief Constructeur avec paramètres de la classe Carte
    * @param[in] valeur  la valeur de la carte (comprise entre 1 et 11)
    * @param[in] signe le signe de la carte (pique, coeur, trèfle ou carreau) 
    * Exemple d'utilisation :
    * @code
    * Carte carte1(5,2);
    * Carte carte1(8,1);
    * @endcode
    */
    Carte (unsigned int valeur, unsigned int signe);

    

};

#endif