#include "AbstractFactory.h"
#include "Game.h"
#include "SDLFactory.h"


int main(int argc, char** args)
{
	AbstractFactory* f = new SDLFactory();
	Game* g = new Game(f);
	g->Start();
	delete g;
	delete f;
	return 0;
}
