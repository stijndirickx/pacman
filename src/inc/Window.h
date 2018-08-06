#ifndef WINDOW_H_
#define WINDOW_H_

namespace Logic{
	class Window {
	public:
		Window();
		virtual ~Window();
		virtual void getWindow()=0;
	};
}

#endif /* WINDOW_H_ */
