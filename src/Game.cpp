#include <iostream>
#include "AbstractFactory.h"

using namespace std;

class Game{
public:
	Game(AbstractFactory* abstractFactory);
	void Start();
private:
	AbstractFactory* f;
};

Game::Game(AbstractFactory* abstractFactory){
	f = abstractFactory;
}

void Game::Start(){

	/*Create all objects*/

	//PAC = f->createPACMAN()

	while(true){
		cout << "game is up and running...";
	}
}
