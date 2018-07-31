#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

#include <Player.h>


namespace Logic{
	class AbstractFactory{
	public:
		AbstractFactory();
		virtual ~AbstractFactory();
		virtual Player* createPacman()=0;
	};
}


#endif
