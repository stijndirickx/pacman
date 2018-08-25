/*
 * PacmanSDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "PacmanSDL.h"

namespace PACMAN {
	PacmanSDL::PacmanSDL(SDL_Renderer* sdlRendererTEMP, SDL_Surface* loadedSurface) {
		sdlRenderer = sdlRendererTEMP;
		surface = loadedSurface;
		pacTexture = SDL_CreateTextureFromSurface( sdlRenderer, surface );

		//SPRITES
		//living: 0-2
		//dead: 3-11
		for(int i = 0; i <= 14; i++){
			pacmanSprite[i].x = 455+(16*i);
			pacmanSprite[i].y = 0;
			pacmanSprite[i].w = 15;
			pacmanSprite[i].h = 15;
		}
	}

	PacmanSDL::~PacmanSDL() {
		// TODO Auto-generated destructor stub
	}

	void PacmanSDL::Visualize(){
		if(mPosX == 0 && mPosY == 0){
			mPosX = (screenWidth/2);
			mPosY = floor(3*screenHeight/4); //TODO better position here
		}
		renderQuad = { mPosX, mPosY, mWidth, mHeight };
		SDL_RenderCopy( sdlRenderer, pacTexture, &pacmanSprite[frame], &renderQuad );
	}

	void PacmanSDL::MoveInDir(int direction){
		int velocity = mWidth / pacmanVel;
		switch(direction)
		{
			case 1: //UP
				mPosY -= velocity;
				pacmanSprite[0].x = 455;
				pacmanSprite[1].x = 471;
				pacmanSprite[0].y = 32;
				pacmanSprite[1].y = 32;
				break;
			case 2: //DOWN
				mPosY += velocity;

				pacmanSprite[0].x = 455;
				pacmanSprite[1].x = 471;
				pacmanSprite[0].y = 48;
				pacmanSprite[1].y = 48;
				break;
			case 3: //LEFT
				mPosX -= velocity;
				pacmanSprite[0].x = 455;
				pacmanSprite[1].x = 471;
				pacmanSprite[0].y = 16;
				pacmanSprite[1].y = 16;
				break;
			case 4: //RIGHT
				mPosX += velocity;
				pacmanSprite[0].x = 455;
				pacmanSprite[1].x = 471;
				pacmanSprite[0].y = 0;
				pacmanSprite[1].y = 0;
				break;
			default:
				break;
		}
	}
}

