all :  bin/Deck bin/MainDeCarte bin/Carte bin/Joueur bin/JeuTxt bin/Jeu bin/JeuSfml bin/jeuMulti bin/MenuSfml bin/MultiSfml bin/Appli


bin/Appli : obj/mainApplication.o obj/Application.o obj/MenuSfml.o obj/JeuSfml.o obj/Jeu.o obj/MultiSfml.o obj/jeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o
	g++ -g -Wall obj/mainApplication.o obj/Application.o obj/MenuSfml.o obj/JeuSfml.o obj/Jeu.o obj/MultiSfml.o obj/jeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o  -o bin/Appli -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

obj/mainApplication.o : src/mainApplication.cpp src/application.h src/MenuSfml.h src/jeuSfml.h src/Jeu.h src/MultiSfml.h src/jeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h src/winTxt.h
	g++ -g -Wall -c src/mainApplication.cpp -o obj/mainApplication.o -I/usr/local/include/SFML

obj/Application.o : src/application.cpp src/application.h src/MenuSfml.h src/jeuSfml.h src/Jeu.h src/MultiSfml.h src/jeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h src/winTxt.h
	g++ -g -Wall -c src/application.cpp -o obj/Application.o -I/usr/local/include/SFML


bin/MultiSfml : obj/mainJeuMultiSfml.o obj/MultiSfml.o obj/jeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o
	g++ -g -Wall obj/mainJeuMultiSfml.o obj/MultiSfml.o obj/jeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o -o bin/MultiSfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

obj/mainJeuMultiSfml.o : src/mainJeuMultiSfml.cpp src/MultiSfml.h src/jeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h src/winTxt.h
	g++ -g -Wall -c src/mainJeuMultiSfml.cpp -o obj/mainJeuMultiSfml.o -I/usr/local/include/SFML

obj/MultiSfml.o : src/MultiSfml.h src/MultiSfml.cpp src/jeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h src/winTxt.h
	g++ -g -Wall -c src/MultiSfml.cpp -o obj/MultiSfml.o -I/usr/local/include/SFML



bin/JeuSfml : obj/mainJeuSfml.o obj/JeuSfml.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o
	g++ -g -Wall obj/mainJeuSfml.o obj/JeuSfml.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o -o bin/JeuSfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

obj/mainJeuSfml.o : src/mainJeuSfml.cpp src/jeuSfml.h src/Jeu.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h src/winTxt.h
	g++ -g -Wall -c src/mainJeuSfml.cpp -o obj/mainJeuSfml.o -I/usr/local/include/SFML

obj/JeuSfml.o : src/jeuSfml.h src/jeuSfml.cpp src/Jeu.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h src/winTxt.h
	g++ -g -Wall -c src/jeuSfml.cpp -o obj/JeuSfml.o -I/usr/local/include/SFML



bin/MenuSfml : obj/mainMenuPrincipal.o obj/MenuSfml.o obj/JeuSfml.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o
	g++ -g -Wall obj/mainMenuPrincipal.o obj/MenuSfml.o obj/JeuSfml.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o -o bin/MenuSfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

obj/mainMenuPrincipal.o : src/mainMenuPrincipal.cpp src/MenuSfml.h src/jeuSfml.h src/Jeu.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h src/winTxt.h
	g++ -g -Wall -c src/mainMenuPrincipal.cpp -o obj/mainMenuPrincipal.o -I/usr/local/include/SFML

obj/MenuSfml.o : src/MenuSfml.h src/MenuSfml.cpp src/jeuSfml.h src/jeuSfml.cpp src/Jeu.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h src/winTxt.h
	g++ -g -Wall -c src/MenuSfml.cpp -o obj/MenuSfml.o -I/usr/local/include/SFML




bin/JeuTxt : obj/mainJeuTxt.o obj/JeuTxt.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o
	g++ -g -Wall obj/mainJeuTxt.o obj/JeuTxt.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o obj/winTxt.o -o bin/JeuTxt

obj/mainJeuTxt.o : src/mainJeuTxt.cpp src/jeuTxt.h src/Jeu.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h src/winTxt.h
	g++ -g -Wall -c src/mainJeuTxt.cpp -o obj/mainJeuTxt.o

obj/JeuTxt.o : src/jeuTxt.h src/jeuTxt.cpp src/Jeu.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h src/winTxt.h
	g++ -g -Wall -c src/jeuTxt.cpp -o obj/JeuTxt.o




obj/winTxt.o : src/winTxt.cpp src/winTxt.h
	g++ -g -Wall -c src/winTxt.cpp -o obj/winTxt.o



bin/Jeu : obj/mainTestJeu.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o
	g++ -g -Wall obj/mainTestJeu.o obj/Jeu.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o -o bin/Jeu

obj/mainTestJeu.o : src/mainTestJeu.cpp src/Jeu.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h
	g++ -g -Wall -c src/mainTestJeu.cpp -o obj/mainTestJeu.o

obj/Jeu.o : src/Jeu.cpp src/Jeu.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h
	g++ -g -Wall -c src/Jeu.cpp -o obj/Jeu.o



bin/jeuMulti : obj/mainTestJeuMulti.o obj/jeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o 
	g++ -g -Wall obj/mainTestJeuMulti.o obj/jeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCarte.o -o bin/jeuMulti

obj/mainTestJeuMulti.o : src/mainTestJeuMulti.cpp src/jeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h
	g++ -g -Wall -c src/mainTestJeuMulti.cpp -o obj/mainTestJeuMulti.o

obj/jeuMulti.o: src/jeuMulti.cpp src/jeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCarte.h
	g++ -g -Wall -c src/jeuMulti.cpp -o obj/jeuMulti.o



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



clean : 
	rm -f obj/*
	rm -f bin/*



doc : src/Carte.h src/Deck.h src/MainDeCarte.h src/Joueur.h src/Jeu.h #src/winTxt.h src/jeuTxt.h
	doxygen doc/whitejack.doxy