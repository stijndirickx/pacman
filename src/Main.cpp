#include <SDLAbstractFactory.h>
#include "AbstractFactory.h"
#include "Game.h"

//DEBUG
#include <iostream>
using namespace std;


int main(int argc, char* args[])
{
	Logic::AbstractFactory* f = new Graphics::SDLAbstractFactory();
	Game* g = new Game(f);
	g->Start();
	delete g;
	delete f;
	return 0;
}


