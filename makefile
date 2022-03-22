all : bin/Joueur

bin/Joueur : obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCartes.o
	g++ -g -Wall obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCartes.o -o bin/Joueur

obj/mainTestJoueur.o : src/mainTestJoueur.cpp src/Joueur.h obj/MainDeCartes.h
	g++ -g -Wall -c src/mainTestJoueur.cpp -o obj/mainTestJoueur.o

obj/Joueur.o : src/Joueur.h src/Joueur.cpp src/MainDeCartes.h
	g++ -g -Wall -c src/Joueur.cpp -o obj/Joueur.o

obj/MainDECartes.o : src/MainDeCartes.cpp src/MainDeCartes.h
	g++ -g -Wall -c src/MainDeCartes.cpp -o obj/MainDeCartes.o