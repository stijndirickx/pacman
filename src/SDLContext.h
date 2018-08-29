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
			SDLContext(SDLHelper* pHelper);
			virtual ~SDLContext();

			void updateText();
			void playSound(string sound);
			void clearScreen();
			void updateScreen();


		protected:
			void renderText(TTF_Font* font, string msgTxt, int x, int y, int option);


			SDLHelper* mHelper;

			SDL_Renderer* renderer;
			SDL_Surface* surface;

			TTF_Font* fontText;
			TTF_Font* fontTitle;
			SDL_Color msgColor;

			Mix_Chunk *pacMusic;
			Mix_Chunk *pacSound;
	};
}

#endif
