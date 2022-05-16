#include "Application.h"


Application::Application()
{
    if (!tExit.loadFromFile("data/exit.png")) 
    {
        cout << "Error data/exit.png non found" << endl;
    }
    else 
    {
        sExit.setTexture(tExit);
        sExit.setPosition((1400/64),30);
        sExit.setScale(0.4,0.4);
    }
}



Application::~Application()
{

}



unsigned int Application::afficherRegles()
{
    sf::View view(sf::Vector2f(1400/2.f, 375.f), sf::Vector2f(1400.f, 750.f));
    sf::RenderWindow * fenetre;
	fenetre = new RenderWindow(VideoMode(1400,750), "Regle" , Style::Default);
	while (fenetre->isOpen())
	{
		Event event; 
        while (fenetre->pollEvent(event))
        {
			if (event.type == Event::Closed)   
            {
                fenetre->close();
                delete fenetre;
                fenetre=NULL;
                return 0;
            }
            if(event.type == Event::MouseButtonPressed)
            {
                if(event.key.code == Mouse::Left)
                {
                    float x = Mouse::getPosition(*fenetre).x;
                    float y = Mouse::getPosition(*fenetre).y;
                    if(sExit.getGlobalBounds().contains(x,y))
                    {
                        fenetre->close();
                        delete fenetre;
                        fenetre=NULL;
                        return 1;
                    }
                }
            }
			if (event.type == Event::MouseWheelScrolled)
			{
				if(event.mouseWheelScroll.delta<0)
				{
					if(view.getCenter().y < menu.rsRegle.getSize().y-450)
					{
						view.move(0, 100.f);
						fenetre->setView(view);
					}
				}
				else if(event.mouseWheelScroll.delta>0)
				{
					if(view.getCenter().y > 375)
					{
						view.move(0, -100.f);
						fenetre->setView(view);
					}
				}
			}
		}
		fenetre->draw(menu.rsRegle);
        fenetre->draw(sExit);
		fenetre->display();
	}
}

void Application::boucleApplication()
{
    menu.initMenu();
    choixRetour=0;
    choixMenu=0;
    choixMenu = menu.boucleMenu();
    if(choixMenu==1)
    {
            JeuSoloSfml* jeuSolo = new JeuSoloSfml;
            jeuSolo->sfmlInit();
            jeuSolo->sfmlAff();
            choixRetour = jeuSolo->sfmlBoucle();
            if(choixRetour==1)
            {
                delete jeuSolo;
                jeuSolo=NULL;
                boucleApplication();
            }
    }
    else if(choixMenu==2)
    {
            JeuMultiSfml* jeuMulti = new JeuMultiSfml;
            jeuMulti->sfmlInit();
            jeuMulti->sfmlAff();
            choixRetour = jeuMulti->sfmlBoucle();
            if(choixRetour==1)
            {
                delete jeuMulti;
                jeuMulti=NULL;
                boucleApplication();
            }
    }
    else if(choixMenu==3)
    {
        choixRetour = afficherRegles();
        if(choixRetour==1)
        {
            boucleApplication();
        }
    }
}