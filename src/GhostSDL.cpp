/*
 * GhostSDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "GhostSDL.h"

namespace PACMAN {
	GhostSDL::GhostSDL(int ghostType, SDL_Renderer* sdlRendererTEMP, SDL_Surface* loadedSurface){
		sdlRenderer = sdlRendererTEMP;
		surface = loadedSurface;
		ghostTexture = SDL_CreateTextureFromSurface( sdlRendererTEMP, surface );

		type = ghostType;

		ghostSprite[0].w = 15;
		ghostSprite[0].h = 15;
	}

	GhostSDL::~GhostSDL(){

	}

	void GhostSDL::Visualize(){
		if(mPosX == 0 && mPosY == 0){ //default setting when factory was unknown.
			mPosX = (screenWidth/2)-(floor(numOfGhosts/2) * mWidth)+(type*mWidth);
			mPosY = (screenHeight/2);
		}
		if(attacking){
			ghostSprite[0].x = 455;
			if(type == 0) {
				ghostSprite[0].y = 64;
			} else if (type == 1) {
				ghostSprite[0].y = 80;
			} else if (type == 2) {
				ghostSprite[0].y = 96;
			} else {
				ghostSprite[0].y = 112;
			}
		} else {
			if(living){
				if(!flashing){
					ghostSprite[0].x = 584;
					ghostSprite[0].y = 64;
				} else {
					ghostSprite[0].x = 616;
					ghostSprite[0].y = 64;
				}
			} else {
				ghostSprite[0].x = 584;
				ghostSprite[0].y = 80;
			}
		}

		renderQuadG = { mPosX, mPosY, mWidth, mHeight };
		SDL_RenderCopy( sdlRenderer, ghostTexture, &ghostSprite[0], &renderQuadG );
	}
}
