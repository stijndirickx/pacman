#ifndef SDLEVENTHANDLER_H_
#define SDLEVENTHANDLER_H_

#include <sdl2/sdl.h>

#include "EventHandler.h"


using namespace logic;

namespace graphics_SDL
{
	class SDLEventHandler:public EventHandler
	{
	public:
		SDLEventHandler();
		virtual ~SDLEventHandler();
		int PollEvent();
		bool QuitEvent();
		bool KeyDown();
		int GetKeyDown();

	protected:
		SDL_Event e;
	};
}

#endif
