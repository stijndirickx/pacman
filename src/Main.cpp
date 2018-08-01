#include "SDLAbstractFactory.h"
#include "AbstractFactory.h"
#include "Game.h"


int main(int argc, char* args[])
{
	Logic::AbstractFactory* f = new Graphics::SDLAbstractFactory();
	Game* g = new Game(f);
	g->Start();
	delete g;
	delete f;
	return 0;
}


