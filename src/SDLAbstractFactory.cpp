#include "SDLAbstractFactory.h"

using namespace graphics_SDL;

SDLAbstractFactory::~SDLAbstractFactory(){}
SDLAbstractFactory::SDLAbstractFactory(){}

Player* SDLAbstractFactory::createPlayer(){
	return new SDLPlayer();
}

/*Window* SDLAbstractFactory::createWindow(){
	return new SDLWindow();
}*/


