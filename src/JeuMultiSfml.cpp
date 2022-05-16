#include "JeuMultiSfml.h"
#include <cassert>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include<sstream> 

using namespace sf;
using namespace std;

JeuMultiSfml::JeuMultiSfml () : jeu(1) { 

    window = new RenderWindow(VideoMode(1400,750), "BlackJack");
    dimx = window->getSize().x;
    dimy = window->getSize().y;
    actionMiser=0;
    finManche=0;
    top1 = 0;
    choixNiv=0;
    elimine=0;
}

void JeuMultiSfml::sfmlInit() {

//Chargement images coeur 

    if (!t1deCoeur.loadFromFile("data/1_Coeur.png")) 
    {
        cout << "Error data/1_Coeur.png non found" << endl;
    }
    else 
    {
        s1deCoeur.setTexture(t1deCoeur);
    }
    
    if (!t2deCoeur.loadFromFile("data/2_Coeur.png")) 
    {
        cout << "Error data/2_Coeur.png non found" << endl;
    }
    else 
    {
        s2deCoeur.setTexture(t2deCoeur);
    }
    
    if (!t3deCoeur.loadFromFile("data/3_Coeur.png")) 
    {
        cout << "Error data/3_Coeur.png non found" << endl;
    }
    else 
    {
        s3deCoeur.setTexture(t3deCoeur);
    }
    
    if (!t4deCoeur.loadFromFile("data/4_Coeur.png")) 
    {
        cout << "Error data/4_Coeur.png non found" << endl;
    }
    else 
    {
        s4deCoeur.setTexture(t4deCoeur);
    }
    
    if (!t5deCoeur.loadFromFile("data/5_Coeur.png")) 
    {
        cout << "Error data/5_Coeur.png non found" << endl;
    }
    else 
    {
        s5deCoeur.setTexture(t5deCoeur);
    }
    
    if (!t6deCoeur.loadFromFile("data/6_Coeur.png")) 
    {
        cout << "Error data/6_Coeur.png non found" << endl;
    }
    else 
    {
        s6deCoeur.setTexture(t6deCoeur);
    }
    
    if (!t7deCoeur.loadFromFile("data/7_Coeur.png")) 
    {
        cout << "Error data/7_Coeur.png non found" << endl;
    }
    else 
    {
        s7deCoeur.setTexture(t7deCoeur);
    }
    
    if (!t8deCoeur.loadFromFile("data/8_Coeur.png")) 
    {
        cout << "Error data/8_Coeur.png non found" << endl;
    }
    else 
    {
        s8deCoeur.setTexture(t8deCoeur);
    }
    
    if (!t9deCoeur.loadFromFile("data/9_Coeur.png")) 
    {
        cout << "Error data/9_Coeur.png non found" << endl;
    }
    else 
    {
        s9deCoeur.setTexture(t9deCoeur);
    }
    
    if (!t10deCoeur.loadFromFile("data/10_Coeur.png")) 
    {
        cout << "Error data/10_Coeur.png non found" << endl;
    }
    else 
    {
        s10deCoeur.setTexture(t10deCoeur);
    }
    
    if (!t11deCoeur.loadFromFile("data/11_Coeur.png")) 
    {
        cout << "Error data/11_Coeur.png non found" << endl;
    }
    else 
    {
        s11deCoeur.setTexture(t11deCoeur);
    }
    
    if (!t12deCoeur.loadFromFile("data/12_Coeur.png")) 
    {
        cout << "Error data/12_Coeur.png non found" << endl;
    }
    else 
    {
        s12deCoeur.setTexture(t12deCoeur);
    }
    
    if (!t13deCoeur.loadFromFile("data/13_Coeur.png")) 
    {
        cout << "Error data/13_Coeur.png non found" << endl;
    }
    else 
    {
        s13deCoeur.setTexture(t13deCoeur);
    }




//Chargement images carreau

    if (!t1deCarreau.loadFromFile("data/1_Carreau.png")) 
    {
        cout << "Error data/1_Carreau.png non found" << endl;
    }
    else 
    {
        s1deCarreau.setTexture(t1deCarreau);
    }
    
    if (!t2deCarreau.loadFromFile("data/2_Carreau.png")) 
    {
        cout << "Error data/2_Carreau.png non found" << endl;
    }
    else 
    {
        s2deCarreau.setTexture(t2deCarreau);
    }
    
    if (!t3deCarreau.loadFromFile("data/3_Carreau.png")) 
    {
        cout << "Error data/3_Carreau.png non found" << endl;
    }
    else 
    {
        s3deCarreau.setTexture(t3deCarreau);
    }
    
    if (!t4deCarreau.loadFromFile("data/4_Carreau.png")) 
    {
        cout << "Error data/4_Carreau.png non found" << endl;
    }
    else 
    {
        s4deCarreau.setTexture(t4deCarreau);
    }
    
    if (!t5deCarreau.loadFromFile("data/5_Carreau.png")) 
    {
        cout << "Error data/5_Carreau.png non found" << endl;
    }
    else 
    {
        s5deCarreau.setTexture(t5deCarreau);
    }
    
    if (!t6deCarreau.loadFromFile("data/6_Carreau.png")) 
    {
        cout << "Error data/6_Carreau.png non found" << endl;
    }
    else 
    {
        s6deCarreau.setTexture(t6deCarreau);
    }
    
    if (!t7deCarreau.loadFromFile("data/7_Carreau.png")) 
    {
        cout << "Error data/7_Carreau.png non found" << endl;
    }
    else 
    {
        s7deCarreau.setTexture(t7deCarreau);
    }
    
    if (!t8deCarreau.loadFromFile("data/8_Carreau.png")) 
    {
        cout << "Error data/8_Carreau.png non found" << endl;
    }
    else 
    {
        s8deCarreau.setTexture(t8deCarreau);
    }
    
    if (!t9deCarreau.loadFromFile("data/9_Carreau.png")) 
    {
        cout << "Error data/9_Carreau.png non found" << endl;
    }
    else 
    {
        s9deCarreau.setTexture(t9deCarreau);
    }
    
    if (!t10deCarreau.loadFromFile("data/10_Carreau.png")) 
    {
        cout << "Error data/10_Carreau.png non found" << endl;
    }
    else 
    {
        s10deCarreau.setTexture(t10deCarreau);
    }
    
    if (!t11deCarreau.loadFromFile("data/11_Carreau.png")) 
    {
        cout << "Error data/11_Carreau.png non found" << endl;
    }
    else 
    {
        s11deCarreau.setTexture(t11deCarreau);
    }
    
    if (!t12deCarreau.loadFromFile("data/12_Carreau.png")) 
    {
        cout << "Error data/12_Carreau.png non found" << endl;
    }
    else 
    {
        s12deCarreau.setTexture(t12deCarreau);
    }
    
    if (!t13deCarreau.loadFromFile("data/13_Carreau.png")) 
    {
        cout << "Error data/13_Carreau.png non found" << endl;
    }
    else 
    {
        s13deCarreau.setTexture(t13deCarreau);
    }
  


  //Chargement images Piques

    if (!t1dePiques.loadFromFile("data/1_Piques.png")) 
    {
        cout << "Error data/1_Piques.png non found" << endl;
    }
    else 
    {
        s1dePiques.setTexture(t1dePiques);
    }
    
    if (!t2dePiques.loadFromFile("data/2_Piques.png")) 
    {
        cout << "Error data/2_Piques.png non found" << endl;
    }
    else 
    {
        s2dePiques.setTexture(t2dePiques);
    }
    
    if (!t3dePiques.loadFromFile("data/3_Piques.png")) 
    {
        cout << "Error data/3_Piques.png non found" << endl;
    }
    else 
    {
        s3dePiques.setTexture(t3dePiques);
    }
    
    if (!t4dePiques.loadFromFile("data/4_Piques.png")) 
    {
        cout << "Error data/4_Piques.png non found" << endl;
    }
    else 
    {
        s4dePiques.setTexture(t4dePiques);
    }
    
    if (!t5dePiques.loadFromFile("data/5_Piques.png")) 
    {
        cout << "Error data/5_Piques.png non found" << endl;
    }
    else 
    {
        s5dePiques.setTexture(t5dePiques);
    }
    
    if (!t6dePiques.loadFromFile("data/6_Piques.png")) 
    {
        cout << "Error data/6_Piques.png non found" << endl;
    }
    else 
    {
        s6dePiques.setTexture(t6dePiques);
    }
    
    if (!t7dePiques.loadFromFile("data/7_Piques.png")) 
    {
        cout << "Error data/7_Piques.png non found" << endl;
    }
    else 
    {
        s7dePiques.setTexture(t7dePiques);
    }
    
    if (!t8dePiques.loadFromFile("data/8_Piques.png")) 
    {
        cout << "Error data/8_Piques.png non found" << endl;
    }
    else 
    {
        s8dePiques.setTexture(t8dePiques);
    }
    
    if (!t9dePiques.loadFromFile("data/9_Piques.png")) 
    {
        cout << "Error data/9_Piques.png non found" << endl;
    }
    else 
    {
        s9dePiques.setTexture(t9dePiques);
    }
    
    if (!t10dePiques.loadFromFile("data/10_Piques.png")) 
    {
        cout << "Error data/10_Piques.png non found" << endl;
    }
    else 
    {
        s10dePiques.setTexture(t10dePiques);
    }
    
    if (!t11dePiques.loadFromFile("data/11_Piques.png")) 
    {
        cout << "Error data/11_Piques.png non found" << endl;
    }
    else 
    {
        s11dePiques.setTexture(t11dePiques);
    }
    
    if (!t12dePiques.loadFromFile("data/12_Piques.png")) 
    {
        cout << "Error data/12_Piques.png non found" << endl;
    }
    else 
    {
        s12dePiques.setTexture(t12dePiques);
    }
    
    if (!t13dePiques.loadFromFile("data/13_Piques.png")) 
    {
        cout << "Error data/13_Piques.png non found" << endl;
    }
    else 
    {
        s13dePiques.setTexture(t13dePiques);
    } 


    //Chargement images Trefles

    if (!t1deTrefles.loadFromFile("data/1_Trèfles.png")) 
    {
        cout << "Error data/1_Trèfles.png non found" << endl;
    }
    else 
    {
        s1deTrefles.setTexture(t1deTrefles);
    }
    
    if (!t2deTrefles.loadFromFile("data/2_Trèfles.png")) 
    {
        cout << "Error data/2_Trèfles.png non found" << endl;
    }
    else 
    {
        s2deTrefles.setTexture(t2deTrefles);
    }
    
    if (!t3deTrefles.loadFromFile("data/3_Trèfles.png")) 
    {
        cout << "Error data/3_Trèfles.png non found" << endl;
    }
    else 
    {
        s3deTrefles.setTexture(t3deTrefles);
    }
    
    if (!t4deTrefles.loadFromFile("data/4_Trèfles.png")) 
    {
        cout << "Error data/4_Trèfles.png non found" << endl;
    }
    else 
    {
        s4deTrefles.setTexture(t4deTrefles);
    }
    
    if (!t5deTrefles.loadFromFile("data/5_Trèfles.png")) 
    {
        cout << "Error data/5_Trèfles.png non found" << endl;
    }
    else 
    {
        s5deTrefles.setTexture(t5deTrefles);
    }
    
    if (!t6deTrefles.loadFromFile("data/6_Trèfles.png")) 
    {
        cout << "Error data/6_Trèfles.png non found" << endl;
    }
    else 
    {
        s6deTrefles.setTexture(t6deTrefles);
    }
    
    if (!t7deTrefles.loadFromFile("data/7_Trèfles.png")) 
    {
        cout << "Error data/7_Trèfles.png non found" << endl;
    }
    else 
    {
        s7deTrefles.setTexture(t7deTrefles);
    }
    
    if (!t8deTrefles.loadFromFile("data/8_Trèfles.png")) 
    {
        cout << "Error data/8_Trèfles.png non found" << endl;
    }
    else 
    {
        s8deTrefles.setTexture(t8deTrefles);
    }
    
    if (!t9deTrefles.loadFromFile("data/9_Trèfles.png")) 
    {
        cout << "Error data/9_Trèfles.png non found" << endl;
    }
    else 
    {
        s9deTrefles.setTexture(t9deTrefles);
    }
    
    if (!t10deTrefles.loadFromFile("data/10_Trèfles.png")) 
    {
        cout << "Error data/10_Trèfles.png non found" << endl;
    }
    else 
    {
        s10deTrefles.setTexture(t10deTrefles);
    }
    
    if (!t11deTrefles.loadFromFile("data/11_Trèfles.png")) 
    {
        cout << "Error data/11_Trèfles.png non found" << endl;
    }
    else 
    {
        s11deTrefles.setTexture(t11deTrefles);
    }
    
    if (!t12deTrefles.loadFromFile("data/12_Trèfles.png")) 
    {
        cout << "Error data/12_Trèfles.png non found" << endl;
    }
    else 
    {
        s12deTrefles.setTexture(t12deTrefles);
    }
    
    if (!t13deTrefles.loadFromFile("data/13_Trèfles.png")) 
    {
        cout << "Error data/13_Trèfles.png non found" << endl;
    }
    else 
    {
        s13deTrefles.setTexture(t13deTrefles);
    } 


//Chargement des autres images nécessaires

    if (!tFond.loadFromFile("data/fond.png")) 
    {
        cout << "Error data/fond.png non found" << endl;
    }
    else 
    {
        rsFond.setTexture(&tFond);
        rsFond.setSize(Vector2f(dimx,dimy));
    }

    if (!t1.loadFromFile("data/1.png")) 
    {
        cout << "Error data/1.png non found" << endl;
    }
    else 
    {
        s1.setTexture(t1);
        s1.setScale(0.75,0.75);
    }

    if (!t10.loadFromFile("data/10.png")) 
    {
        cout << "Error data/10.png non found" << endl;
    }
    else 
    {
        s10.setTexture(t10);
        s10.setScale(0.75,0.75);
    }

    if (!t100.loadFromFile("data/100.png")) 
    {
        cout << "Error data/100.png non found" << endl;
    }
    else 
    {
        s100.setTexture(t100);
        s100.setScale(0.75,0.75);
    }

    if (!t250.loadFromFile("data/250.png")) 
    {
        cout << "Error data/250.png non found" << endl;
    }
    else 
    {
        s250.setTexture(t250);
        s250.setScale(0.75,0.75);
    }

    if (!t500.loadFromFile("data/500.png")) 
    {
        cout << "Error data/500.png non found" << endl;
    }
    else 
    {
        s500.setTexture(t500);
        s500.setScale(0.75,0.75);
    }

    if (!tDoubler.loadFromFile("data/doubler.png")) 
    {
        cout << "Error data/doubler.png non found" << endl;
    }
    else 
    {
        sDoubler.setTexture(tDoubler);
        sDoubler.setScale(0.75,0.75);
    }

    if (!tRester.loadFromFile("data/rester.png")) 
    {
        cout << "Error data/rester.png non found" << endl;
    }
    else 
    {
        sRester.setTexture(tRester);
        sRester.setScale(0.75,0.75);
    }

    if (!tTirer.loadFromFile("data/tirer.png")) 
    {
        cout << "Error data/tirer.png non found" << endl;
    }
    else 
    {
        sTirer.setTexture(tTirer);
        sTirer.setScale(0.75,0.75);
    }

    if (!tChanger.loadFromFile("data/changer.png")) 
    {
        cout << "Error data/changer.png non found" << endl;
    }
    else 
    {
        sChanger.setTexture(tChanger);
        sChanger.setScale(0.75,0.75);
    }

    if (!tExit.loadFromFile("data/exit.png")) 
    {
        cout << "Error data/exit.png non found" << endl;
    }
    else 
    {
        sExit.setTexture(tExit);
        sf::Color color = sExit.getColor();
        color.a=200;
        sExit.setPosition((dimx/64),30);
        sExit.setColor(color);
        sExit.setScale(0.4,0.4);
    }

    if (!tBlackjack.loadFromFile("data/BlackJack.png")) 
    {
        cout << "Error data/BlackJack.png non found" << endl;
    }
    else 
    {
        sBlackjack.setTexture(tBlackjack);
        sBlackjack.setScale(0.6,0.6);
        sBlackjack.setPosition(dimx/2-70, dimy/2+165);
    }
    if (!tGagne.loadFromFile("data/Gagne.png")) 
    {
        cout << "Error data/Gagne.png non found" << endl;
    }
    else 
    {
        sGagne.setTexture(tGagne);
        sGagne.setScale(0.6,0.6);
        sGagne.setPosition(dimx/2-50, dimy/2+165);
    }
    if (!tPerdu.loadFromFile("data/Perdu.png")) 
    {
        cout << "Error data/Perdu.png non found" << endl;
    }
    else 
    {
        sPerdu.setTexture(tPerdu);
        sPerdu.setScale(0.6,0.6);
        sPerdu.setPosition(dimx/2-50, dimy/2+165);
    }
    if (!tEgalite.loadFromFile("data/Egalite.png")) 
    {
        cout << "Error data/Egalite.png non found" << endl;
    }
    else 
    {
        sEgalite.setTexture(tEgalite);
        sEgalite.setScale(0.6,0.6);
        sEgalite.setPosition(dimx/2-55, dimy/2+165);
    }
    if (!tAmateur.loadFromFile("data/amateur.png")) 
    {
        cout << "Error data/Amateur.png non found" << endl;
    }
    else 
    {
        sAmateur.setTexture(tAmateur);
        sAmateur.setPosition(dimx/2-400,dimy/2-100);
    }
    if (!tIntermediaire.loadFromFile("data/intermédiaire.png")) 
    {
        cout << "Error data/intermédiaire.png non found" << endl;
    }
    else 
    {
        sIntermediaire.setTexture(tIntermediaire);
        sIntermediaire.setPosition(dimx/2-100,dimy/2-100);
    }
    if (!tExpert.loadFromFile("data/expert.png")) 
    {
        cout << "Error data/expert.png non found" << endl;
    }
    else 
    {
        sExpert.setTexture(tExpert);
        sExpert.setPosition(dimx/2+200,dimy/2-100);
    }
    if (!tBigWin.loadFromFile("data/bigWin.png")) 
    {
        cout << "Error data/bigWin.png non found" << endl;
    }
    else 
    {
        sBigWin.setTexture(tBigWin);
        sBigWin.setScale(1.3,1.3);
        sBigWin.setPosition(dimx/2-310,dimy/2-350);
    }
    if (!tElimine.loadFromFile("data/Elimination.png")) 
    {
        cout << "Error data/Elimination.png non found" << endl;
    }
    else 
    {
        sElimine.setTexture(tElimine);
        sElimine.setPosition(80,dimy/2-100);
    }

    if (!m1_font.loadFromFile("data/FontMoney.ttf")) 
    {
        cout << "Error data/FontMoney.ttf non found" << endl;
    }
    else 
    {
        txtBudget.setFont(m1_font);
        txtBudget1.setFont(m1_font);
        txtBudget2.setFont(m1_font);
        txtBudget3.setFont(m1_font);
        
        txtBudget.setCharacterSize(35);
        txtBudget1.setCharacterSize(35);
        txtBudget2.setCharacterSize(35);
        txtBudget3.setCharacterSize(35);
        
        txtBudget.setFillColor(Color::Yellow);
        txtBudget1.setFillColor(Color::Yellow);
        txtBudget2.setFillColor(Color::Yellow);
        txtBudget3.setFillColor(Color::Yellow);

        txtBudget.setPosition(dimx/2-40,dimy/2+75);
        txtBudget1.setPosition(70,dimy/2-50);
        txtBudget2.setPosition(dimx/4,dimy/2+50);
        txtBudget3.setPosition(3*dimx/4-65,dimy/2+50);
    }

    if (!m2_font.loadFromFile("data/BLACR___.TTF")) 
    {
        cout << "Error data/BLACR___.TTF non found" << endl;
    }
    else 
    {
        txtScoreJoueur.setFont(m2_font);
        txtScore1.setFont(m2_font);
        txtScore2.setFont(m2_font);
        txtScore3.setFont(m2_font);
        txtScoreCroupier.setFont(m2_font);
        txtNom.setFont(m2_font);
        txtNom1.setFont(m2_font);
        txtNom2.setFont(m2_font);
        txtNom3.setFont(m2_font);
        txtManche.setFont(m2_font);
        
        txtScoreJoueur.setCharacterSize(30);
        txtScore1.setCharacterSize(30);
        txtScore2.setCharacterSize(30);
        txtScore3.setCharacterSize(30);
        txtScoreCroupier.setCharacterSize(30);
        txtNom.setCharacterSize(30);
        txtNom1.setCharacterSize(30);
        txtNom2.setCharacterSize(30);
        txtNom3.setCharacterSize(30);
        txtManche.setCharacterSize(30);
        
        txtScoreJoueur.setFillColor(Color::Black);
        txtScore1.setFillColor(Color::Black);
        txtScore2.setFillColor(Color::Black);
        txtScore3.setFillColor(Color::Black);
        txtScoreCroupier.setFillColor(Color::Black);
        txtNom.setFillColor(Color::Black);
        txtNom1.setFillColor(Color::Black);
        txtNom2.setFillColor(Color::Black);
        txtNom3.setFillColor(Color::Black);
        txtManche.setFillColor(Color::White);
        
        txtScoreJoueur.setPosition(dimx/2-10,dimy/2+250);
        txtScore1.setPosition(100,dimy/2+125);
        txtScore2.setPosition(dimx/4+30,dimy/2+225);
        txtScore3.setPosition(3*dimx/4-35,dimy/2+225);
        txtScoreCroupier.setPosition(dimx/2-100, dimy/2-250);
        txtNom.setPosition(dimx/2-25,dimy/2+300);
        txtNom1.setPosition(90,dimy/2+175);
        txtNom2.setPosition(dimx/4+15,dimy/2+275);
        txtNom3.setPosition(3*dimx/4-40,dimy/2+275);
        txtManche.setPosition(dimx-200,dimy/2-150);

    }

    if (!m1_soundbuffer.loadFromFile("data/SonMise.wav")) 
    {
        cout << "Error data/SonMise.wav non found" << endl;
    }
    else {
        sonMise.setBuffer(m1_soundbuffer);
    }

    if (!m2_soundbuffer.loadFromFile("data/SonJackpot.wav")) 
    {
        cout << "Error data/SonJackpot.wav non found" << endl;
    }
    else {
        sonJackpot.setBuffer(m2_soundbuffer);
        sonJackpot.setVolume(20);
    }

    if (!m4_soundbuffer.loadFromFile("data/sonGagne.wav")) 
    {
        cout << "Error data/sonGagne.wav non found" << endl;
    }
    else {
        sonGagne.setBuffer(m4_soundbuffer);
    }

    if (!m5_soundbuffer.loadFromFile("data/sonPerdu.wav")) 
    {
        cout << "Error data/sonPerdu.wav non found" << endl;
    }
    else {
        sonPerdu.setBuffer(m5_soundbuffer);
        sonPerdu.setVolume(20);
    }

    if (!m3_soundbuffer.loadFromFile("data/SonCarte.wav")) 
    {
        cout << "Error data/SonCarte.wav non found" << endl;
    }
    else {
        sonCarte.setBuffer(m3_soundbuffer);
    }

}


