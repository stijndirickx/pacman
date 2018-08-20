#ifndef SDLPLAYER_H_
#define SDLPLAYER_H_
#include "Player.h"

using namespace logic;

namespace graphics_SDL{

	class SDLPlayer: public Player
	{
	public:
		SDLPlayer();
		~SDLPlayer();
		void Paint();
	};
}

#endif /* SDLPLAYER_H_ */
