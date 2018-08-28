#ifndef SDLEVENTHANDLER_H_
#define SDLEVENTHANDLER_H_

#include "EventHandler.h"
#include <sdl2/SDL.h>

using namespace logic;

namespace graphics_SDL
{
	class SDLEventHandler : public EventHandler
	{
		public:
			SDLEventHandler();
			virtual ~SDLEventHandler();

			int pollEvent();
			bool quitEvent();
			bool keyDown();
			int getKeyDown();

		protected:
			SDL_Event e;
	};
}

#endif