JeuMultiSfml::~JeuMultiSfml () 
{
    if (window != NULL) delete window;
    window=NULL;
}



void JeuMultiSfml::afficherMainDeCarte(const MainDeCartes& mainJoueur, unsigned int x, unsigned int y)const 
{
    unsigned int positionx = x;
    unsigned int positiony = y;

    for (unsigned int i=0; i<mainJoueur.getNbCartes(); i++)
    {
        Sprite carte;
            if (mainJoueur.getIemeCarte(i).getRang()== 1)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s1dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s1deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s1deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s1deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 2)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s2dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s2deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s2deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s2deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 3)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s3dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s3deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s3deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s3deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 4)
			{
			    if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s4dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s4deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s4deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s4deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 5)
			{
                if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s5dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s5deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s5deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s5deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 6)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s6dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s6deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s6deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s6deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 7)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s7dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s7deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s7deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s7deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 8)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s8dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s8deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s8deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s8deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 9)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s9dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s9deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s9deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s9deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 10)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s10dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s10deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s10deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s10deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 11)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s11dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s11deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s11deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s11deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 12)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s12dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s12deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s12deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s12deCarreau;
				}
			}
			else if (mainJoueur.getIemeCarte(i).getRang() == 13)
			{
				if (mainJoueur.getIemeCarte(i).getSigne() == 1)
				{
					carte = s13dePiques;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 2)
				{
					carte = s13deCoeur;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 3)
				{
					carte = s13deTrefles;
				}
				if (mainJoueur.getIemeCarte(i).getSigne() == 4)
				{
					carte = s13deCarreau;
				}
			}
			carte.setPosition(positionx, positiony);
            carte.setScale(0.5,0.5);
			positionx +=15;
			window->draw(carte);
    }
}


