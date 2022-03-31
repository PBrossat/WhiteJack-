all :  bin/Deck bin/MainDeCarte bin/Carte bin/Joueur bin/JeuTxt #bin/Jeu 

bin/JeuTxt : obj/mainJeuTxt.o obj/JeuTxt.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o
	g++ -g -Wall obj/mainJeuTxt.o obj/JeuTxt.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o -o bin/JeuTxt

obj/mainJeuTxt.o : src/mainJeuTxt.cpp src/jeuTxt.h src/Jeu.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h
	g++ -g -Wall -c src/mainJeuTxt.cpp -o obj/mainJeuTxt.o

obj/JeuTxt.o : src/jeuTxt.h src/jeuTxt.cpp src/Jeu.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h
	g++ -g -Wall -c src/jeuTxt.cpp -o obj/JeuTxt.o




# bin/Jeu : obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o
# 	g++ -g -Wall obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o -o bin/Jeu

obj/Jeu.o : src/Jeu.cpp src/Jeu.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h
	g++ -g -Wall -c src/Jeu.cpp -o obj/Jeu.o



bin/Joueur : obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCarte.o obj/Carte.o
	g++ -g -Wall obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCarte.o obj/Carte.o -o bin/Joueur

obj/mainTestJoueur.o : src/mainTestJoueur.cpp src/Joueur.h src/MainDeCarte.h src/Carte.h
	g++ -g -Wall -c src/mainTestJoueur.cpp -o obj/mainTestJoueur.o

obj/Joueur.o : src/Joueur.h src/Joueur.cpp src/MainDeCarte.h src/Carte.h
	g++ -g -Wall -c src/Joueur.cpp -o obj/Joueur.o





bin/Deck : obj/mainTestDeck.o obj/Deck.o obj/Carte.o
	g++ -g -Wall obj/mainTestDeck.o obj/Deck.o obj/Carte.o -o bin/Deck 

obj/mainTestDeck.o : src/mainTestDeck.cpp src/Deck.h src/Carte.h
	g++ -g -Wall -c src/mainTestDeck.cpp -o obj/mainTestDeck.o 

obj/Deck.o : src/Deck.h src/Deck.cpp src/Carte.h 
	g++ -g -Wall -c src/Deck.cpp -o obj/Deck.o 





bin/MainDeCarte : obj/mainTestMainDeCarte.o obj/MainDeCarte.o obj/Carte.o
	g++ -g -Wall obj/mainTestMainDeCarte.o obj/MainDeCarte.o obj/Carte.o -o bin/MainDeCarte

obj/mainTestMainDeCarte.o : src/mainTestMainDeCarte.cpp src/MainDeCarte.h src/Carte.h
	g++ -g -Wall -c src/mainTestMainDeCarte.cpp -o obj/mainTestMainDeCarte.o

obj/MainDeCarte.o : src/MainDeCarte.cpp src/MainDeCarte.h src/Carte.h 
	g++ -g -Wall -c src/MainDeCarte.cpp -o obj/MainDeCarte.o





bin/Carte : obj/mainTestCarte.o obj/Carte.o 
	g++ -g -Wall obj/mainTestCarte.o obj/Carte.o -o bin/Carte 

obj/mainTestCarte.o : src/mainTestCarte.cpp src/Carte.h
	g++ -g -Wall -c src/mainTestCarte.cpp -o obj/mainTestCarte.o 

obj/Carte.o : src/Carte.cpp src/Carte.h
	g++ -g -Wall -c src/Carte.cpp -o obj/Carte.o





doc : src/Carte.h src/Deck.h src/MainDeCarte.h src/Joueur.h
	doxygen doc/whitejack.doxy