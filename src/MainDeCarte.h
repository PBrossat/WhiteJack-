#ifndef MAINSDECARTES_H
#define MAINSDECARTES_H

#include <vector>
#include <iostream>

using namespace std;

class MainDeCartes 
{
    public :


    /**
    * @brief  tableau dynamique de liens sur Cartes
    */
    tableauDynamque*Cartes;

    /**
    * @brief   nbCartes désigne le nombre de cartes qu'a le joueur dans sa main 
    */
    unsigned int nbCartes;

    /**
    * @brief  Booléen permettant de savoir si le joueur est toujours en lice (SommeValeur est inférieur ou égal à 21)
    */
    bool état;


    /**
    * @brief Constructeur par défaut de la classe
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte Main_1;
    * @endcode
    */
    MainDeCarte ();


    /**
    * @brief Destructeur de la classe
    */
    ~MainDeCarte ();



   
    /**
    * @brief Permet de tirer une nouvelle carte
    * @param[in] niveauJoueur Le niveau du joueur qui est en train de tirer 
    * @return void  
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.tirerCarte(0);
    * MainDeCarte.tirerCarte(1);
    * MainDeCarte.tirerCarte(2);
    * MainDeCarte.tirerCarte(3);
    * @endcode
    * @warning niveauJoueur doit etre compris entre 0 et 3 
    */
    void tirerCarte (int niveauJoueur);


    /**
    * @brief Permet de demander une unique nouvelle carte au croupier
    * @param[in] niveauJoueur Le niveau du joueur qui est en train de tirer 
    * @return void  
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.doubler(0);
    * MainDeCarte.doubler(1);
    * MainDeCarte.doubler(2);
    * MainDeCarte.doubler(3);
    * @endcode
    * @warning niveauJoueur doit etre compris entre 0 et 3 
    * @warning le joueur peut doubler que lors de sa première action (lorsqu'il à deux cartes uniquement)
    */
    void doubler (int niveauJoueur);


    /**
    * @brief Permet de splitter son jeu lorsque le joueur à deux carte d'une même valeur
    * @param[in] niveauJoueur Le niveau du joueur qui est en train de tirer 
    * @return void  
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.splitter(0);
    * MainDeCarte.splitter(1);
    * MainDeCarte.splitter(2);
    * MainDeCarte.splitter(3);
    * @endcode
    * @warning niveauJoueur doit etre compris entre 0 et 3 
    * @warning le joueur peut splitter que lors de sa première action (lorsqu'il à deux cartes uniquement)
    */
    void splitter (int niveauJoueur);


    /**
    * @brief Permet au joueur de passer son tour lorsque la somme des valeurs de ses cartes lui convient 
    * @param[in] niveauJoueur Le niveau du joueur qui est en train de tirer 
    * @return void  
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.rester(0);
    * MainDeCarte.rester(1);
    * MainDeCarte.rester(2);
    * MainDeCarte.rester(3);
    * @endcode
    * @warning niveauJoueur doit etre compris entre 0 et 3 
    * @warning le joueur peut splitter que lors de sa première action (lorsqu'il à deux cartes uniquement)
    */
    void rester (int niveauJoueur);


    /**
     * @brief   Accesseur : récupère la somme des valeurs des cartes du joueur 
     * @return  unsigned int 
     * 
     * Exemple d'utilisation :
     * @code
     * unsigned char sommeValeur = MainDeCarte.getSommeValeur();
     * @endcode       
     */   
    unsigned int getSommeValeur () const;


    /**
    * @brief   Mutateur : permet de changer la somme des valeurs des cartes
    * @return  void  
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.setSommeValeur(6);
    * MainDeCarte.setSommeValeur(12);
    * @endcode  
    * @warning le joueur peut changer la somme des valeurs de ses cartes UNIQUEMENT lorsqu'il double ou qu'il doit choisir la valeur de l'as (qui vaut 1 ou 11)
    */ 
    void setSommeValeur (int SommeValeur);

    /**
    * @brief Tester la classe et ses fonctionnalités
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.testRegression();
    * @endcode     
    */ 
    void testRegression();


    private : 
    
    /**
    * @brief   sommeValeur est la somme des valeurs des cartes de la main de cartes
    */
    unsigned int sommeValeur;


}