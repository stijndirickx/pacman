#include "SDLEventHandler.h"
using namespace Graphics;

SDLEventHandler::SDLEventHandler() {}
SDLEventHandler::~SDLEventHandler() {}


int SDLEventHandler::PollEvent(){
	return SDL_PollEvent(&e);
}

bool SDLEventHandler::QuitEvent() {
	if( e.type == SDL_QUIT ){return true;}
	return false;
}

bool SDLEventHandler::KeyDown() {
	if (e.type == SDL_KEYDOWN){return true;}
	return false;
}

int SDLEventHandler::GetKeyDown() {
	int key;
	enum KeyPresses
	{
		KEY_PRESS_DEFAULT,
		KEY_PRESS_UP,
		KEY_PRESS_DOWN,
		KEY_PRESS_LEFT,
		KEY_PRESS_RIGHT,
		KEY_PRESS_SPACE
	};

	switch( e.key.keysym.sym )
	{
		case SDLK_UP:
			key = KEY_PRESS_UP;
			break;

		case SDLK_DOWN:
			key = KEY_PRESS_DOWN;
			break;

		case SDLK_LEFT:
			key = KEY_PRESS_LEFT;
			break;

		case SDLK_RIGHT:
			key = KEY_PRESS_RIGHT;
			break;

		case SDLK_SPACE:
			key = KEY_PRESS_SPACE;
			break;

		default:
			key = KEY_PRESS_DEFAULT;
			break;
		}
		return key;
	}
