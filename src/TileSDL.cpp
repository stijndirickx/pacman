#include "TileSDL.h"

namespace PACMAN
{
	TileSDL::TileSDL(SDL_Renderer* sdlRendererTEMP, SDL_Texture* tileTexture)
	{
		sdlRenderer = sdlRendererTEMP;
		texture = tileTexture;
	}

	TileSDL::~TileSDL()
	{
		// TODO Auto-generated destructor stub
	}

	void TileSDL::Visualize()
	{

		switch(boxInt[4])
		{
			case 1:
				brickSprite = {0,0,8,8};
				break;
			case 2:
				brickSprite = {8,0,8,8};
				break;
			case 3:
				brickSprite = {16,0,8,8};
				break;
			case 4:
				brickSprite = {24,0,8,8};
				break;
			case 5:
				brickSprite = {0,8,8,8};
				break;
			case 6:
				brickSprite = {8,8,8,8};
				break;
			case 7:
				brickSprite = {16,8,8,8};
				break;
			case 8:
				brickSprite = {24,8,8,8};
				break;
			case 9:
				brickSprite = {0,16,8,8};
				break;
			case 10:
				brickSprite = {8,16,8,8};
				break;
			case 11:
				brickSprite = {16,16,8,8};
				break;
			case 12:
				brickSprite = {24,16,8,8};
				break;
			case 13:
				brickSprite = {0,24,8,8};
				break;
			case 14:
				brickSprite = {8,24,8,8};
				break;
			case 15:
				brickSprite = {16,24,8,8};
				break;
			case 16:
				brickSprite = {24,24,8,8};
				break;
			case 17:
				brickSprite = {0,32,8,8};
				break;
			case 18:
				brickSprite = {8,32,8,8};
				break;
			case 19:
				brickSprite = {16,32,8,8};
				break;
			case 20:
				brickSprite = {24,32,8,8};
				break;
			case 21:
				brickSprite = {0,40,8,8};
				break;
			case 22:
				brickSprite = {8,40,8,8};
				break;
			case 23:
				brickSprite = {16,40,8,8};
				break;
			case 24:
				brickSprite = {24,40,8,8};
				break;
		}
		brickRect = { boxInt[0], boxInt[1], boxInt[2], boxInt[3] };
		SDL_RenderCopy( sdlRenderer, texture, &brickSprite, &brickRect );
	}
}
