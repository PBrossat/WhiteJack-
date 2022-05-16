#ifndef MAINDECARTE_H
#define MAINDECARTE_H
#include "Carte.h"
#include <vector>
#include <iostream>

using namespace std;

class MainDeCartes
{
    public :

    /**
     * @brief Constructeur de la classe sans paramètres
     * 
     * Exemple d'utilisation :
     * @code
     * MainDeCarte uneMain;
     * @endcode
     * @warning initialise nbCartes, sommeValeur, crame à 0 et joueToujours à 1
    */
    MainDeCartes();



    /**
     * @brief Constructeur avec paramètres de la classe MainDeCarte
     * @param[in,out] carte1 la première carte de la main (mode donnée-résultat mais CONST)
     * @param[in,out] carte2 la deuxième carte de la main (mode donnée-résultat mais CONST)
     * 
     * Exemple d'utilisation :
     * @code
     * MainDeCarte uneMain(carte1, carte2);
     * @endcode
    */
    MainDeCartes (const Carte& carte1, const Carte& carte2);



    /**
    * @brief Destructeur de MainDeCarte
    */
    ~MainDeCartes();



    /**
     * @brief Permet de tirer une nouvelle carte
     * @param[in,out] carteAjoutee La carte que le croupier tire pour le joueur (mode donnée-résultat mais CONST)
     * @return void  
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.tirerCarte(carteAjoutee);
     * @endcode
     */
    void tirerCarte (const Carte& carteAjoutee);



    /**
     * @brief Permet de demander une unique nouvelle carte au croupier 
     * @param[in] carteAjoutee La carte à ajouter (mode donnée-résultat mais CONST)
     * @return void  
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.doubler(carteAjoutee);
     * @endcode
     * @warning Le joueur peut doubler que lors de sa première action (lorsqu'il à deux cartes uniquement) et si il a assez d'argent
    */
    void doubler (const Carte& carteAjoutee);



    /**
     * @brief Permet d'echanger sa dernière carte avec une autre 
     * @param[in] carteAjoutee La carte à ajouter (mode donnée-résultat mais CONST)
     * @return void  
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.changeCarte(carteAjoutee);
     * @endcode
     * @warning Le joueur peut changer que lorsqu'il a deux cartes de même rang et si il a assez d'argent 
    */
    void changeCarte(const Carte& carteAjoutee);



    /**
     * @brief Permet au joueur de passer son tour lorsque la somme des valeurs de ses cartes lui convient  
     * @return void  
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.rester();
     * @endcode 
    */
    void rester ();



    /**
     * @brief Permet de gérer la valeur de l'as (1 ou 11)
     * @return void  
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.verifAs();
     * @endcode
    */
    void verifAs();



    /**
     * @brief Permet de verifier si le score du joueur est inferieur ou égal à 21  
     * @return void  
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.verifScore();
     * @endcode
    */
    void verifScore ();



    /**
     * @brief Permet de verifier si le joueur a un blackJack  
     * @return bool
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.verifBlackJack();
     * @endcode
    */
    bool verifBlackJack ();



    /**
     * @brief Permet d'obtenir la carte d'indice I dans la main.  
     * @param[in] indice L'indice de la carte que l'on veut  
     * @return Carte La carte d'indice "indice" 
 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.getIemeCarte(1);
     * @endcode
     * @warning Le tableau de carte ne doit pas être vide
     * @warning L'indice en paramètre doit être inférieur à la taille du tableau de Carte
     * @warning L'indice en paramètre doit est supérieur ou egal à 0 
    */
    Carte getIemeCarte(unsigned int indice) const;

    

    /**
     * @brief Accesseur : récupère la somme des valeurs des cartes du joueur 
     * @return La somme des valeurs des cartes du joueur 
     * 
     * Exemple d'utilisation :
     * @code
     * unsigned int sommeValeur = uneMainDeCarte.getSommeValeur();
     * @endcode       
     */   
    unsigned int getSommeValeur () const;



    /**
     * @brief   Mutateur : permet de changer la somme des valeurs des cartes
     * @return  void  
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.setSommeValeur(6);
     * uneMainDeCarte.setSommeValeur(10);
     * @endcode  
    */ 
    void setSommeValeur (unsigned int SommeValeur);



    /**
     * @brief   Accesseur : récupère le nombre de cartes du joueur 
     * @return  le nombre de carte de la main du joeur  
     * 
     * Exemple d'utilisation :
     * @code
     * unsigned int NbCarte = uneMainDeCarte.getNbCarte();
     * @endcode       
    */   
    unsigned int getNbCartes () const;



    /**
     * @brief   Accesseur : récupère le booléen permettant de savoir si le joueur joue toujours
     * @return  bool (1 si le joueur joue toujours, 0 sinon)
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.getJoueToujours();
     * @endcode       
    */   
    bool getJoueToujours () const;



    /**
     * @brief   Accesseur : récupère le booléen permettant de savoir si le joueur a cramé
     * @return  bool (1 si le joueur a cramé, 0 sinon)
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.getCrame();
     * @endcode       
    */   
    bool getCrame () const;



    /**
     * @brief Vide la main de carte du joueur (la réinitialise)
     * @return  void
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.vider();
     * @endcode       
    */   
    void vider();



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
    
    //sommeValeur est la somme des valeurs des cartes de la main de cartes
    unsigned int sommeValeur;



    //tableau de Carte
    vector<Carte>mainDeJoueur;



    //nbCartes désigne le nombre de cartes qu'a le joueur dans sa main 
    unsigned int nbCartes;


    
    //Booléen permettant de savoir si le joueur joue encore.
    bool joueToujours;



    //Booléen permettant de savoir si la valeur de la somme de ses cartes est supérieur à 21 (0= pas cramé, 1= il a cramé).
    bool crame;

};

#endif