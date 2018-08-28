#include "SDLEventHandler.h"

namespace PACMAN
{
	SDLEventHandler::SDLEventHandler() {}

	SDLEventHandler::~SDLEventHandler() {}

	int SDLEventHandler::pollEvent()
	{
		return SDL_PollEvent(&e);
	}

	bool SDLEventHandler::quitEvent()
	{
		if(e.type == SDL_QUIT)
		{
			return true;
		}
		return false;
	}

	bool SDLEventHandler::keyDown()
	{
		if (e.type == SDL_KEYDOWN)
		{
			return true;
		}
		return false;
	}

	int SDLEventHandler::getKeyDown()
	{
		int key;
		enum KeyPressSurfaces
		{
			KEY_PRESS_SURFACE_DEFAULT,
			KEY_PRESS_SURFACE_UP,
			KEY_PRESS_SURFACE_DOWN,
			KEY_PRESS_SURFACE_LEFT,
			KEY_PRESS_SURFACE_RIGHT,
			KEY_PRESS_SURFACE_TOTAL,
			KEY_PRESS_ENTER
		};

		switch(e.key.keysym.sym)
		{
			case SDLK_UP:
				key = KEY_PRESS_SURFACE_UP;
				break;
			case SDLK_DOWN:
				key = KEY_PRESS_SURFACE_DOWN;
				break;
			case SDLK_LEFT:
				key = KEY_PRESS_SURFACE_LEFT;
				break;
			case SDLK_RIGHT:
				key = KEY_PRESS_SURFACE_RIGHT;
				break;
			case SDLK_RETURN:
				key = KEY_PRESS_ENTER;
				break;
			default:
				key = KEY_PRESS_SURFACE_DEFAULT;
				break;
		}
		return key;
	}
}

