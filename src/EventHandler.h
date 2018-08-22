#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

namespace logic
{
	class EventHandler
	{
		public:
			EventHandler();
			virtual ~EventHandler();

			virtual int getKeyDown() = 0;
			virtual bool keyDown() = 0;
			virtual int pollEvent() = 0;
			virtual bool quitEvent() = 0;
	};
}

#endif
