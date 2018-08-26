#include <iostream>

#include "Factory.h"
#include "FactorySDL.h"
#include "Game.h"

using namespace std;

int main(int argc, char* args[])  //parameters for SDL
{
	PACMAN::Factory* aFactory = new PACMAN::FactorySDL();
	PACMAN::Game* game = new PACMAN::Game(aFactory);
	game->Start();
	delete aFactory;
	delete game;

	return 0;
}
