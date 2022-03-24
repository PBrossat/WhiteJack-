#ifndef MAINDECARTE_H
#define MAINDECARTE_H

#include <vector>
#include <iostream>

using namespace std;

class MainDeCarte 
{
    public :


    /**
    * @brief  tableau de Carte
    */
    vector<Carte>Hand;

    /**
    * @brief   nbCartes désigne le nombre de cartes qu'a le joueur dans sa main 
    */
    unsigned int nbCartes;

    /**
    * @brief  Booléen permettant de savoir si le joueur joue encore.
    */
    bool joueToujours;


    /**
    * @brief  Booléen permettant de savoir si la valeur de la somme de ses cartes est supérieur à 21 (0= pas cramé, 1= il a cramé)
    */
    bool cramé?;
    


    /**
    * @brief Destructeur de la classe (sommeValeur=0 et nbCarte=0)
    */
    MainDeCarte();



    /**
    * @brief Constructeur avec parametres de la classe MainDeCarte
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte Main_1(carte1, carte2);
    * @endcode
    */
    MainDeCarte (Carte carte1, Carte carte2);




    /**
    * @brief Destructeur de la classe
    */
    ~MainDeCarte ();



   
    /**
    * @brief Permet de tirer une nouvelle carte
    * @param[in] carteAjoutee La carte que le croupier tire pour le joueur  
    * @return void  
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.tirerCarte(carteAjoutee);
    * @endcode
    */
    void tirerCarte (Carte carteAjoutee);


    /**
    * @brief Permet de demander une unique nouvelle carte au croupier 
    * @param[in] carteAjoutee La carte a ajouter
    * @return void  
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.doubler(carteAjoutee);
    * @endcode
    * @warning Le joueur peut doubler que lors de sa première action (lorsqu'il à deux cartes uniquement)
    */
    void doubler (Carte carteAjoutee);


    /**
    * @brief Permet de splitter son jeu lorsque le joueur à deux carte d'une même valeur
    * @param[in] carteAjoutee1 La carte que le croupier tire pour la main 1 du joueur 
    * @param[in] carteAjoutee2 La carte que le croupier tire pour la main 2 du joueur (la nouvelle main du joueur)
    * @return Cette fonction renvoie une MainDeCarte (car on en crée une nouvelle) 
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.splitter(carteAjoutee1, carteAjoutee2);
    * @endcode
    * @warning Le joueur peut splitter que lors de sa première action (lorsqu'il à deux cartes uniquement)
    */
    MainDeCArte splitter (Carte carteAjoutee1, Carte carteAjoutee2);



    /**
    * @brief Permet au joueur de passer son tour lorsque la somme des valeurs de ses cartes lui convient  
    * @return void  
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.rester();
    * @endcode
    */
    void rester ();



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


};

#endif