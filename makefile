CC := g++ -g -Wall
SFML := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
SFML_OBJ := -I/usr/local/include/SFML


all :  bin/Deck bin/MainDeCartes bin/Carte bin/Joueur bin/JeuSoloTxt bin/JeuSolo bin/JeuSoloSfml bin/JeuMulti bin/MenuSfml bin/JeuMultiSfml bin/Appli


bin/Appli : obj/mainApplication.o obj/Application.o obj/MenuSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/JeuMultiSfml.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o 
	$(CC) obj/mainApplication.o obj/Application.o obj/MenuSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/JeuMultiSfml.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/Appli $(SFML)

obj/mainApplication.o : src/mainApplication.cpp src/Application.h src/MenuSfml.h src/JeuSoloSfml.h src/JeuSolo.h src/JeuMultiSfml.h src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	$(CC) -c src/mainApplication.cpp -o obj/mainApplication.o $(SFML_OBJ)

obj/Application.o : src/Application.cpp src/Application.h src/MenuSfml.h src/JeuSoloSfml.h src/JeuSolo.h src/JeuMultiSfml.h src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	$(CC) -c src/Application.cpp -o obj/Application.o $(SFML_OBJ)



bin/JeuMultiSfml : obj/mainJeuMultiSfml.o obj/JeuMultiSfml.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o 
	$(CC) obj/mainJeuMultiSfml.o obj/JeuMultiSfml.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuMultiSfml $(SFML)

obj/mainJeuMultiSfml.o : src/mainJeuMultiSfml.cpp src/JeuMultiSfml.h src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	$(CC) -c src/mainJeuMultiSfml.cpp -o obj/mainJeuMultiSfml.o $(SFML_OBJ)

obj/JeuMultiSfml.o : src/JeuMultiSfml.h src/JeuMultiSfml.cpp src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	$(CC) -c src/JeuMultiSfml.cpp -o obj/JeuMultiSfml.o $(SFML_OBJ)



bin/JeuSoloSfml : obj/mainJeuSoloSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o 
	$(CC) obj/mainJeuSoloSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuSoloSfml $(SFML) 

obj/mainJeuSoloSfml.o : src/mainJeuSoloSfml.cpp src/JeuSoloSfml.h src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	$(CC) -c src/mainJeuSoloSfml.cpp -o obj/mainJeuSoloSfml.o $(SFML_OBJ)

obj/JeuSoloSfml.o : src/JeuSoloSfml.h src/JeuSoloSfml.cpp src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	$(CC) -c src/JeuSoloSfml.cpp -o obj/JeuSoloSfml.o $(SFML_OBJ)



bin/MenuSfml : obj/mainMenuSfml.o obj/MenuSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o 
	$(CC) obj/mainMenuSfml.o obj/MenuSfml.o obj/JeuSoloSfml.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/MenuSfml $(SFML)

obj/mainMenuSfml.o : src/mainMenuSfml.cpp src/MenuSfml.h src/JeuSoloSfml.h src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	$(CC) -c src/mainMenuSfml.cpp -o obj/mainMenuSfml.o $(SFML_OBJ)

obj/MenuSfml.o : src/MenuSfml.h src/MenuSfml.cpp src/JeuSoloSfml.h src/JeuSoloSfml.cpp src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h 
	$(CC) -c src/MenuSfml.cpp -o obj/MenuSfml.o $(SFML_OBJ)



bin/JeuSoloTxt : obj/mainJeuSoloTxt.o obj/JeuSoloTxt.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o obj/WinTxt.o
	$(CC) obj/mainJeuSoloTxt.o obj/JeuSoloTxt.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o obj/WinTxt.o -o bin/JeuSoloTxt

obj/mainJeuSoloTxt.o : src/mainJeuSoloTxt.cpp src/JeuSoloTxt.h src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h src/WinTxt.h
	$(CC) -c src/mainJeuSoloTxt.cpp -o obj/mainJeuSoloTxt.o

obj/JeuSoloTxt.o : src/JeuSoloTxt.h src/JeuSoloTxt.cpp src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h src/WinTxt.h
	$(CC) -c src/JeuSoloTxt.cpp -o obj/JeuSoloTxt.o



