#include <iostream>
#include "AbstractFactory.h"
#include "Game.h"

using namespace std;


Game::Game(AbstractFactory* abstractFactory){
	f = abstractFactory;
}

void Game::Start(){

	/*Create all objects*/

	Pacman* p = f->createPacman();

	while(true){

		cout << "game is up and running...";
	}
}
