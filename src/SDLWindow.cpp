#include "SDLWindow.h"
#include <iostream>
using namespace Graphics;


SDLWindow::SDLWindow() {

}

SDLWindow::~SDLWindow() {}

void SDLWindow::getWindow(){
	std::cout << "HI" << std::endl;
	SDL_Init(SDL_INIT_VIDEO);
	_window = SDL_CreateWindow("Pacman ~ Stijn Dirickx", 100, 100, 600, 400, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	_renderer = SDL_CreateRenderer(_window, -1, 0);
	_mainEvent = new SDL_Event();

	_textureGrass = IMG_LoadTexture(_renderer,"Assets/grass.bmp");
	_textureBob = IMG_LoadTexture(_renderer,"Assets/bob.png");

	SDL_Rect rectGrass = {0,0,600,400};
	SDL_Rect rectBob = {300,250,50,80};
}



