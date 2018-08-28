#include "SDLAbstractFactory.h"

namespace PACMAN
{
	SDLAbstractFactory::SDLAbstractFactory()
	{
		helper = NULL;
	}

	SDLAbstractFactory::~SDLAbstractFactory()
	{
		delete helper;
	}

	Enemy* SDLAbstractFactory::createEnemy(int type)
	{
		Enemy* enemy = new SDLEnemy(type, helper->getRenderer(), helper->getSurface());
		enemy->setAbstractFactory(this);
		enemy->setContext(context);
		context->addEnemy(enemy);
		return enemy;
	}

	Player* SDLAbstractFactory::createPlayer()
	{
		Player* player = new SDLPlayer(helper->getRenderer(), helper->getSurface());
		player->setAbstractFactory(this);
		player->setContext(context);
		return player;
	}

	Brick* SDLAbstractFactory::createBrick(int x, int y, int type, int width, int height)
	{
		Brick* brick = new SDLBrick(helper->getRenderer(), helper->getBrickTexture());
		brick->renderTile(x, y, type, width, height);
		return brick;
	}

	void SDLAbstractFactory::createVis()
	{
		helper = new SDLHelper(house->getScreenWidth(), house->getScreenHeight(), config->getSpritesFile());
	}

	Context* SDLAbstractFactory::createContext()
	{
		context = new SDLContext(helper);
		context->setMap(house);
		house->setContext(context);
		return context;
	}

	EventHandler* SDLAbstractFactory::createEventHandler()
	{
		EventHandler* ev = new EventHandlerSDL();
		return ev;
	}
}
