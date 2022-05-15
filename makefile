all :  bin/Deck bin/MainDeCartes bin/Carte bin/Joueur bin/JeuSoloTxt bin/JeuSolo bin/JeuSoloSfml bin/JeuMulti bin/MenuSfml bin/JeuMultiSfml bin/Appli


bin/Appli : obj/mainApplication.o obj/Application.o obj/MenuSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/JeuMultiSfml.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o 
	g++ -g -Wall obj/mainApplication.o obj/Application.o obj/MenuSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/JeuMultiSfml.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/Appli -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

obj/mainApplication.o : src/mainApplication.cpp src/Application.h src/MenuSfml.h src/JeuSoloSfml.h src/JeuSolo.h src/JeuMultiSfml.h src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	g++ -g -Wall -c src/mainApplication.cpp -o obj/mainApplication.o -I/usr/local/include/SFML

obj/Application.o : src/Application.cpp src/Application.h src/MenuSfml.h src/JeuSoloSfml.h src/JeuSolo.h src/JeuMultiSfml.h src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	g++ -g -Wall -c src/Application.cpp -o obj/Application.o -I/usr/local/include/SFML



bin/JeuMultiSfml : obj/mainJeuMultiSfml.o obj/JeuMultiSfml.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o 
	g++ -g -Wall obj/mainJeuMultiSfml.o obj/JeuMultiSfml.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuMultiSfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

obj/mainJeuMultiSfml.o : src/mainJeuMultiSfml.cpp src/JeuMultiSfml.h src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	g++ -g -Wall -c src/mainJeuMultiSfml.cpp -o obj/mainJeuMultiSfml.o -I/usr/local/include/SFML

obj/JeuMultiSfml.o : src/JeuMultiSfml.h src/JeuMultiSfml.cpp src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	g++ -g -Wall -c src/JeuMultiSfml.cpp -o obj/JeuMultiSfml.o -I/usr/local/include/SFML



bin/JeuSoloSfml : obj/mainJeuSoloSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o 
	g++ -g -Wall obj/mainJeuSoloSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuSoloSfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

obj/mainJeuSoloSfml.o : src/mainJeuSoloSfml.cpp src/JeuSoloSfml.h src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	g++ -g -Wall -c src/mainJeuSoloSfml.cpp -o obj/mainJeuSoloSfml.o -I/usr/local/include/SFML

obj/JeuSoloSfml.o : src/JeuSoloSfml.h src/JeuSoloSfml.cpp src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	g++ -g -Wall -c src/JeuSoloSfml.cpp -o obj/JeuSoloSfml.o -I/usr/local/include/SFML



bin/MenuSfml : obj/mainMenuSfml.o obj/MenuSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o 
	g++ -g -Wall obj/mainMenuSfml.o obj/MenuSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/MenuSfml -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

obj/mainMenuSfml.o : src/mainMenuSfml.cpp src/MenuSfml.h src/JeuSoloSfml.h src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	g++ -g -Wall -c src/mainMenuSfml.cpp -o obj/mainMenuSfml.o -I/usr/local/include/SFML

obj/MenuSfml.o : src/MenuSfml.h src/MenuSfml.cpp src/JeuSoloSfml.h src/JeuSoloSfml.cpp src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	g++ -g -Wall -c src/MenuSfml.cpp -o obj/MenuSfml.o -I/usr/local/include/SFML



bin/JeuSoloTxt : obj/mainJeuSoloTxt.o obj/JeuSoloTxt.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o obj/WinTxt.o
	g++ -g -Wall obj/mainJeuSoloTxt.o obj/JeuSoloTxt.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o obj/WinTxt.o -o bin/JeuSoloTxt

obj/mainJeuSoloTxt.o : src/mainJeuSoloTxt.cpp src/JeuSoloTxt.h src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h src/WinTxt.h
	g++ -g -Wall -c src/mainJeuSoloTxt.cpp -o obj/mainJeuSoloTxt.o

obj/JeuSoloTxt.o : src/JeuSoloTxt.h src/JeuSoloTxt.cpp src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h src/WinTxt.h
	g++ -g -Wall -c src/JeuSoloTxt.cpp -o obj/JeuSoloTxt.o



