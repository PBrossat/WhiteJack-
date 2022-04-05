#include <cassert>
#include <time.h>
#include "jeuSdl.h"
#include <stdlib.h>

#include <iostream>
using namespace std;


// ============= CLASS IMAGE =============== //

Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) {
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}


void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}

void Image::afficherInit() 
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("Blackjack", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 950/13, 392/4, SDL_WINDOW_SHOWN );
    if (window == NULL) 
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    loadFromFile("data/Carte.png", renderer);
    loadFromCurrentSurface(renderer);

}

void Image::afficherBoucle() 
{
    bool stop = false;
    SDL_Event events;
    int h,w;
    h=392;  //total 392 pour 4 signes
    w=950;  //total 950 pour 13 cartes 
    while (!stop)
    {
        while (SDL_PollEvent(&events)) 
        {
        
        if (events.type == SDL_QUIT) stop = true;           // Si l'utilisateur a clique sur la croix de fermeture
        else if (events.type == SDL_KEYDOWN) 
        {              // Si une touche est enfoncee
            switch (events.key.keysym.scancode) 
            {
            case SDL_SCANCODE_ESCAPE:
                stop = true;
            case SDL_SCANCODE_G:
                h=h*0.75;
                w=w*0.75;
                if(w<5) w=5;
                if(h<5) h=5;
                break;
            case SDL_SCANCODE_T:
                h=h*2;
                w=w*2;
                if(h>10000) h=10000;
                if(w>10000) w=10000;
                break;
            default: break;
            }
        }
        }
        SDL_SetRenderDrawColor(renderer, 206, 206, 206, 255); 
        SDL_RenderClear(renderer);
        draw(renderer, 0, 0, w, h);
        SDL_RenderPresent(renderer);
    }
}

void Image::afficherDetruit ()
{
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window); 
    SDL_Quit();
}




