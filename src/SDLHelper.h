#ifndef SDLHELPER_H_
#define SDLHELPER_H_

#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_mixer.h>
#include <sdl2/SDL_ttf.h>

namespace graphics_SDL
{
	class SDLHelper
	{
	public:
		SDLHelper(int windowWidth, int windowHeight);
		virtual ~SDLHelper();

		SDL_Renderer* GetRenderer();
		SDL_Renderer* GetShownRenderer();
		SDL_Surface* GetSurface();
		SDL_Texture* GetTexture();


	protected:
		SDL_Renderer* renderer;
		SDL_Renderer* shownRenderer;
		SDL_Surface* screenSurface;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Window* window;
	};
}

#endif /* SDLHELPER_H_ */