void JeuMultiSfml::initPartie()
{
    jeu.initialisationMiseMulti();
    sonMise.play();
    jeu.initialisationJeuMulti();
    sonCarte.play();
    actionMiser=1;
}


void JeuMultiSfml::finPartie()
{
    assert(!jeu.tabJoueur.empty());
    if(!jeu.tabJoueur[0].mainJoueur.getJoueToujours())
    {
        switch(choixNiv)
        {
            case 1:
                jeu.actionAmateur();
                break;
            case 2:
                jeu.actionIntermediaire();
                break;
            case 3:
                jeu.actionExpert();
                break;
        }
        jeu.actionCroupier();
        sonCarte.play();
        finManche=1;
        for(unsigned int i=1; i<jeu.tabJoueur.size();i++)
        {
            jeu.resultat(i);
        }
        res = jeu.resultat(0);
        switch(res)
        {
            case 0:
                sonPerdu.play(); // si on a perdu on joue le sonPerdu
                break;
            case 1:
                sonMise.play(); // si on a égalité on joue le sonMise
                break;
            case 2:
                sonGagne.play();// si on a gagné on joue le sonGagne
                break;
            case 3:
                sonJackpot.play();// si on a blackjack on joue le sonJackpot
                break;
        }
    }
}


void JeuMultiSfml::affichageManche(unsigned int nbJoueurs)
{
    if (nbJoueurs==4)
    {
        afficherMainDeCarte(jeu.tabJoueur[1].mainJoueur, 70, dimy/2 );
        string scoreIA1 = to_string(jeu.tabJoueur[1].mainJoueur.getSommeValeur());
        txtScore1.setString(scoreIA1);
        stringstream stream2;
        stream2.precision(1);
        stream2 << fixed;
        stream2<<jeu.tabJoueur[1].getBudget();  
        string budgetIA1  = stream2.str();
        txtBudget1.setString(budgetIA1+"$");
        txtNom1.setString(jeu.tabJoueur[1].nom);
        window->draw(txtNom1);
        window->draw(txtScore1);
        window->draw(txtBudget1);

        afficherMainDeCarte(jeu.tabJoueur[2].mainJoueur, dimx/4, dimy/2+100 );
        string scoreIA2 = to_string(jeu.tabJoueur[2].mainJoueur.getSommeValeur());
        txtScore2.setString(scoreIA2);
        stringstream stream3;
        stream3.precision(1);
        stream3 << fixed;
        stream3<<jeu.tabJoueur[2].getBudget();  
        string budgetIA2  = stream3.str();
        txtBudget2.setString(budgetIA2+"$");
        txtNom2.setString(jeu.tabJoueur[2].nom);
        window->draw(txtNom2);
        window->draw(txtScore2);
        window->draw(txtBudget2);

        afficherMainDeCarte(jeu.tabJoueur[0].mainJoueur, dimx/2-40, dimy/2+125 );
        string scoreJoueur = to_string(jeu.tabJoueur[0].mainJoueur.getSommeValeur());
        txtScoreJoueur.setString(scoreJoueur);
        stringstream stream1;
        stream1.precision(1);
        stream1 << fixed;
        stream1<<jeu.tabJoueur[0].getBudget();  
        string budget  = stream1.str();
        txtBudget.setString(budget+"$");
        txtNom.setString(jeu.tabJoueur[0].nom);
        window->draw(txtNom);
        window->draw(txtScoreJoueur);
        window->draw(txtBudget);

        afficherMainDeCarte(jeu.tabJoueur[3].mainJoueur, 3*dimx/4-65, dimy/2+100 );
        string scoreIA3 = to_string(jeu.tabJoueur[3].mainJoueur.getSommeValeur());
        txtScore3.setString(scoreIA3);
        stringstream stream4;
        stream4.precision(1);
        stream4 << fixed;
        stream4<<jeu.tabJoueur[3].getBudget();  
        string budgetIA3  = stream1.str();
        txtBudget3.setString(budgetIA3+"$");
        txtNom3.setString(jeu.tabJoueur[3].nom);
        window->draw(txtNom3);
        window->draw(txtScore3);
        window->draw(txtBudget3);
    }
    else if (nbJoueurs==3)
    {
        afficherMainDeCarte(jeu.tabJoueur[1].mainJoueur, dimx/4, dimy/2+100);
        string scoreIA1 = to_string(jeu.tabJoueur[1].mainJoueur.getSommeValeur());
        txtScore2.setString(scoreIA1);
        stringstream stream2;
        stream2.precision(1);
        stream2 << fixed;
        stream2<<jeu.tabJoueur[1].getBudget();  
        string budgetIA1  = stream2.str();
        txtBudget2.setString(budgetIA1+"$");
        txtNom2.setString(jeu.tabJoueur[1].nom);
        window->draw(txtNom2);
        window->draw(txtScore2);
        window->draw(txtBudget2);

        afficherMainDeCarte(jeu.tabJoueur[0].mainJoueur, dimx/2-40, dimy/2+125 );
        string scoreJoueur = to_string(jeu.tabJoueur[0].mainJoueur.getSommeValeur());
        txtScoreJoueur.setString(scoreJoueur);
        stringstream stream1;
        stream1.precision(1);
        stream1 << fixed;
        stream1<<jeu.tabJoueur[0].getBudget();  
        string budget  = stream1.str();
        txtBudget.setString(budget+"$");
        window->draw(txtNom);
        window->draw(txtScoreJoueur);
        window->draw(txtBudget);

        afficherMainDeCarte(jeu.tabJoueur[2].mainJoueur, 3*dimx/4-65, dimy/2+100 );
        string scoreIA2 = to_string(jeu.tabJoueur[2].mainJoueur.getSommeValeur());
        txtScore3.setString(scoreIA2);
        txtScore3.setPosition(3*dimx/4-35,dimy/2+225);
        stringstream stream3;
        stream3.precision(1);
        stream3 << fixed;
        stream3<<jeu.tabJoueur[2].getBudget();  
        string budgetIA2  = stream3.str();
        txtBudget3.setString(budgetIA2+"$");
        txtNom3.setString(jeu.tabJoueur[2].nom);
        window->draw(txtNom3);
        window->draw(txtScore3);
        window->draw(txtBudget3);
    }
    else if (nbJoueurs==2)
    {
        afficherMainDeCarte(jeu.tabJoueur[1].mainJoueur, dimx/4, dimy/2+100);
        string scoreIA1 = to_string(jeu.tabJoueur[1].mainJoueur.getSommeValeur());
        txtScore2.setString(scoreIA1);
        stringstream stream2;
        stream2.precision(1);
        stream2 << fixed;
        stream2<<jeu.tabJoueur[1].getBudget();  
        string budgetIA1  = stream2.str();
        txtBudget2.setString(budgetIA1+"$");
        txtNom2.setString(jeu.tabJoueur[1].nom);
        window->draw(txtNom2);
        window->draw(txtScore2);
        window->draw(txtBudget2);

        afficherMainDeCarte(jeu.tabJoueur[0].mainJoueur, dimx/2-40, dimy/2+125 );
        string scoreJoueur = to_string(jeu.tabJoueur[0].mainJoueur.getSommeValeur());
        txtScoreJoueur.setString(scoreJoueur);
        stringstream stream1;
        stream1.precision(1);
        stream1 << fixed;
        stream1<<jeu.tabJoueur[0].getBudget();  
        string budget  = stream1.str();
        txtBudget.setString(budget+"$");
        window->draw(txtNom);
        window->draw(txtScoreJoueur);
        window->draw(txtBudget);
    }
}


