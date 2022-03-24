all : bin/Joueur bin/Deck

bin/Joueur : obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCarte.o
	g++ -g -Wall obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCarte.o -o bin/Joueur

obj/mainTestJoueur.o : src/mainTestJoueur.cpp src/Joueur.h src/MainDeCarte.h
	g++ -g -Wall -c src/mainTestJoueur.cpp -o obj/mainTestJoueur.o

obj/Joueur.o : src/Joueur.h src/Joueur.cpp src/MainDeCarte.h
	g++ -g -Wall -c src/Joueur.cpp -o obj/Joueur.o

obj/MainDeCartes.o : src/MainDeCarte.cpp src/MainDeCarte.h
	g++ -g -Wall -c src/MainDeCarte.cpp -o obj/MainDeCarte.o

bin/Deck : obj/mainTestDeck.o obj/Deck.o obj/Carte.o
	g++ -g -Wall obj/mainTestDeck.o obj/Deck.o obj/Carte.o -o bin/Deck 

obj/mainTestDeck.o : src/mainTestDeck.cpp src/Deck.h src/Carte.h
	g++ -g -Wall -c src/mainTestDeck.cpp -o obj/mainTestDeck.o 

obj/Deck.o : src/Deck.h src/Deck.cpp src/Carte.h 
	g++ -g -Wall -c src/Deck.cpp -o obj/Deck.o 

obj/Carte.o : src/Carte.cpp src/Carte.h
	g++ -g -Wall -c src/Carte.cpp -o obj/Carte.o

<<<<<<< HEAD
obj/mainTestMainDeCarte.o : src/mainTestMainDeCarte.cpp src/MainDeCarte.h src/Carte.h
	g++ -g -Wall -c src/mainTestMainDeCarte.cpp -o obj/mainTestMainDeCarte.o

bin/mainTestMainDeCarte : obj/mainTestMainDeCarte.o obj/MainDeCarte.o obj/Carte.h
	g++ -g -Wall obj/mainTestMainDeCarte.o obj/MainDeCarte.o -o bin/MainDeCarte
=======
>>>>>>> ae98213b556536c9a6d1a4e95e384d878abfde99
