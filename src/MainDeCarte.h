#ifndef MAINDECARTE_H
#define MAINDECARTE_H
#include "Carte.h"
#include <vector>
#include <iostream>

using namespace std;

class MainDeCarte 
{
    public :



    /**
    * @brief Constructeur de la classe (sommeValeur=0 et nbCarte=0)
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
    MainDeCarte (const Carte& carte1, const Carte& carte2);




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
    void tirerCarte (const Carte& carteAjoutee);




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
    void doubler (const Carte& carteAjoutee);




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
    //MainDeCarte splitter (Carte carteAjoutee1, Carte carteAjoutee2);




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
    * @brief Permet de verifier si le score du joueur est inferieur ou egal à 21  
    * @return void  
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.verifScore();
    * @endcode
    */
    void verifScore ();




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
     * @brief   Accesseur : récupère le nombre de cartes du joueur 
     * @return  unsigned int 
     * 
     * Exemple d'utilisation :
     * @code
     * unsigned int NbCarte = MainDeCarte.getNbCarte();
     * @endcode       
     */   
    unsigned int getNbCartes () const;




    /**
     * @brief   Accesseur : récupère le booléen permettant de savoir si le joueur joue toujours.
     * @return  bool
     * 
     * Exemple d'utilisation :
     * @code
     * MainDeCarte.getJoueToujours();
     * @endcode       
     */   
    bool getJoueToujours () const;




    /**
     * @brief   Accesseur : récupère le booléen permettant de savoir si le joueur a cramé.
     * @return  bool
     * 
     * Exemple d'utilisation :
     * @code
     * MainDeCarte.getCrame();
     * @endcode       
     */   
    bool getCrame () const;




    /**
    * @brief Tester la classe et ses fonctionnalités
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte.testRegression();
    * @endcode     
    */ 
    void testRegression() const;


    private : 
    
    /**
    * @brief   sommeValeur est la somme des valeurs des cartes de la main de cartes
    */
    unsigned int sommeValeur;


    /**
    * @brief  tableau de Carte
    */
    vector<Carte>mainDeJoueur;

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
    bool crame;
    


};

#endif