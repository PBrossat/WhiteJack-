#ifndef CARTE_H
#define CARTE_H


#include <iostream>

using namespace std;


class Carte 
{
    public:



    /**
    * @brief Constructeur avec paramètres de la classe Carte
    * @param[in] Rang le rang de la carte (as, dame, roi,...) 
    * @param[in] Valeur  la valeur de la carte 
    * @param[in] Signe le signe de la carte (pique, coeur, trèfle ou carreau) 
    * 
    * Exemple d'utilisation :
    * @code
    * Carte carte1(5,5,2);
    * Carte carte1(11,10,1);
    * @endcode
    * @warning Rang doit être compris entre 1 et 13 (ace=1, deux=2, ..., valet=11, dame=12, roi=13)
    * @warning Valeur doit être comprise entre 1 et 11
    * @warning Signe doit être compris entre 1 et 4 (pique=1, coeur =2, trèfle=3, carreau=4)
    */
    Carte (unsigned int Rang, unsigned int Valeur, unsigned int Signe);



    /**
    * @brief Constructeur sans paramètres de la classe Carte
    * 
    * Exemple d'utilisation :
    * @code
    * Carte carte1;
    * @endcode
    * @warning Initialise la valeur, le signe et le rang de la carte à 0
    */
    Carte();



    /**
    * @brief Accesseur renvoyant le rang d'une carte
    * @return unsigned int
    * 
    * Exemple d'utilisation :
    * @code
    * uneCarte.getRang();
    * @endcode
    */
    unsigned int getRang() const;



    /**
    * @brief Accesseur renvoyant la valeur d'une carte
    * @return unsigned int
    * 
    * Exemple d'utilisation :
    * @code
    * uneCarte.getValeur();
    * @endcode
    */
    unsigned int getValeur() const;



    /**
    * @brief Accesseur renvoyant le signe d'une carte
    * @return unsigned int
    * 
    * Exemple d'utilisation :
    * @code
    * uneCarte.getSigne();
    * @endcode
    */
    unsigned int getSigne() const;



    /**
    * @brief Mutateur modifiant la valeur d'une carte
    * @param[in] Valeur la nouvelle valeur de la carte 
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * uneCarte.setValeur(11);
    * @endcode
    * @warning : Valeur doit être comprise entre 1 et 11
    */
    void setValeur(unsigned int Valeur);



    /**
    * @brief Procédure testant les fonctionnalités de la classe
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * uneCarte.testRegression();
    * @endcode
    */
    void testRegression() const;



    /**
    * @brief Surcharge de l'opérateur = pour l'affectation
    * @param[in,out] operandeDroite carte que l'on désire affectée à la carte à gauche du = 
    * (attention : en mode donnée/résultat mais CONST)
    * @return Carte& 
    * 
    * Exemple d'utilisation :
    * @code
    * Carte carte1(5,5,2);
    * Carte carte2;
    * carte2 = carte1;
    * @endcode
    */
    Carte& operator = (const Carte& operandeDroite); 



    /**
    * @brief Surcharge de l'opérateur == pour tester l'égalité entre deux cartes (mêmes valeur et rang seulement)
    * @param[in,out] operandeDroite carte que l'on désire comparée à la carte à gauche du == 
    * (attention : en mode donnée/résultat mais CONST)
    * @return bool 
    * 
    * Exemple d'utilisation :
    * @code
    * Carte carte1(5,5,2);
    * Carte carte2 (5,5,1);
    * if (carte2 == carte1) {...};
    * @endcode
    */
    bool operator == (const Carte& operandeDroite); 



    /**
    * @brief Permet d'aficher une carte à l'écran (rang / valeur / signe)
    * 
    * Exemple d'utilisation :
    * @code
    * Carte carte1(5,5,2);
    * cout<<carte1;
    * @endcode
    */ 
    friend ostream& operator << (ostream& flux, const Carte& carteAffichee);   



    private :   



    //Représente la valeur de la carte 
    // Ce valeur est obligatoirement comprise entre 1 et 11    
    unsigned int valeur;

    

    //Représente la signe de la carte (pique=1 , coeur =2, trèfle=3, carreau=4) 
    //Ce valeur est obligatoirement comprise entre 1 et 4   
    unsigned int signe;


    
    //Représente le rang de la carte (ace=1; deux=2; ... valet=11; dame=12; roi=13) 
    //Ce valeur est obligatoirement comprise entre 1 et 13     
    unsigned int rang;


};

#endif