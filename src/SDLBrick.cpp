#include "SDLBrick.h"

namespace graphics_SDL
{
	SDLBrick::SDLBrick(SDL_Renderer* renderer, SDL_Texture* texture)
	{
		mRenderer = renderer;
		mTexture = texture;
	}

	SDLBrick::~SDLBrick()
	{
		// TODO Auto-generated destructor stub
	}

	void SDLBrick::visualize()
	{

		if((brickInfo[4] == PATH)||(brickInfo[4] == FOOD_REGULAR))
		{
			brickSprite = {8,24,8,8};
		}
		else if(brickInfo[4] == WALL_UP_LEFT)
		{
			brickSprite = {228,0,5,5};
		}
		else if(brickInfo[4] == WALL_UP_DOWN)
		{
			brickSprite = {228,12,5,5};
		}
		else if(brickInfo[4] == WALL_UP_RIGHT)
		{
			brickSprite = {448,0,5,5};
		}
		else if(brickInfo[4] == WALL_DOWN_LEFT)
		{
			brickSprite = {448,74,5,5};
		}
		else if(brickInfo[4] == WALL_DOWN_RIGHT)
		{
			brickSprite = {234,0,5,5};
		}
		else if(brickInfo[4] == WALL_LEFT_RIGHT)
		{
			brickSprite = {234,0,5,5};
		}
		else if(brickInfo[4] == FOOD_BONUS)
		{
			brickSprite = {487,48,15,15};
		}

		/*int type = brickInfo[4];
		switch(type)
		{
		case PATH || FOOD_REGULAR :
			brickSprite = {8,24,8,8};
			break;

		case WALL_UP_LEFT :
			brickSprite = {228,0,5,5};
			break;

		case WALL_UP_DOWN :
			brickSprite = {228,12,5,5};
			break;

		case WALL_UP_RIGHT :
			brickSprite = {448,0,5,5};
			break;

		case WALL_DOWN_LEFT :
			brickSprite = {228,74,5,5};
			break;

		case WALL_DOWN_RIGHT :
			brickSprite = {448,74,5,5};
			break;

		case WALL_LEFT_RIGHT :
			brickSprite = {234,0,5,5};
			break;

		case FOOD_BONUS :
			brickSprite = {487,48,15,15};
			break;
		}*/

		brickRect = {brickInfo[0], brickInfo[1], brickInfo[2], brickInfo[3]};
		SDL_RenderCopy(mRenderer, mTexture, &brickSprite, &brickRect);
	}

}
