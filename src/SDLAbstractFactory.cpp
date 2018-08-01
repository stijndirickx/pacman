#include "SDLAbstractFactory.h"
using namespace Graphics;

SDLAbstractFactory::~SDLAbstractFactory(){}
SDLAbstractFactory::SDLAbstractFactory(){}

Player* SDLAbstractFactory::createPacman(){
	return new SDLPlayer();
}


