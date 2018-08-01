#include <iostream>
#include "AbstractFactory.h"
#include "Game.h"

namespace Logic{

	Game::~Game(){};

	Game::Game(AbstractFactory* abstractFactory){
		f = abstractFactory;
	}

	void Game::Start(){
		Player* p = f->createPacman();
		p->Paint();


		//NEW testing phase
		bool quit = false;
		SDL_Init(SDL_INIT_VIDEO);
		SDL_Window* window = NULL;
		window = SDL_CreateWindow("test", 100, 100, 600, 400, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if(window == NULL){
			std::cout << "error";
		}

		_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		SDL_Event* mainEvent = new SDL_Event();


		//_TextureGrass = IMG_LoadTexture(_renderer,"grass.bmp");
		//_TextureBob = loadTexture("Assets/bob.png");

		SDL_Rect grass_rect;
		grass_rect.x = 10;
		grass_rect.y = 50;
		grass_rect.w = 250;
		grass_rect.h = 250;

		while(!quit && mainEvent->type != SDL_QUIT){
			SDL_PollEvent(mainEvent);
			SDL_RenderClear(_renderer);
			//SDL_RenderCopy(_renderer, _TextureGrass, NULL, &grass_rect);
			SDL_RenderPresent(_renderer);
		}
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(_renderer);
		delete mainEvent;


	}

	SDL_Texture* Game::loadTexture( std::string path )
	{
		SDL_Texture* newTexture = NULL;
//		SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
//		newTexture = SDL_CreateTextureFromSurface( _renderer, loadedSurface );
//		if( newTexture == NULL )
//		{
//			std::cout << "texture not loaded" << std::endl;
//		}
//		SDL_FreeSurface( loadedSurface );
		return newTexture;
	}
}

