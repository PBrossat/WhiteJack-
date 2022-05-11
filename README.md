# WhiteJack

# Contributeurs : 

    p2020351 Faustmann Lucas
    p2002218 Brossat Pierrick 

# Présentation WhiteJack

	Notre projet: "WhiteJack" est un dérivé bien connu du jeu de casino: le "BlackJack". Dans notre application vous pourrez jouer en mode Solo (contre le croupier) avec les règles classique du "BlackJack". 
    Cependant vous pourrez aussi jouer en mode Multijoueur contre des Intelligences Artificielles que nous avons créée. 
    Le but, dans ce mode, est d'être le dernier en lice apres les 9 manches de la partie. En effet, toute les 3 manches, le joueur ayant le moins d'argent est éliminé de la partie. Vous êtes aussi éliminé de la partie si vous n'avez plus d'argent. 
    Pour créer cette application nous utiliserons la programmation modulaire grâce à de nombreuse classes. 

# Installation des dépendances 

	Nous avons programmés notre projet "WhitJack" en utilisant le language C++ et la librairie graphique SFML.

	Pour installer sous Linux toutes les dépendances nécessaires pour notre projet il faut exécuter la commande suivante :
		~/sudo apt-get install libsfml-dev

	Pour installer g++, le compilateur C++, nécessaire pour compiler notre projet il faut exécuter la commande suivante :
		~/sudo apt-get install g++

# Compilation 

Pour compiler, utiliser la commande make suivante: 

    ~/whitejack$ make (ou make all)
    g++ -g -Wall obj/mainTestCarte.o obj/Carte.o -o bin/Carte 
    g++ -g -Wall obj/mainTestMainDeCarte.o obj/MainDeCarte.o obj/Carte.o -o bin/MainDeCarte
    g++ -g -Wall obj/mainTestDeck.o obj/Deck.o obj/Carte.o -o bin/Deck 
    g++ -g -Wall obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCarte.o obj/Carte.o -o bin/Joueur
    g++ -g -Wall obj/mainTestJeuMulti.o obj/jeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o -o bin/jeuMulti
    g++ -g -Wall obj/mainTestJeu.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o -o bin/Jeu
    g++ -g -Wall obj/mainJeuTxt.o obj/JeuTxt.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o -o bin/JeuTxt
    g++ -g -Wall obj/mainMenuPrincipal.o obj/MenuSfml.o obj/JeuSfml.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o -o bin/MenuSfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
    g++ -g -Wall obj/mainJeuSfml.o obj/JeuSfml.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o -o bin/JeuSfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
    g++ -g -Wall obj/mainJeuMultiSfml.o obj/MultiSfml.o obj/jeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o -o bin/MultiSfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

Pour compiler qu'un seul fichier (exemple ici la classe Carte), utiliser la commande make suivante:

    ~/whitejack$ make bin/Carte 
    g++ -g -Wall obj/mainTestCarte.o obj/Carte.o -o bin/Carte 

