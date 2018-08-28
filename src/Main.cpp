#include <iostream>

#include "AbstractFactory.h"
#include "Game.h"
#include "SDLAbstractFactory.h"

using namespace std;

int main(int argc, char* args[])  //parameters for SDL
{
	logic::AbstractFactory* aFactory = new graphics_SDL::SDLAbstractFactory();
	Game* game = new Game(aFactory);
	game->start();
	delete aFactory;
	delete game;

	return 0;
}
