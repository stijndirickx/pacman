#ifndef SDLEVENTHANDLER_H_
#define SDLEVENTHANDLER_H_
#include <EventHandler.h>
#include <sdl2/sdl.h>

using namespace Logic;

namespace Graphics{
	class SDLEventHandler:public EventHandler{
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
