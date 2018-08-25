/*
 * PacmanSDL.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef PACMANSDL_H_
#define PACMANSDL_H_

#include "Pacman.h"
#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include "Factory.h"
#include "FactorySDL.h"

using namespace std;

namespace PACMAN {
	class FactorySDL; //forward declaration for construct
	class PacmanSDL : public Pacman{
	public:
		PacmanSDL(SDL_Renderer* sdlRendererTEMP, SDL_Surface* loadedSurface);
		virtual ~PacmanSDL();
		void Visualize();
		void Move();
		void Animate();
		void MoveInDir(int direction);
		void SetDirection(int key);
		void GotCaptured(Ghost* ghosts[], int NUM_OF_GHOSTS);
	protected:
		SDL_Renderer* sdlRenderer;
		SDL_Surface* surface;

		SDL_Rect pacmanSprite[15];
		SDL_Texture* pacTexture = NULL;
		SDL_Rect renderQuad;
	};
}

#endif /* PACMANSDL_H_ */
