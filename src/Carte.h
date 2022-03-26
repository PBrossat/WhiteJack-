#ifndef CARTE_H
#define CARTE_H


#include <iostream>

using namespace std;


class Carte 
{
    public:

    enum RANK {ACE, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX,
               VALET, REINE, ROI};  

    /**
    * @brief  Représente la valeur de la carte 
    * @warning Ce valeur est obligatoirement comprise entre 1 et 11
    */    
    unsigned int valeur;

    /**
    * @brief  Représente la signe de la carte (pique=0 , coeur =1, trèfle=2, carreau=3) 
    * @warning Ce valeur est obligatoirement comprise entre 0 et 3 
    */    
    unsigned int signe;

    /**
    * @brief  Représente la carte (au sein de sa famille de signe)
    */    
    RANK rang;

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
    Carte (RANK r, unsigned int valeur, unsigned int signe);


    /**
    * @brief Constructeur sans  paramètre de la classe Carte
    * Exemple d'utilisation :
    * @code
    * Carte carte1;
    * @endcode
    * #warning : initialise la valeur et le signe de la carte à -1
    */
    Carte();


    /**
    * @brief Procédure testant les fonctionnalités de la classe
    * @return void
    * Exemple d'utilisation :
    * @code
    * Carte carte1;
    * carte1.testRegression()
    * @endcode
    */
    void testRegression() const;


    /**
    * @brief Surcharge de l'opérateur =
    * @param[in] operandeDroite la carte que l'on souhaite affectée à la carte utilisée
    * @return Carte&
    * Exemple d'utilisation :
    * @code
    * Carte carte1;
    * Carte carte2(5,2);
    * carte1 = carte2;
    * @endcode
    */
    Carte& operator = (const Carte& operandeDroite); 



    friend ostream& operator << (ostream& flux, const Carte& carteAffichee);    //À METTRE DANS MODULE JEU TXT

};

#endif