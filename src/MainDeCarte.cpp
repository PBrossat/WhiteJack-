#include "MainDeCarte.h"
#include <iostream>
#include <cassert>


using namespace std;

MainDeCarte::MainDeCarte ()
{
    nbCartes=0;
    SommeValeur=0;
}


void MainDeCarte::tirerCarte (int niveauJoueur);
{
    switch (niveauJoueur)
    {
        case '0':
        if (sommeValeur<21)
            {
                nbCartes++;
                

            }



    }




}




void MainDeCArte::testRegression();
{
    MainDeCarte main1;
    assert (nbCartes==0);
    assert (SommeValeur==0);


}