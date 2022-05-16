# WhiteJack

    Lien vers le projet : https://forge.univ-lyon1.fr/p2020351/whitejack
    Identifiant du projet sur la forge : 23537

# Contributeurs : 

    p2002218 Brossat Pierrick 
    p2020351 Faustmann Lucas

# Présentation WhiteJack :

    Dans le cadre de l'UE LIFAP4, nous devions implémenter une application, et nous avons décidé de créer un jeu de cartes.
    Pour plus d'informations sur le projet, se référer au site de l'UE: 
        https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4#projetrealisation_en_tp

	Notre projet: "WhiteJack" est un dérivé bien connu du jeu de casino: le "BlackJack". Dans notre application vous pourrez jouer en mode Solo (contre le croupier) avec les règles classique du "BlackJack". 
    Cependant vous pourrez aussi jouer en mode Multijoueur contre des Intelligences Artificielles que nous avons créée. 
    Le but, dans ce mode, est d'être le dernier en lice apres les 9 manches de la partie. En effet, toute les 3 manches, le joueur ayant le moins d'argent est éliminé de la partie. Vous êtes aussi éliminé de la partie si vous n'avez plus d'argent. 
    Pour créer cette application nous utiliserons la programmation modulaire grâce à de nombreuse classes. 

# Règles du jeu : 

Le blackjack est un jeu de cartes joué dans les casinos où l’objectif est de gagner de l’argent en faisant des mises au début de chaque partie. Ce jeu se joue avec des jeux de cartes habituels où chaque carte représente un certain nombre de points (entre 1 et 11) 
et le but est d’avoir un score le plus proche possible de 21 sans jamais pour autant dépassé cette limite mais tout en ayant un meilleur score que le croupier, la personne distribuant les cartes et représentant le casino. 
Si jamais le score du joueur dépasse 21 (score cumulé des cartes), le joueur est déclaré automatiquement perdant (on dit que le joueur crame). Au début d’une nouvelle partie, les joueurs décident de l’argent qu’ils misent puis le croupier distribue deux cartes face visible à chaque joueur en lice et se distribue également une carte face visible et une autre face cachée. Le premier à jouer est celui à qui le croupier a donné la première carte.

Selon son jeu, un joueur peut effectuer diverses actions :
    • Tirer : demander une nouvelle carte (tant que son score ne dépasse pas 21)
    • Doubler : demander une et une seule nouvelle carte (impossible de tirer par la suite) et doubler sa mise de départ (il n’est possible de doubler que lors de sa première action)
    • Changer : permet de changer sa deuxième carte par une autre et doubler sa mise de départ. Ceci n’est possible que si vous obtenez deux cartes d’une même valeur.
    • Rester : le joueur décide de garder son jeu tel qu’il est (c’est alors au tour des autres joueurs)

Une fois que tous les joueurs ont fini de jouer, c’est au tour de croupier. Ce dernier retourne sa carte face
cachée et si son score est inférieur à 17 alors il est contraint à tirer une autre carte, et ce jusqu’à ce qu’on
son score soit supérieur ou égal à 17.
Lorsque le croupier a fini de jouer à son tour, la partie se termine et vient le moment des résultats :
    • Un joueur avec un score inférieur à celui du croupier, ou supérieur à 21 perd sa mise de départ
    • Un joueur ayant le même résultat que la banque (inférieur à 21) récupère sa mise de départ
    • Un joueur avec un score de 21 en deux cartes, c’est-à-dire un Blackjack, récupère 2,5 fois sa mise
    de départ
    • Un joueur ayant un score supérieur à celui du croupier et inférieur ou égal à 21 (sans Blackjack)
    récupère deux fois sa mise de départ
    • Si le croupier a un score supérieur à 21, les joueurs encore en lice (avec un score inférieur ou égal à
    21) récupère deux fois leur mise de départ.

Mode Solo :

En ce qui concerne le mode solo, il s’agira d’un mode tout à fait ordinaire, avec les règles originelles. Le joueur sera tout seul autour de la table avec le croupier. 

Mode Multijoueur (contre IA) :

