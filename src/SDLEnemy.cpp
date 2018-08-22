#include "SDLEnemy.h"

namespace graphics_SDL
{

	SDLEnemy::SDLEnemy(SDL_Renderer* pRenderer, SDL_Surface* pSurface, int pType)
	{
		mRenderer = pRenderer;
		mSurface = pSurface;
		enemyTexture = SDL_CreateTextureFromSurface(mRenderer, mSurface);
		type = pType;

		enemySprite[0].w = 15;
		enemySprite[0].h = 15;
	}

	SDLEnemy::~SDLEnemy()
	{

	}

	void SDLEnemy::paint() //TODO insert switch?
	{
		if(x == 0 && y == 0) //TODO default setting when factory was unknown.
		{
			x = (screenWidth/2)-(floor(numOfEnemies/2) * w)+(type*w);
			y = (screenHeight/2);
		}

		if(attacking)
		{
			enemySprite[0].x = 455;
			if(type == 0)
			{
				enemySprite[0].y = 64;
			}
			else if (type == 1)
			{
				enemySprite[0].y = 80;
			}
			else if (type == 2)
			{
				enemySprite[0].y = 96;
			}
			else
			{
				enemySprite[0].y = 112;
			}
		}

		else
		{
			if(living)
			{
				if(!flashing)
				{
					enemySprite[0].x = 584;
					enemySprite[0].y = 64;
				}
				else
				{
					enemySprite[0].x = 616;
					enemySprite[0].y = 64;
				}
			}
			else
			{
				enemySprite[0].x = 584;
				enemySprite[0].y = 80;
			}
		}

		renderRect = {x, y, w, h};
		SDL_RenderCopy(mRenderer, enemyTexture, &enemySprite[0], &renderRect );
	}

}
