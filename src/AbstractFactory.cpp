#include <iostream>
#include "Pacman.h"
#include "SDLFactory.h"

class AbstractFactory{
public:
	AbstractFactory(SDLFactory* sdlFactory);	//constructor
	virtual ~AbstractFactory();					//destructor

	virtual Pacman* createPacman() = 0;
private:
	SDLFactory* sdlf;
};

AbstractFactory::AbstractFactory(SDLFactory* sdlFactory){
	sdlf = sdlFactory;
}

