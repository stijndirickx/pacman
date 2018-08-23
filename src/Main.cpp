#include <iostream>


#include "AbstractFactory.h"
#include "Game.h"
#include "SDLAbstractFactory.h"


using namespace std;

int main(int argc, char* args[])
{
	cout << "t";
	logic::AbstractFactory* f = new graphics_SDL::SDLAbstractFactory();
	Game* g = new Game(f);
	g->Start();
	delete g;
	delete f;
	return 0;
}


