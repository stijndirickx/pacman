#include "SDLPlayer.h"

namespace PACMAN
{
	SDLPlayer::SDLPlayer(SDL_Renderer* pRenderer, SDL_Surface* pSurface)
	{
		mRenderer = pRenderer;
		mSurface = pSurface;
		playerTexture = SDL_CreateTextureFromSurface(mRenderer, mSurface);

		for(int i = 0; i <= 14; i++)
		{
			playerSprites[i].x = 37+(15*i);
			playerSprites[i].y = 0;
			playerSprites[i].w = 15;
			playerSprites[i].h = 15;
		}

	}

	SDLPlayer::~SDLPlayer() {}

	void SDLPlayer::paint()
	{
		if(mPosX == 0 && mPosY == 0)
		{
			mPosX = (screenWidth/2);
			mPosY = floor(3*screenHeight/4); //TODO better position here
			this->moveDir(4);
		}
		renderRect = {mPosX, mPosY, mWidth, mHeight};
		SDL_RenderCopy(mRenderer, playerTexture, &playerSprites[frame], &renderRect);
	}

	void SDLPlayer::moveDir(int direction)
	{
		//direction: 1 = up, 2 = down, 3 = left, 4 = right

		int velocity = mWidth / pacmanVel;
		for(int i=0; i< 3 ; i++)
		{
			playerSprites[i].y = (direction-1)*15;
		}

		switch(direction)
		{
			case 1:
				mPosY -= velocity;
				break;
			case 2:
				mPosY += velocity;
				break;
			case 3:
				mPosX -= velocity;
				break;
			case 4:
				mPosX += velocity;
				break;
		}
	}
}

