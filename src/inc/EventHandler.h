#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

namespace Logic{
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
