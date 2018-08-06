#ifndef SDLWINDOW_H_
#define SDLWINDOW_H_
#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace Logic;

namespace Graphics{

	class SDLWindow: public Window {
	public:
		SDLWindow();
		~SDLWindow();
		void getWindow();
	private:
		SDL_Window* _window = NULL;
		SDL_Renderer* _renderer = NULL;
		SDL_Event* _mainEvent = NULL;

		SDL_Texture* _textureBob = NULL;
		SDL_Texture* _textureGrass = NULL;
	};
}

#endif /* SDLWINDOW_H_ */