void JeuMultiSfml::sfmlAff() 
{
    window->clear(Color(230, 240, 255, 255)); 
    window->draw(rsFond);
    window->draw(sExit);

    if(choixNiv==0)
    {
        window->draw(sAmateur);
        window->draw(sIntermediaire);
        window->draw(sExpert);
    }
    else
    {
        if(top1)
        {
            window->draw(sBigWin);
        }
        else if(elimine)
        {
            window->draw(sElimine);
        }
        else
        {
            string nbManche = to_string(jeu.nbManches);
            txtManche.setString("Manche : "+nbManche);
            window->draw(txtManche);

            if(actionMiser==1)
            {

                afficherMainDeCarte(jeu.mainCroupier, dimx/2-50, dimy/2-200);
                string scoreCroupier = to_string(jeu.mainCroupier.getSommeValeur());
                txtScoreCroupier.setString("Croupier : "+scoreCroupier);
                window->draw(txtScoreCroupier);
                affichageManche(jeu.nbJoueurs);

                if(finManche==1)
                {   
                    switch(res)
                    {
                        case 0:
                            window->draw(sPerdu);
                            break;
                        case 1:
                            window->draw(sEgalite);
                            break;
                        case 2:
                            window->draw(sGagne);
                            break;
                        case 3:
                            window->draw(sBlackjack);
                            break;
                    }

                }
                else
                {
                    sRester.setPosition(dimx-100,dimy-80);
                    window->draw(sRester);
                    sTirer.setPosition(dimx-100,dimy-160);
                    window->draw(sTirer);
                    if((jeu.tabJoueur[0].mainJoueur.getNbCartes()==2) && (jeu.tabJoueur[0].getBudget()>=jeu.tabJoueur[0].getMise()))
                    //si le joueur peut doubler (2 cartes et peut doubler sa mise)
                    {
                        sDoubler.setPosition(dimx-100,dimy-240);
                        window->draw(sDoubler);
                        if((jeu.tabJoueur[0].mainJoueur.getIemeCarte(0).getValeur()==jeu.tabJoueur[0].mainJoueur.getIemeCarte(1).getValeur())
                        ||(jeu.tabJoueur[0].mainJoueur.getIemeCarte(0).getRang()==jeu.tabJoueur[0].mainJoueur.getIemeCarte(1).getRang()))
                        {
                            sChanger.setPosition(dimx-100,dimy-320);
                            window->draw(sChanger);
                        }
                    }
                    else    //on déplace le sprite de doubler hors de la fenetre pour s'assurer que le joueur ne puisse doubler
                    {
                        sDoubler.setPosition(dimx+1,dimy+1);
                        sChanger.setPosition(dimx+1,dimy+1);
                        window->draw(sDoubler);
                        window->draw(sChanger);
                    }
                }
            }
            else if(jeu.tabJoueur[0].getBudget()>=500)
            {
                s1.setPosition(dimx/2-205,dimy-90);
                window->draw(s1);

                s10.setPosition(dimx/2-120,dimy-90);
                window->draw(s10);

                s100.setPosition(dimx/2-35,dimy-90);
                window->draw(s100);

                s250.setPosition(dimx/2+50,dimy-90);
                window->draw(s250);

                s500.setPosition(dimx/2+135,dimy-90);
                window->draw(s500);
            }
            else if(jeu.tabJoueur[0].getBudget()>=250)
            {
                s1.setPosition(dimx/2-162.5,dimy-90);
                window->draw(s1);

                s10.setPosition(dimx/2-77.5,dimy-90);
                window->draw(s10);

                s100.setPosition(dimx/2+7.5,dimy-90);
                window->draw(s100);

                s250.setPosition(dimx/2+92.5,dimy-90);
                window->draw(s250);
            }
            else if(jeu.tabJoueur[0].getBudget()>=100)
            {
                s1.setPosition(dimx/2-120,dimy-90);
                window->draw(s1);

                s10.setPosition(dimx/2-35,dimy-90);
                window->draw(s10);

                s100.setPosition(dimx/2+50,dimy-90);
                window->draw(s100);
            }
            else if(jeu.tabJoueur[0].getBudget()>=10)
            {
                s1.setPosition(dimx/2-77.5,dimy-90);
                window->draw(s1);

                s10.setPosition(dimx/2+7.5,dimy-90);
                window->draw(s10);
            }
            else if(jeu.tabJoueur[0].getBudget()>=1)
            {
                s1.setPosition(dimx/2-35,dimy-90);
                window->draw(s1);
            }
        }
    }
    window->display();
}



