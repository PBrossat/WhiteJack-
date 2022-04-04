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
    * @brief Constructeur de la classe sans paramètres
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte uneMain;
    * @endcode
    * @warning initialise nbCartes, sommeValeur, crame à 0 et joueToujours à 1
    */
    MainDeCarte();




    /**
    * @brief Constructeur avec parametres de la classe MainDeCarte
    * @param[in,out] carte1 la première carte de la main (mode donnée-résultat mais CONST)
    * @param[in,out] carte2 la deuxième carte de la main (mode donnée-résultat mais CONST)
    * 
    * Exemple d'utilisation :
    * @code
    * MainDeCarte uneMain(carte1, carte2);
    * @endcode
    */
    MainDeCarte (const Carte& carte1, const Carte& carte2);




    /**
    * @brief Permet de tirer une nouvelle carte
    * @param[in,out] carteAjoutee La carte que le croupier tire pour le joueur  (mode donnée-résultat mais CONST)
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
    * @brief Permet de verifier si le score du joueur est inferieur ou egal à 21  
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
    */
    Carte getIemeCarte(unsigned int indice) const;

    

    /**
     * @brief   Accesseur : récupère la somme des valeurs des cartes du joueur 
     * @return  unsigned int 
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
    * uneMainDeCarte.setSommeValeur(12);
    * @endcode  
    */ 
    void setSommeValeur (unsigned int SommeValeur);




    /**
     * @brief   Accesseur : récupère le nombre de cartes du joueur 
     * @return  unsigned int 
     * 
     * Exemple d'utilisation :
     * @code
     * unsigned int NbCarte = uneMainDeCarte.getNbCarte();
     * @endcode       
     */   
    unsigned int getNbCartes () const;




    /**
     * @brief   Accesseur : récupère le booléen permettant de savoir si le joueur joue toujours.
     * @return  bool
     * 
     * Exemple d'utilisation :
     * @code
     * uneMainDeCarte.getJoueToujours();
     * @endcode       
     */   
    bool getJoueToujours () const;




    /**
     * @brief   Accesseur : récupère le booléen permettant de savoir si le joueur a cramé.
     * @return  bool
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
    * @brief Tester la classe et ses fonctionnalités
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * uneMainDeCarte.testRegression();
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


    //Booléen permettant de savoir si la valeur de la somme de ses cartes est supérieur à 21 (0= pas cramé, 1= il a cramé)
    bool crame;
    


};

#endif