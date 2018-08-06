#include "SDLAbstractFactory.h"
using namespace Graphics;

SDLAbstractFactory::~SDLAbstractFactory(){}
SDLAbstractFactory::SDLAbstractFactory(){}

Player* SDLAbstractFactory::createPlayer(){
	return new SDLPlayer();
}

Window* SDLAbstractFactory::createWindow(){
	return new SDLWindow();
}


