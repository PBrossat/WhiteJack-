all : bin/Joueur

bin/Joueur : obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCarte.o
	g++ -g -Wall obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCarte.o -o bin/Joueur

obj/mainTestJoueur.o : src/mainTestJoueur.cpp src/Joueur.h src/MainDeCarte.h
	g++ -g -Wall -c src/mainTestJoueur.cpp -o obj/mainTestJoueur.o

obj/Joueur.o : src/Joueur.h src/Joueur.cpp src/MainDeCarte.h
	g++ -g -Wall -c src/Joueur.cpp -o obj/Joueur.o

obj/MainDeCartes.o : src/MainDeCarte.cpp src/MainDeCarte.h
	g++ -g -Wall -c src/MainDeCarte.cpp -o obj/MainDeCarte.o