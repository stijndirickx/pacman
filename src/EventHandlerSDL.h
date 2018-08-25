/*
 * EventHandlerSDL.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef EVENTHANDLERSDL_H_
#define EVENTHANDLERSDL_H_

#include "EventHandler.h"
#include <sdl2/SDL.h>

namespace PACMAN {
	class EventHandlerSDL : public EventHandler{
	public:
		EventHandlerSDL();
		virtual ~EventHandlerSDL();
		int PollEvent();
		bool QuitEvent();
		bool KeyDown();
		int GetKeyDown();
	protected:
		SDL_Event e;
	};
}

#endif /* EVENTHANDLERSDL_H_ */
