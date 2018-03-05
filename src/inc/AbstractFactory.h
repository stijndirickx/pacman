#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_
#include "SDLFactory.h"
#include "Pacman.h"

class AbstractFactory
{
public:
	AbstractFactory(SDLFactory* sdlFactory);
	virtual ~AbstractFactory();
	virtual Pacman* createPacman() = 0;
private:
	SDLFactory* sdlf;
};


#endif /* ABSTRACTFACTORY_H_ */
