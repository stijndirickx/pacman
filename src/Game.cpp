#include <iostream>
#include "AbstractFactory.h"
#include "Game.h"

namespace logic
{
	Game::~Game(){};

	Game::Game(AbstractFactory* abstractFactory){
		f = abstractFactory;
		quit = false;
		CPlayer = NULL;
		//CWindow = NULL;
	}

	void Game::Start(){
		//CWindow = f->createWindow(); //Gets class Window
		CPlayer = f->createPlayer();
		CPlayer->Paint();

		/*if(CWindow == NULL){
			std::cout << "Window not created." << std::endl;
			quit = true;
		}

		CWindow->getWindow();*/


//		while(!quit && CWindow::_mainEvent->type != SDL_QUIT){
//			SDL_PollEvent(mainEvent);
//			SDL_RenderClear(_renderer);
//			SDL_RenderCopy(_renderer, _TextureGrass, NULL, &rectGrass);
//			SDL_RenderCopy(_renderer, _TextureBob, NULL, &rectBob);
//			SDL_RenderPresent(_renderer);
//		}
//		SDL_DestroyTexture(_TextureGrass);
//		SDL_DestroyTexture(_TextureBob);
//		//SDL_DestroyWindow(window);
//		SDL_DestroyRenderer(_renderer);
//		delete mainEvent;
//		SDL_Quit();


	}

	SDL_Texture* Game::loadTexture(std::string path)
	{
		std::cout << "Game::loadTexture" << std::endl;
		SDL_Texture* newTexture = NULL;
		SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
		newTexture = SDL_CreateTextureFromSurface( _renderer, loadedSurface );
		if( newTexture == NULL )
		{
			std::cout << "texture not loaded" << std::endl;
		}
		SDL_FreeSurface( loadedSurface );
		return newTexture;
	}
}

