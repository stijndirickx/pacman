#include "SDLBrick.h"

namespace graphics_SDL
{
	SDLBrick::SDLBrick(SDL_Renderer* pRenderer, SDL_Texture* pTexture)
	{
		mRenderer = pRenderer;
		mTexture = pTexture;
	}

	SDLBrick::~SDLBrick(){}

	void SDLBrick::paint()
	{
		//To see different types --> Assets/Maps/legend.txt
		switch(brickProp[3])
		{
			case 1: // path but empty
				brickSprite = {0,0,8,8};
				break;
			case 2: // path but with plus
				brickSprite = {8,0,8,8};
				break;
			case 3: // big plus
				brickSprite = {16,0,8,8};
				break;
			case 4:	// barrier
				brickSprite = {24,0,8,8};
				break;
			case 5: // double wall topleft
				brickSprite = {0,8,8,8};
				break;
			case 6: // double wall topright
				brickSprite = {8,8,8,8};
				break;
			case 7: // double wall bottomleft
				brickSprite = {16,8,8,8};
				break;
			case 8: // double wall bottomright
				brickSprite = {24,8,8,8};
				break;
			case 9: // double wall top
				brickSprite = {0,16,8,8};
				break;
			case 10: // double wall right
				brickSprite = {8,16,8,8};
				break;
			case 11: // double wall bottom
				brickSprite = {16,16,8,8};
				break;
			case 12: // double wall left
				brickSprite = {24,16,8,8};
				break;
			case 13: // single wall topleft
				brickSprite = {0,24,8,8};
				break;
			case 14: // single wall topright
				brickSprite = {8,24,8,8};
				break;
			case 15: // single wall bottomleft
				brickSprite = {16,24,8,8};
				break;
			case 16: // single wall bottomright
				brickSprite = {24,24,8,8};
				break;
			case 17: // single wall top
				brickSprite = {0,32,8,8};
				break;
			case 18: // single wall right
				brickSprite = {8,32,8,8};
				break;
			case 19: // single wall bottom
				brickSprite = {16,32,8,8};
				break;
			case 20: // single wall left
				brickSprite = {24,32,8,8};
				break;
			case 21: // inner wall topleft
				brickSprite = {0,40,8,8};
				break;
			case 22: // inner wall topright
				brickSprite = {8,40,8,8};
				break;
			case 23: // inner wall bottomleft
				brickSprite = {16,40,8,8};
				break;
			case 24: // inner wall bottomright
				brickSprite = {24,40,8,8};
				break;
			case 25: // eclipse
				brickSprite = {0,48,15,15};
				break;
		}
		brickRect = { brickProp[0], brickProp[1], brickProp[2], brickProp[2] };
		SDL_RenderCopy( mRenderer, mTexture, &brickSprite, &brickRect );
	}
}
