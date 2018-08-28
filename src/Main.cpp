#include <iostream>

#include "AbstractFactory.h"
#include "Game.h"
#include "SDLAbstractFactory.h"

using namespace std;

int main(int argc, char* args[])  //parameters for SDL
{
	PACMAN::AbstractFactory* aFactory = new PACMAN::SDLAbstractFactory();
	PACMAN::Game* game = new PACMAN::Game(aFactory);
	game->start();
	delete aFactory;
	delete game;

	return 0;
}
