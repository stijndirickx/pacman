#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_
#include "Pacman.h"

class AbstractFactory{
public:
	AbstractFactory();							//constructor
	virtual ~AbstractFactory();					//destructor
	virtual Pacman* createPacman() = 0;
};


#endif /* ABSTRACTFACTORY_H_ */
