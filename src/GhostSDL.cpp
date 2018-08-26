#include "GhostSDL.h"

namespace PACMAN
{
	GhostSDL::GhostSDL(int ghostType, SDL_Renderer* sdlRendererTEMP, SDL_Surface* loadedSurface)
	{
		sdlRenderer = sdlRendererTEMP;
		surface = loadedSurface;
		ghostTexture = SDL_CreateTextureFromSurface(sdlRendererTEMP, surface);

		type = ghostType;

		ghostSprite[0].w = 15;
		ghostSprite[0].h = 15;
	}

	GhostSDL::~GhostSDL(){}

	void GhostSDL::Visualize()
	{
		if(mPosX == 0 && mPosY == 0) //default setting when factory was unknown.
		{
			mPosX = (screenWidth/2)-(floor(numOfGhosts/2) * mWidth)+(type*mWidth);
			mPosY = (screenHeight/2);
		}

		ghostSprite[0].y = 15;

		if(attacking)
		{
			if(type == 0)
			{
				ghostSprite[0].x = 82;
			}
			else if (type == 1)
			{
				ghostSprite[0].x = 97;
			}
			else if (type == 2)
			{
				ghostSprite[0].x = 112;
			}
			else
			{
				ghostSprite[0].x = 127;
			}
		}
		else
		{
			if(living)
			{
				if(!flashing)
				{
					ghostSprite[0].x = 142;
				}
				else
				{
					ghostSprite[0].x = 157;
				}
			}
			else
			{
				ghostSprite[0].x = 172;
			}
		}
		renderQuadG = {mPosX, mPosY, mWidth, mHeight};
		SDL_RenderCopy(sdlRenderer, ghostTexture, &ghostSprite[0], &renderQuadG);
	}
}
