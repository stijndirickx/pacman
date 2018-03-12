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
	p->Paint(); //output/ painted sdlpacman

//	while(true){ //makes program crash atm because its rather empty
//
//		//cout << "game is up and running...";
//	}
}
