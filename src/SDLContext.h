#ifndef SDLCONTEXT_H_
#define SDLCONTEXT_H_

#include <iostream>
#include <sdl2/SDL_ttf.h>
#include <sdl2/SDL_mixer.h>

#include "Context.h"
#include "SDLHelper.h"

using namespace std;
using namespace logic;

namespace graphics_SDL
{
	class SDLContext : public Context
	{
		public:
			SDLContext(SDLHelper* pSDLHelper);
			virtual ~SDLContext();

			void updateText();
			void playSound(string sound);
			void clearScreen();
			void updateScreen();
			void quitVisualization();

		protected:
			SDLHelper* mSDLHelper;

			SDL_Renderer* renderer;
			SDL_Surface* surface;

			TTF_Font* fontText;
			TTF_Font* fontTitle;
			SDL_Color msgColor;
			SDL_Surface* msgSurface;
			SDL_Texture* msgTexture;
			SDL_Rect msgRect;
			std::string msgString = "";

			Mix_Chunk* startMix; //TODO rename
			Mix_Chunk* eatMix;
	};

}

#endif