Pour "nettoyer" les dossiers bin et obj (supprimer les éxécutables dans bin et les .o dans obj) nous utilisons la commande make suivante: 

    ~/whitejack$ make clean 
    rm -f obj/*
    rm -f bin/*
   
Pour mettre à jour la documentation doxygen, utiliser la commande make suivante :

    ~/whitejack$ make doc


# Arborescence

	whitejack/
	├─ bin/
	│  ├─ contient les exécutables du projet (Carte.bin, Deck.bin, ...)
	├─ data/
	│  ├─ contient les images, les sons et les polices utilisées dans le projet  
	├─ doc/
	│  ├─ whitejack.doxy
	│  ├─ html/
	│  │  ├─ contient tous les fichiers nécessaires à la documentation en html de notre projet
	├─ makefile
	├─ obj/
	│  ├─ contient les fichiers objets du projet (Carte.o, Deck.o, ...)
	├─ Readme.txt
	├─ src/
	│  ├─ Carte.h
	│  ├─ Carte.cpp
	│  ├─ Deck.h
	│  ├─ Deck.cpp
	│  ├─ Jeu.h
	│  ├─ Jeu.cpp
	│  ├─ jeuMulti.h
    │  ├─ jeuMulti.cpp
    │  ├─ jeuSfml.h
    │  ├─ jeuSfml.cpp
    │  ├─ jeuTxt.h
    │  ├─ jeuTxt.cpp
    │  ├─ Joueur.h
    │  ├─ Joueur.cpp
    │  ├─ MainDeCarte.h
    │  ├─ MainDeCarte.cpp
    │  ├─ mainJeuMultiSfml.cpp
    │  ├─ mainJeuSfml.cpp
    │  ├─ mainJeuTxt.cpp
    │  ├─ mainMenuPrincipal.cpp
    │  ├─ mainTestCarte.cpp
    │  ├─ mainTestDeck.cpp
    │  ├─ mainTestJeu.cpp
    │  ├─ mainTestJeuMulti.cpp
    │  ├─ mainTestJoueur.cpp
    │  ├─ mainTestMainDeCarte.cpp
    │  ├─ MenuSfml.cpp
    │  ├─ MenuSfml.h
    │  ├─ MultiSfml.cpp
    │  ├─ MultiSfml.h


- Les fichiers sources (.h et .cpp) sont placés dans le dossier src
- Les images, sons et polices seront toujours placées dans le dossier data
- doc/whitejack.doxy est le fichier de configuration de doxygen
- doc/html/index.html est la page d'entrée de la documentation (générée avec doxygen)


# Utilisation

Le projet permet de créer dix exécutables. Le principal étant bin/MenuSfml.

## bin/MenuSfml : cet exécutable permet d'afficher le Menu du jeu avec trois choix disponible: le mode Solo, le mode MultiJoueur et les règles du jeu. Pour "naviguer" dans celui-ci, utiliser les flèches du clavier et la touche entré pour valider son choix.
## Cet executable est le plus important car c'est celui que l'on appelera si l'on veut jouer au WhiteJack.

	Pour le lancer :
		~/whitejack$ ./bin/MenuSfml

## bin/MultiSfml: cet exécutable permet de lancer le jeu graphique en mode multijoueur sans passer par le menu.

	Pour le lancer :
		~/whitejack$ ./bin/MultiSfml

## bin/jeuSfml : cet exécutable permet de lancer le jeu graphique en mode solo sans passer par le menu.

	Pour le lancer :
		~/whitejack$ ./bin/jeuSfml

## bin/JeuTxt : cet exécutable permet de lancer le jeu texte en mode solo 

    Pour le lancer :
		~/whitejack$ ./bin/JeuTxt


## bin/jeuMulti : cet exécutable permet de lancer la procédure testRegression() de la classe jeuMulti afin de faire passer une multitude de tests et s'assurer que les fonctions de la classe fonctionnent correctement

    Pour le lancer :
		~/whitejack$ ./bin/jeuMulti

## bin/MainDeCarte : cet exécutable permet de lancer la procédure testRegression() de la classe MainDeCarte afin de faire passer une multitude de tests et s'assurer que les fonctions de la classe fonctionnent correctement

    Pour le lancer :
		~/whitejack$ ./bin/MainDeCarte

## bin/Joueur : cet exécutable permet de lancer la procédure testRegression() de la classe Joueur afin de faire passer une multitude de tests et s'assurer que les fonctions de la classe fonctionnent correctement

    Pour le lancer :
		~/whitejack$ ./bin/Joueur

## bin/Jeu : cet exécutable permet de lancer la procédure testRegression() de la classe Jeu afin de faire passer une multitude de tests et s'assurer que les fonctions de la classe fonctionnent correctement

    Pour le lancer :
		~/whitejack$ ./bin/Jeu

## bin/Deck : cet exécutable permet de lancer la procédure testRegression() de la classe Deck afin de faire passer une multitude de tests et s'assurer que les fonctions de la classe fonctionnent correctement

    Pour le lancer :
		~/whitejack$ ./bin/Deck

## bin/Carte : cet exécutable permet de lancer la procédure testRegression() de la classe Carte afin de faire passer une multitude de tests et s'assurer que les fonctions de la classe fonctionnent correctement

    Pour le lancer :
		~/whitejack$ ./bin/Carte



# Documentation du code

Voir doc/html/index.html pour accéder à la documentation de toute les classes de notre projet. 


