/*
 * EventHandler.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

namespace PACMAN {
	class EventHandler {
	public:
		EventHandler();
		virtual ~EventHandler();
		virtual int PollEvent() = 0;
		virtual bool QuitEvent() = 0;
		virtual bool KeyDown() = 0;
		virtual int GetKeyDown() = 0;
	};
}

#endif /* EVENTHANDLER_H_ */
