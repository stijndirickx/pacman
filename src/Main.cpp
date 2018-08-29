#include <iostream>

#include "AbstractFactory.h"
#include "Game.h"
#include "SDLAbstractFactory.h"

using namespace std;

int main(int argc, char* args[])
{
	logic::AbstractFactory* abstractFactory = new graphics_SDL::SDLAbstractFactory();
	Game* game = new Game(abstractFactory);
	game->start();
	delete abstractFactory;
	delete game;
	return 0;
}
