#include "AbstractFactory.h"
#include "Game.h"
#include "SDLFactory.h"


int main( )
{
	AbstractFactory* f = new SDLFactory();
	Game* g = new Game(f);
	g->Start();
	delete g;
	delete f;
	return 0;
}
