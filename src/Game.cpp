#include <iostream>
#include "AbstractFactory.h"
#include "Game.h"

#include <SDL2/SDL.h> //TODO DELETE THIS, SEPRATE SDL/LOGIC

using namespace Logic;


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
		SDL_Renderer* renderer = NULL;
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		SDL_Event* mainEvent = new SDL_Event();

		while(!quit && mainEvent->type != SDL_QUIT){
			SDL_PollEvent(mainEvent);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
		}
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		delete mainEvent;


	}
}