unsigned int JeuMultiSfml::sfmlBoucle() {

    while (window->isOpen()) 
    {
        Event event;

        while(window->pollEvent(event))
        {
            if (event.type == Event::Closed)   
            {
                window->close();
                delete window;
                window=NULL;
                return 0;
            }
        
            if(event.type == Event::MouseButtonPressed)
            {
                if(event.key.code == Mouse::Left)
                {
                    float x = Mouse::getPosition(*window).x;
                    float y = Mouse::getPosition(*window).y;

                    if(sExit.getGlobalBounds().contains(x,y))
                    {
                        window->close();
                        delete window;
                        window=NULL;
                        return 1;
                    }

                    if(choixNiv==0)
                    {
                        if(sAmateur.getGlobalBounds().contains(x,y))
                        {
                            choixNiv=1;
                            jeu.remplirJoueurs(choixNiv);
                            sonMise.play();
                        }
                        else if(sIntermediaire.getGlobalBounds().contains(x,y))
                        {
                            choixNiv=2;
                            jeu.remplirJoueurs(choixNiv);
                            sonMise.play();
                        }
                        else if(sExpert.getGlobalBounds().contains(x,y))
                        {
                            choixNiv=3;
                            jeu.remplirJoueurs(choixNiv);
                            sonMise.play();
                        }
                    }
                    else
                    {
                        if(top1)
                        {
                            window->close();
                            delete window;
                            window=NULL;
                            return 1;
                        }

                        if(elimine)
                        {
                            window->close();
                            delete window;
                            window=NULL;
                            return 1;
                        }

                        if(finManche==1)
                        {
                            jeu.finManche();
                            actionMiser=0;
                            finManche=0;
                            
                            if(jeu.tabJoueur[0].getNiveau()!=0) //si nous avons été éliminés
                            {
                                elimine=1;
                                sonPerdu.play();
                            }
                            else
                            {
                                if(jeu.nbJoueurs==1)    //si pas éliminé + dernier survivant = top1
                                {
                                    top1 = 1;
                                    sonJackpot.play();
                                }
                            }
                        }

                        switch(actionMiser)
                        {
                            case 0 :
                                if(s1.getGlobalBounds().contains(x,y))  
                                {
                                    jeu.initialisationMise('a');    
                                    initPartie();
                                }
                                else if(s10.getGlobalBounds().contains(x,y))  
                                {
                                    jeu.initialisationMise('z');    
                                    initPartie();
                                }
                                else if(s100.getGlobalBounds().contains(x,y)) 
                                {
                                    jeu.initialisationMise('e');    
                                    initPartie();
                                }
                                else if(s250.getGlobalBounds().contains(x,y))  
                                {
                                    jeu.initialisationMise('r');    
                                    initPartie();
                                }
                                else if(s500.getGlobalBounds().contains(x,y))  
                                {
                                    jeu.initialisationMise('t');    
                                    initPartie();
                                }
                                break;
                            
                            case 1 :
                                if(jeu.tabJoueur[0].mainJoueur.getJoueToujours())
                                {
                                    if(sDoubler.getGlobalBounds().contains(x,y))  //on appuie sur le bouton doubler
                                    {
                                        jeu.actionClavier('d');    //on double
                                        sonMise.play();
                                        sonCarte.play();
                                        finPartie();
                                    }
                                    else if(sTirer.getGlobalBounds().contains(x,y))  //on appuie sur le bouton tirer
                                    {
                                        jeu.actionClavier('t');    //on tire
                                        sonCarte.play();
                                        finPartie();
                                    }
                                    else if(sRester.getGlobalBounds().contains(x,y))  //on appuie sur le bouton rester
                                    {
                                        jeu.actionClavier('r'); 
                                        finPartie();
                                    }
                                    else if(sChanger.getGlobalBounds().contains(x,y))  //on appuie sur le bouton rester
                                    {
                                        jeu.actionClavier('c'); //on change
                                        sonMise.play();
                                        sonCarte.play();
                                        finPartie();
                                    }
                                }
                                break;
                        }
                    }
                }
            }
            sfmlAff();
        }
    }
}
