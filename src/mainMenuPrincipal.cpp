#include "MenuSfml.h"
#include <SFML/Graphics.hpp>
using namespace sf;

void main ()
{
    RenderWindow MENU (VideoMode(1400,750), "Menu Principal" , Style::Default);
    Menu menuPrincipal (MENU.getSize().x, MENU.getSize().y);


    while (MENU.isOpen())
    {
        Event evenenement; 
        while (MENUI.pollEvent(evenement))
        {
            if (evenenement.type==Event::Closed)
            {
                MENU.close();
            }
            if (evenenement.type==Event::KeyReleased)
            {
                if (evenement.key.code==Keyboard::Up)
                {
                    menuPrincipal.monter();
                    break;
                }
                if (evenement.key.code==Keyboard::Down)
                {
                    menuPrincipal.descendre();
                    break;
                }
                if (evenement.key.code==Keyboard::Return)
                {
                    RenderWIndow JeuSolo(VideoMode(1400,750), "Mode Solo")
                    RenderWIndow JeuMulti(VideoMode(1400,750), "Mode Multi")
                    RenderWIndow Regles(VideoMode(1400,750), "Règles")
                    
                    int x = menuPrincipal.MenuPrincipalSelection();
                    if (x==0)
                    {
                        while (JeuSolo.isOpen())
                        {
                            Event evenementSolo;
                            while(JeuSolo.pollEvent(evenementSolo))
                            {
                                if (evenementSolo.type==Event::Closed)
                                {
                                    JeuSolo.close();
                                }
                                if (evenementSolo.type==Event::KeyPressed)
                                {
                                    if (evenementSolo.key.code==Keyboard::Escape)
                                    {
                                        JeuSolo.close();
                                    }
                                }
                            }
                            JeuMulti.close();
                            Regles.close();
                            JeuSolo.clear();
                            JeuSolo.display();
                        }
                    }
                    if (x==1)
                    {
                        Event evenementMulti;
                        while(JeuMulti.pollEvent(evenementMulti))
                        {
                            if (evenementMulti.type==Event::Closed)
                            {
                                JeuMulti.close();
                                }
                                if (evenementMulti.type==Event::KeyPressed)
                                {
                                    if (evenementMulti.key.code==Keyboard::Escape)
                                    {
                                        JeuMulti.close();
                                    }
                                } 
                            }
                            JeuMulti.close();
                            Regles.close();
                            JeuMulti.display();
                        }
                    }
                    if(x==2)
                    {
                        while(Regles.isOpen())
                        {
                            Event evenementRegle;
                            while(Regle.pollEvent(evenementRegle))
                        {
                            if (evenementRegle.type==Event::Closed)
                            {
                                Regle.close();
                                }
                                if (evenementRegle.type==Event::KeyPressed)
                                {
                                    if (evenementRegle.key.code==Keyboard::Escape)
                                    {
                                        Regle.close();
                                    }
                                } 
                            }
                            JeuSolo.close();
                            JeuMulti.clear();
                            Regle.display();
                            Regle.clear();
                        }
                    }
                    if(x==3)
                    {
                        MENU.close();
                        break;
                    }
                }

            }
            MENU.clear();
            menuPrincipal.dessiner(MENU);
            MENU.display();
            
        }



    }


}