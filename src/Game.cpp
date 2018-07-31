#include <iostream>
#include "AbstractFactory.h"
#include "Game.h"

using namespace Logic;


namespace Logic{

	Game::~Game(){};

	Game::Game(AbstractFactory* abstractFactory){
		f = abstractFactory;
	}

	void Game::Start(){
		Player* p = f->createPacman();
		p->Paint();
	}
}