Pour ce qui est du mode multijoueur, l’idée est que le joueur joue contre la banque, c’est-à-dire le croupier, mais aussi contre d’autres joueurs, ceux-ci sont fictifs dans notre cas (IA).
En fait, l’objectif principal de ce mode multijoueur est d’être le dernier joueur en lice contre la banque. Au début d’une partie, le joueur se retrouve à une table avec également trois autres joueurs fictifs avec le même budget qu’eux.
L’idée est qu’au bout de trois manches, le joueur avec le moins d’argent se fasse éliminer. Ainsi, en répétant ce processus, le joueur gagnant sera celui avec le plus de budget lors de la dernière manche, c’est-à-dire la neuvième. 
Si un joueur perd la totalité de son budget, ce dernier se retrouve automatiquement éliminer de la table.
Les IA auront un niveau que vous choisirez. 
    • Amateur : l’IA se contente de tirer et rester, elle joue de manière très simple (sans doubler, changer, …)
    • Intermédiaire : le niveau de l’IA se situe entre amateur et expert 
    • Expert : l’IA joue exactement les coups préconisés afin d’avoir une probabilité de victoires et donc de gains la plus optimale possible grâce au tableau 


# Installation de WSL si votre machine tourne sous Windows :

    WSL permet d'avoir Linux sous Windows.
    Pour instaler WSL, se référer au lien suivant (lien vers le site de L'UE) :
        https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4#wsl_pour_faire_tourner_un_linux_ultra_leger_sous_windows

    Léger, pratique, rapide et suffisant pour de nombreuses applications.
    Windows/WSL est exactement comme une machine Linux avec des drivers minimalistes, donc la gestion de certains périphériques comme la carte son ou l'accélération 3D peut ne pas marcher. 
    Il faut par contre que vous ayez installé XMing pour pouvoir ouvrir des fenêtres comme expliqué sur la page du cours. 
    

# Librairie SFML :

    SFML offre une interface simple vers les différents composants de votre PC, afin de faciliter le développement de jeux ou d'applications multimedia. Elle se compose de cinq modules : système, fenêtrage, graphisme, audio et réseau.
    De plus cette librairie est multi-platefrome. 

    Découvrez plus en détail ses fonctionnalités grâce à la documentation detaillée : 
        https://www.sfml-dev.org/documentation/2.5.1-fr/index.php

    Pour télécharger la librairie, se référer au lien suivant permettant d'installer SFML sous Linux, Mac OS et autre OS :
        https://www.sfml-dev.org/download/sfml/2.5.1/index-fr.php

    Pour accéder à un tutoriel détaillé permettant de découvrir SFML, se référer au lien suivant :
        https://www.sfml-dev.org/tutorials/2.5/index-fr.php


# Installation des dépendances :

	Nous avons programmés notre projet "WhiteJack" en utilisant le language C++ et la librairie graphique SFML.

	Pour installer sous Linux toutes les dépendances nécessaires pour notre projet il faut exécuter la commande suivante :
		~/sudo apt-get install libsfml-dev
    
    Pour les installer sous Mac OS ou Windows, se référer au lien suivant :
        https://www.sfml-dev.org/download/sfml/2.5.1/index-fr.php

	Pour installer g++, le compilateur C++, sous Linux nécessaire pour compiler notre projet il faut exécuter la commande suivante :
		~/sudo apt-get install g++

    Pour Mac OS, veuillez installer XCode, disponible sur l'App Store de votre appareil :
        https://apps.apple.com/fr/app/xcode/id497799835?mt=12


# Utilisation de git :

    Pour récupérer l'archive de notre projet il suffit d'utiliser la ligne de commande suivante :
        ~/Projet$ git clone https://forge.univ-lyon1.fr/p2020351/whitejack nomProjet 
    Où "nomProjet" désigne le nom ue vous voulez donner a l'application (on considérera ici qu'il s'appelle 'whitejack')

    Pour récupérer les changements effectués par un autre developpeur, nous avons utiliser la commande suivante:
        ~/whitejack$ git pull 

    Pour effectuer des changements, nous avons utiliser les commandes suivantes :
        ~/whitejack$ git add .                          
        ~/whitejack$ git commit -m "commentaire"    
        ~/whitejack$ git push 

    Pour plus d'informations sur l'utilisation de git, se référer à la documentation :
        https://git-scm.com/doc


# Compilation 

Pour compiler, utiliser la commande make suivante: 

    ~/whitejack$ make (ou make all)
    g++ -g -Wall obj/mainApplication.o obj/Application.o obj/MenuSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/JeuMultiSfml.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/Appli -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
    g++ -g -Wall -c src/mainApplication.cpp -o obj/mainApplication.o -I/usr/local/include/SFML
    g++ -g -Wall -c src/Application.cpp -o obj/Application.o -I/usr/local/include/SFML
    g++ -g -Wall obj/mainJeuMultiSfml.o obj/JeuMultiSfml.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuMultiSfml -lsfml-graphics -lsfml-window -lsfml-system 
    -lsfml-audio 
    g++ -g -Wall -c src/mainJeuMultiSfml.cpp -o obj/mainJeuMultiSfml.o -I/usr/local/include/SFML
    g++ -g -Wall -c src/JeuMultiSfml.cpp -o obj/JeuMultiSfml.o -I/usr/local/include/SFML
    g++ -g -Wall obj/mainJeuSoloSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuSoloSfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
    g++ -g -Wall -c src/mainJeuSoloSfml.cpp -o obj/mainJeuSoloSfml.o -I/usr/local/include/SFML
    g++ -g -Wall -c src/JeuSoloSfml.cpp -o obj/JeuSoloSfml.o -I/usr/local/include/SFML
    g++ -g -Wall obj/mainMenuSfml.o obj/MenuSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/MenuSfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
    g++ -g -Wall -c src/mainMenuSfml.cpp -o obj/mainMenuSfml.o -I/usr/local/include/SFML
    g++ -g -Wall -c src/MenuSfml.cpp -o obj/MenuSfml.o -I/usr/local/include/SFML
    g++ -g -Wall obj/mainJeuSoloTxt.o obj/JeuSoloTxt.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o obj/WinTxt.o -o bin/JeuSoloTxt
    g++ -g -Wall -c src/mainJeuSoloTxt.cpp -o obj/mainJeuSoloTxt.o
    g++ -g -Wall -c src/JeuSoloTxt.cpp -o obj/JeuSoloTxt.o
    g++ -g -Wall -c src/WinTxt.cpp -o obj/WinTxt.o
    g++ -g -Wall obj/mainTestJeuSolo.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuSolo
    g++ -g -Wall -c src/mainTestJeuSolo.cpp -o obj/mainTestJeuSolo.o
    g++ -g -Wall -c src/JeuSolo.cpp -o obj/JeuSolo.o
    g++ -g -Wall obj/mainTestJeuMulti.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuMulti
    g++ -g -Wall -c src/mainTestJeuMulti.cpp -o obj/mainTestJeuMulti.o
    g++ -g -Wall -c src/JeuMulti.cpp -o obj/JeuMulti.o
    g++ -g -Wall obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCartes.o obj/Carte.o -o bin/Joueur
    g++ -g -Wall -c src/mainTestJoueur.cpp -o obj/mainTestJoueur.o
    g++ -g -Wall -c src/Joueur.cpp -o obj/Joueur.o
    g++ -g -Wall obj/mainTestDeck.o obj/Deck.o obj/Carte.o -o bin/Deck 
    g++ -g -Wall -c src/mainTestDeck.cpp -o obj/mainTestDeck.o
    g++ -g -Wall -c src/Deck.cpp -o obj/Deck.o
    g++ -g -Wall obj/mainTestMainDeCartes.o obj/MainDeCartes.o obj/Carte.o -o bin/MainDeCartes
    g++ -g -Wall -c src/mainTestMainDeCartes.cpp -o obj/mainTestMainDeCartes.o
    g++ -g -Wall -c src/MainDeCartes.cpp -o obj/MainDeCartes.o
    g++ -g -Wall obj/mainTestCarte.o obj/Carte.o -o bin/Carte 
    g++ -g -Wall -c src/mainTestCarte.cpp -o obj/mainTestCarte.o
    g++ -g -Wall -c src/Carte.cpp -o obj/Carte.o



Pour compiler qu'un seul fichier (exemple ici la classe Carte), utiliser la commande make suivante:

    ~/whitejack$ make bin/Carte 
    g++ -g -Wall -c src/Carte.cpp -o obj/Carte.o
    g++ -g -Wall -c src/mainTestCarte.cpp -o obj/mainTestCarte.o 
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
	│  ├─ JeuSolo.h
	│  ├─ JeuSolo.cpp
	│  ├─ JeuMulti.h
    │  ├─ JeuMulti.cpp
    │  ├─ JeuSoloSfml.h
    │  ├─ JeuSoloSfml.cpp
    │  ├─ JeuSoloTxt.h
    │  ├─ JeuSoloTxt.cpp
    │  ├─ Joueur.h
    │  ├─ Joueur.cpp
    │  ├─ MainDeCartes.h
    │  ├─ MainDeCartes.cpp
    │  ├─ mainJeuMultiSfml.cpp
    │  ├─ mainJeuSfml.cpp
    │  ├─ mainJeuTxt.cpp
    │  ├─ mainMenuPrincipal.cpp
    │  ├─ mainTestCarte.cpp
    │  ├─ mainTestDeck.cpp
    │  ├─ mainTestJeu.cpp
    │  ├─ mainTestJeuMulti.cpp
    │  ├─ mainTestJoueur.cpp
    │  ├─ mainTestMainDeCartes.cpp
    │  ├─ MenuSfml.cpp
    │  ├─ MenuSfml.h
    │  ├─ JeuMultiSfml.cpp
    │  ├─ JeuMultiSfml.h
    │  ├─ Application.h
    │  ├─ Application.cpp

- Les fichiers sources (.h et .cpp) sont placés dans le dossier src
- Les images, sons et polices seront toujours placées dans le dossier data
- doc/whitejack.doxy est le fichier de configuration de doxygen
- doc/html/index.html est la page d'entrée de la documentation (générée avec doxygen)


# Utilisation

Le projet permet de créer onze exécutables. Le principal étant bin/Appli.

## bin/Appli:
    Cet exécutable permet de lancer l'application.

    Pour le lancer :
		~/whitejack$ ./bin/Appli

## bin/MenuSfml : 
    Cet exécutable permet d'afficher le Menu du jeu avec trois choix disponibles: le mode Solo, le mode MultiJoueur et les règles du jeu. Pour "naviguer" dans celui-ci, utiliser les flèches du clavier et la touche entrée pour valider votre choix. 

	Pour le lancer :
		~/whitejack$ ./bin/MenuSfml

## bin/JeuMultiSfml: 
    Cet exécutable permet de lancer le jeu graphique en mode multijoueur sans passer par le menu.

	Pour le lancer :
		~/whitejack$ ./bin/JeuMultiSfml

## bin/JeuSoloSfml : 
    Cet exécutable permet de lancer le jeu graphique en mode solo sans passer par le menu.

	Pour le lancer :
		~/whitejack$ ./bin/JeuSoloSfml

## bin/JeuSoloTxt :
    Cet exécutable permet de lancer le jeu texte en mode solo.

    Pour le lancer :
		~/whitejack$ ./bin/JeuSoloTxt


## bin/JeuMulti : 
    Cet exécutable permet de lancer la procédure testRegression() de la classe jeuMulti afin de faire passer une multitude de tests et   s'assurer que les fonctions de la classe fonctionnent correctement.

    Pour le lancer :
		~/whitejack$ ./bin/JeuMulti

## bin/MainDeCartes : 
    Cet exécutable permet de lancer la procédure testRegression() de la classe MainDeCarte afin de faire passer une multitude de tests et s'assurer que les fonctions de la classe fonctionnent correctement

    Pour le lancer :
		~/whitejack$ ./bin/MainDeCartes

## bin/Joueur : 
    Cet exécutable permet de lancer la procédure testRegression() de la classe Joueur afin de faire passer une multitude de tests et s'assurer que les fonctions de la classe fonctionnent correctement

    Pour le lancer :
		~/whitejack$ ./bin/Joueur

## bin/JeuSolo : 
    Cet exécutable permet de lancer la procédure testRegression() de la classe Jeu afin de faire passer une multitude de tests et s'assurer que les fonctions de la classe fonctionnent correctement

    Pour le lancer :
		~/whitejack$ ./bin/JeuSolo

## bin/Deck : 
    Cet exécutable permet de lancer la procédure testRegression() de la classe Deck afin de faire passer une multitude de tests et s'assurer que les fonctions de la classe fonctionnent correctement

    Pour le lancer :
		~/whitejack$ ./bin/Deck

## bin/Carte : 
    Cet exécutable permet de lancer la procédure testRegression() de la classe Carte afin de faire passer une multitude de tests et s'assurer que les fonctions de la classe fonctionnent correctement

    Pour le lancer :
		~/whitejack$ ./bin/Carte



# Documentation du code :

    Voir doc/html/index.html pour accéder à la documentation de toute les classes de notre projet. 


# Remerciement :

    Nous remercions Madame Elodie Desseree ainsi que Monsieur Alexandre Meyer pour leurs conseils et leur aide tout au long de la réalisation du projet. 