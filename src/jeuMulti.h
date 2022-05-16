#ifndef JEUMULTI_H
#define JEUMULTI_H
#include <iostream>
#include "MainDeCartes.h"
#include "Carte.h"
#include "Deck.h"
#include "Joueur.h"
#include "JeuSolo.h"

class JeuMulti{
    
    public : 

    /**
    * @brief Tableau contenant les joueurs de la partie
    */
    vector<Joueur>tabJoueur;



    /**
    * @brief La main de carte du croupier
    */
	MainDeCartes mainCroupier;



    /**
    @brief Le nombre de partie effectuées
    */
    unsigned int nbManches;



    /**
    @brief Le nombre de joueur encore présents
    */
    unsigned int nbJoueurs;



    /**
     * @brief Procédure permettant de gérer automatiquement les actions du croupier 
     * @return void
     * 
     * Exemple d'utilisation :
     * @code
     * unJeuMulti.actionCroupier();
     * @endcode
    */
	void actionCroupier();



    /**
    * @brief Procédure permettant d'initialiser et de créer les joueurs (IA) selon le niveau choisi
    * @param[in] NiveauJoueur : le niveau des IA avec lesquelles le joueur jouera sa partie. 
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.remplirJoueurs(2);
    * @endcode
    * @warning NiveauJoueur doit être compris entre 1 et 3 compris (1=amateur ; 2=intermédiaire ; 3=expert).
    */
	void remplirJoueurs(unsigned int NiveauJoueur);



    /**
    * @brief Constructeur sans paramètres de JeuMulti.
    * 
    * Exemple d'utilisation :
    * @code
    * JeuMulti unJeuMulti;
    * @endcode
    * @warning Attention, aucun joueur n'est créé
    */
    JeuMulti ();



    /**
    * @brief Destructeur de JeuMulti.
    */
    ~JeuMulti();



    /**
    * @brief Constructeur avec paramètre de JeuMulti.
    * @param[in] NiveauJoueur : le niveau des IA avec lesquelles le joueur jouera sa partie.
    *  
    * Exemple d'utilisation :
    * @code
    * JeuMulti unJeuMulti(1);
    * JeuMulti unJeuMulti(2);
    * JeuMulti unJeuMulti(3);
    * @endcode
    * @warning NiveauJoueur doit être compris entre 1 et 3 compris (1=amateur ; 2=intermédiaire ; 3=expert).
    */
    JeuMulti(unsigned int NiveauJoueur);



    /**
    * @brief Procédure permettant d'éliminer un joueur soit si il n'a plus d'argent,
    * soit si il a le moins d'argent à la partie 3, 6 ou 9.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.eliminationJoueur();
    * @endcode
    */
    void eliminationJoueur();



    /**
     * @brief Fonction permettant de déterminer les gains du joueur et renvoyant un entier 
     * déterminant le résultat (gagné,perdu,blackjack...)
     * @param[in] indiceJoueur : l'indice du joueur pour lequel on veut obtenir le résultat
     * @return unsigned int : 0 pour perdu, 1 pour égalité, 2 pour gagné, 3 pour blackjack
     * 
     * Exemple d'utilisation :
     * @code
     * unJeuMulti.resultat(0);
     * @endcode
     * @warning À faire qu'à la fin de la partie
    */
	unsigned int resultat(unsigned int indiceJoueur); 



    /**
    * @brief Procédure permettant de faire miser aléaoirement les IA, celles-ci peuvent miser les mises suivantes: 
    * 100, 200, 300, 500 ou 1000.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.initialisationMiseMulti();
    * @endcode
    */
    void initialisationMiseMulti();



    /**
     * @brief Procédure permettant de saisir la mise de départ
     * @param[in] touche : la touche saisie par l'utilisateur
     * @return void
     * 
     * Exemple d'utilisation :
      * unJeu.initialisationMise();
     * @endcode
     * @warning La mise saisie doit être inférieur au budget du joueur (2000)
     * @warning Le parametre touche doit etre obligatoirement 'a' pour 1, 'z' pour 10, 'e' pour 100, 'r' pour 250 ou 't' pour 500
    */
    void initialisationMise(const char touche);



    /**
    * @brief Procédure permettant de distribuer 2 cartes aux joueurs (le joueur physique derrière son écran et les IA)
    * et 1 carte au croupier.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.initialisationJeuMulti();
    * @endcode
    */
    void initialisationJeuMulti();



    /**
     * @brief Procédure permettant d'adapter les actions suivant les touches pressées par l'utilisateur
     * @param[in] touche : la touche saisie par l'utilisateur
     * @return void
     * 
     * Exemple d'utilisation :
     * @code
     * unJeuMulti.actionClavier('a');
     * @endcode
     * @warning Le parametre touche doit etre obligatoirement 't', 'd', 'r', 'c' 
    */
	void actionClavier(const char touche);



    /**
    * @brief Procédure permettant d'effectuer les actions des IAs si NiveauJoueur est égal à 3.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.actionExpert();
    * @endcode
    */   
    void actionExpert();



    /**
    * @brief Procédure permettant d'effectuer les actions des IAs si NiveauJoueur est égal à 2.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.actionIntermediaire();
    * @endcode
    */   
    void actionIntermediaire();



    /**
    * @brief Procédure permettant d'effectuer les actions des IAs si NiveauJoueur est égal à 1. 
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.actionAmateur();
    * @endcode
    */   
    void actionAmateur();



    /**
    * @brief Procédure permettant d'effectuer les actions des IAs selon NiveauJoueur.
    * @return void
    * @param[in] NiveauJoueur : le niveau des IA avec lesquelles le joueur jouera sa partie.
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.actionIA(1);
    * unJeuMulti.actionIA(2);
    * unJeuMulti.actionIA(3);
    * @endcode
    * @warning NiveauJoueur doit être compris entre 1 et 3 compris (1=amateur ; 2=intermédiaire ; 3=expert).
    */      
    void actionIA(unsigned int NiveauJoueur);



    /**
     * @brief Procédure permettant de réinitialiser les mains de cartes des joueurs et du croupier 
     * @return void
     * 
     * Exemple d'utilisation :
     * @code
     * unJeuMulti.finManche();
     * @endcode
     * @warning À faire à chaque fin de partie
    */ 
	void finManche();



    /**
    * @brief Procédure permettant de tester les fonctionnalités de la classe.
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * unJeuMulti.testRegression();
    * @endcode
    */
    void testRegression() const; 



    private:



    //Le niveau choisi au hasard dans la fonction actionIntermediaire().
    unsigned int nvHasard;

    //Le pourcentage (entre 40 et 60) pour determiner le ratio/le niveau du joueur.
	unsigned int randPourcentage;

    //La deuxième carte du croupier (cachée lorsque le joueur joue)  
	Carte deuxiemeCarteCroupier;

    //Le deck du jeu
	Deck unDeck;

};
#endif
