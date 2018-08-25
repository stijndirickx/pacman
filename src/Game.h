/*
 * Game.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef GAME_H_
#define GAME_H_

#include "Factory.h"
#include "Ghost.h"
#include "Map.h"
#include "Config.h"
#include "EventHandlerSDL.h"
#include "EventHandler.h"
#include <time.h>

using namespace std;

namespace PACMAN {
	class Game {
	public:
		Factory* aFactory;
		Game(Factory*& abstractFactory);
		virtual ~Game();
		void Start();
	protected:
		Config* cFile;
		int fps;
		int mspf;
		int countToAttacking;
		int numOfGhosts;
		int animationSpeed;
	};
}

#endif /* GAME_H_ */
