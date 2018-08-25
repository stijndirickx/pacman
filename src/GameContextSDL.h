/*
 * GameContextSDL.h
 *
 *  Created on: May 15, 2018
 *      Author: ruben
 */

#ifndef GAMECONTEXTSDL_H_
#define GAMECONTEXTSDL_H_

#include <iostream>

#include <sdl2/SDL_ttf.h>
#include <sdl2/SDL_mixer.h>
#include "GameContext.h"
#include "InitSDL.h"

using namespace std;

namespace PACMAN {
	class GameContextSDL : public GameContext{
	public:
		GameContextSDL(InitSDL* sdlInit);
		virtual ~GameContextSDL();
		void UpdateText();
		void PlaySound(string sound);
		void ClearScreen();
		void UpdateScreen();
		void QuitVis();
	protected:
		PACMAN::InitSDL* sdlInit;

		SDL_Renderer* sdlRendererTemp;
		SDL_Surface* loadedSurface;

		TTF_Font* font;
		TTF_Font* fontBig;
		SDL_Color white;
		SDL_Surface* textSurface;
		SDL_Texture* messageTexture;
		SDL_Rect messageRect;
		std::string printTxt = "";

		Mix_Chunk *pacMusic;
		Mix_Chunk *pacSound;
	};
}

#endif /* GAMECONTEXTSDL_H_ */
