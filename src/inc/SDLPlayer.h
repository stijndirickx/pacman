#ifndef SDLPLAYER_H_
#define SDLPLAYER_H_
#include "Player.h"

using namespace Logic;

namespace Graphics{

	class SDLPlayer: public Player{
	public:
		~SDLPlayer();
		SDLPlayer();
		void Paint();
	};
}

#endif /* SDLPLAYER_H_ */