obj/WinTxt.o : src/WinTxt.cpp src/WinTxt.h
	$(CC) -c src/WinTxt.cpp -o obj/WinTxt.o



bin/JeuSolo : obj/mainTestJeuSolo.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o
	$(CC) obj/mainTestJeuSolo.o obj/JeuSolo.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuSolo

obj/mainTestJeuSolo.o : src/mainTestJeuSolo.cpp src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h
	$(CC) -c src/mainTestJeuSolo.cpp -o obj/mainTestJeuSolo.o

obj/JeuSolo.o : src/JeuSolo.cpp src/JeuSolo.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h
	$(CC) -c src/JeuSolo.cpp -o obj/JeuSolo.o



bin/JeuMulti : obj/mainTestJeuMulti.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o 
	$(CC) obj/mainTestJeuMulti.o obj/JeuMulti.o obj/Joueur.o obj/Carte.o obj/Deck.o obj/MainDeCartes.o -o bin/JeuMulti

obj/mainTestJeuMulti.o : src/mainTestJeuMulti.cpp src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h
	$(CC) -c src/mainTestJeuMulti.cpp -o obj/mainTestJeuMulti.o

obj/JeuMulti.o: src/JeuMulti.cpp src/JeuMulti.h src/Joueur.h src/Carte.h src/Deck.h src/MainDeCartes.h
	$(CC) -c src/JeuMulti.cpp -o obj/JeuMulti.o



bin/Joueur : obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCartes.o obj/Carte.o
	$(CC) obj/mainTestJoueur.o obj/Joueur.o obj/MainDeCartes.o obj/Carte.o -o bin/Joueur

obj/mainTestJoueur.o : src/mainTestJoueur.cpp src/Joueur.h src/MainDeCartes.h src/Carte.h
	$(CC) -c src/mainTestJoueur.cpp -o obj/mainTestJoueur.o

obj/Joueur.o : src/Joueur.h src/Joueur.cpp src/MainDeCartes.h src/Carte.h
	$(CC) -c src/Joueur.cpp -o obj/Joueur.o



bin/Deck : obj/mainTestDeck.o obj/Deck.o obj/Carte.o
	$(CC) obj/mainTestDeck.o obj/Deck.o obj/Carte.o -o bin/Deck 

obj/mainTestDeck.o : src/mainTestDeck.cpp src/Deck.h src/Carte.h
	$(CC) -c src/mainTestDeck.cpp -o obj/mainTestDeck.o 

obj/Deck.o : src/Deck.h src/Deck.cpp src/Carte.h 
	$(CC) -c src/Deck.cpp -o obj/Deck.o 



bin/MainDeCartes : obj/mainTestMainDeCartes.o obj/MainDeCartes.o obj/Carte.o
	$(CC) obj/mainTestMainDeCartes.o obj/MainDeCartes.o obj/Carte.o -o bin/MainDeCartes

obj/mainTestMainDeCartes.o : src/mainTestMainDeCartes.cpp src/MainDeCartes.h src/Carte.h
	$(CC) -c src/mainTestMainDeCartes.cpp -o obj/mainTestMainDeCartes.o

obj/MainDeCartes.o : src/MainDeCartes.cpp src/MainDeCartes.h src/Carte.h 
	$(CC) -c src/MainDeCartes.cpp -o obj/MainDeCartes.o



bin/Carte : obj/mainTestCarte.o obj/Carte.o 
	$(CC) obj/mainTestCarte.o obj/Carte.o -o bin/Carte 

obj/mainTestCarte.o : src/mainTestCarte.cpp src/Carte.h
	$(CC) -c src/mainTestCarte.cpp -o obj/mainTestCarte.o 

obj/Carte.o : src/Carte.cpp src/Carte.h
	$(CC) -c src/Carte.cpp -o obj/Carte.o



clean : 
	rm -f obj/*
	rm -f bin/*



doc : src/Carte.h src/Deck.h src/MainDeCartes.h src/Joueur.h src/JeuSolo.h src/MenuSfml.h src/JeuSoloSfml.h src/JeuMulti.h src/JeuMultiSfml.h src/Application.h
	doxygen doc/whitejack.doxy