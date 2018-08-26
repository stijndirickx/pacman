#include "PacmanSDL.h"

namespace PACMAN
{
	PacmanSDL::PacmanSDL(SDL_Renderer* sdlRendererTEMP, SDL_Surface* loadedSurface)
	{
		sdlRenderer = sdlRendererTEMP;
		surface = loadedSurface;
		pacTexture = SDL_CreateTextureFromSurface(sdlRenderer, surface);

		//SPRITES
		//living: 0-2
		//dead: 3-11
		for(int i = 0; i <= 14; i++)
		{
			pacmanSprite[i].x = 37+(15*i);
			pacmanSprite[i].y = 0;
			pacmanSprite[i].w = 15;
			pacmanSprite[i].h = 15;
		}
	}

	PacmanSDL::~PacmanSDL() {}

	void PacmanSDL::Visualize()
	{
		if(mPosX == 0 && mPosY == 0)
		{
			mPosX = (screenWidth/2);
			mPosY = floor(3*screenHeight/4); //TODO better position here
		}
		renderQuad = {mPosX, mPosY, mWidth, mHeight};
		SDL_RenderCopy(sdlRenderer, pacTexture, &pacmanSprite[frame], &renderQuad);
	}

	void PacmanSDL::MoveInDir(int direction)
	{
		int velocity = mWidth / pacmanVel;
		switch(direction)
		{
			case 1: //UP
				mPosY -= velocity;
				pacmanSprite[0].x = 37;
				pacmanSprite[0].y = 30;
				pacmanSprite[1].x = 52;
				pacmanSprite[1].y = 30;
				pacmanSprite[2].x = 67;
				pacmanSprite[2].y = 30;
				break;
			case 2: //DOWN
				mPosY += velocity;

				pacmanSprite[0].x = 37;
				pacmanSprite[0].y = 45;
				pacmanSprite[1].x = 52;
				pacmanSprite[1].y = 45;
				pacmanSprite[2].x = 67;
				pacmanSprite[2].y = 45;
				break;
			case 3: //LEFT
				mPosX -= velocity;
				pacmanSprite[0].x = 37;
				pacmanSprite[0].y = 15;
				pacmanSprite[1].x = 52;
				pacmanSprite[1].y = 15;
				pacmanSprite[2].x = 67;
				pacmanSprite[2].y = 15;
				break;
			case 4: //RIGHT
				mPosX += velocity;
				pacmanSprite[0].x = 37;
				pacmanSprite[0].y = 0;
				pacmanSprite[1].x = 52;
				pacmanSprite[1].y = 0;
				pacmanSprite[2].x = 67;
				pacmanSprite[2].y = 0;
				break;
		}
	}
}