obj/WinTxt.o : src/WinTxt.cpp src/WinTxt.h
	g++ -g -Wall -c src/WinTxt.cpp -o obj/WinTxt.o



bin/JeuSolo : obj/mainTestJeuSolo.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o
	g++ -g -Wall obj/mainTestJeuSolo.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuSolo

obj/mainTestJeuSolo.o : src/mainTestJeuSolo.cpp src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h
	g++ -g -Wall -c src/mainTestJeuSolo.cpp -o obj/mainTestJeuSolo.o

obj/JeuSolo.o : src/JeuSolo.cpp src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h
	g++ -g -Wall -c src/JeuSolo.cpp -o obj/JeuSolo.o



bin/JeuMulti : obj/mainTestJeuMulti.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o 
	g++ -g -Wall obj/mainTestJeuMulti.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuMulti

obj/mainTestJeuMulti.o : src/mainTestJeuMulti.cpp src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h
	g++ -g -Wall -c src/mainTestJeuMulti.cpp -o obj/mainTestJeuMulti.o

obj/JeuMulti.o: src/JeuMulti.cpp src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h
	g++ -g -Wall -c src/JeuMulti.cpp -o obj/JeuMulti.o



bin/Joueur : obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCartes.o obj/Carte.o
	g++ -g -Wall obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCartes.o obj/Carte.o -o bin/Joueur

obj/mainTestJoueur.o : src/mainTestJoueur.cpp src/Joueur.h src/MainDeCartes.h src/Carte.h
	g++ -g -Wall -c src/mainTestJoueur.cpp -o obj/mainTestJoueur.o

obj/Joueur.o : src/Joueur.h src/Joueur.cpp src/MainDeCartes.h src/Carte.h
	g++ -g -Wall -c src/Joueur.cpp -o obj/Joueur.o



bin/Deck : obj/mainTestDeck.o obj/Deck.o obj/Carte.o
	g++ -g -Wall obj/mainTestDeck.o obj/Deck.o obj/Carte.o -o bin/Deck 

obj/mainTestDeck.o : src/mainTestDeck.cpp src/Deck.h src/Carte.h
	g++ -g -Wall -c src/mainTestDeck.cpp -o obj/mainTestDeck.o 

obj/Deck.o : src/Deck.h src/Deck.cpp src/Carte.h 
	g++ -g -Wall -c src/Deck.cpp -o obj/Deck.o 



bin/MainDeCartes : obj/mainTestMainDeCartes.o obj/MainDeCartes.o obj/Carte.o
	g++ -g -Wall obj/mainTestMainDeCartes.o obj/MainDeCartes.o obj/Carte.o -o bin/MainDeCartes

obj/mainTestMainDeCartes.o : src/mainTestMainDeCartes.cpp src/MainDeCartes.h src/Carte.h
	g++ -g -Wall -c src/mainTestMainDeCartes.cpp -o obj/mainTestMainDeCartes.o

obj/MainDeCartes.o : src/MainDeCartes.cpp src/MainDeCartes.h src/Carte.h 
	g++ -g -Wall -c src/MainDeCartes.cpp -o obj/MainDeCartes.o



bin/Carte : obj/mainTestCarte.o obj/Carte.o 
	g++ -g -Wall obj/mainTestCarte.o obj/Carte.o -o bin/Carte 

obj/mainTestCarte.o : src/mainTestCarte.cpp src/Carte.h
	g++ -g -Wall -c src/mainTestCarte.cpp -o obj/mainTestCarte.o 

obj/Carte.o : src/Carte.cpp src/Carte.h
	g++ -g -Wall -c src/Carte.cpp -o obj/Carte.o



clean : 
	rm -f obj/*
	rm -f bin/*



doc : src/Carte.h src/Deck.h src/MainDeCartes.h src/Joueur.h src/JeuSolo.h src/WinTxt.h src/JeuSoloTxt.h src/MenuSfml.h src/JeuSoloSfml.h src/JeuMulti.h src/JeuMultiSfml.h src/Application.h
	doxygen doc/whitejack.doxy