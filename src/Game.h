#ifndef GAME_H_
#define GAME_H_

#include <time.h>

#include "AbstractFactory.h"
#include "EventHandler.h"

using namespace std;

namespace logic
{
	class Game
	{
		public:
			Game(AbstractFactory*& pAbstractFactory);
			virtual ~Game();

			void start();

		protected:
			AbstractFactory* mAbstractFactory;
			Config* config;
	};
}

#endif
