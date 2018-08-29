#include "SDLAbstractFactory.h"

namespace graphics_SDL
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

	Brick* SDLAbstractFactory::createBrick(int x, int y, int size, int type)
	{
		Brick* brick = new SDLBrick(helper->getRenderer(), helper->getBrickTexture());
		brick->renderBrick(x, y, size, type);
		return brick;
	}

	void SDLAbstractFactory::createVis()
	{
		helper = new SDLHelper(house->getwindowWidth(), house->getwindowHeight(), config->getSpritesFile());
	}

	Context* SDLAbstractFactory::createContext()
	{
		context = new SDLContext(helper);
		context->setHouse(house);
		house->setContext(context);
		return context;
	}

	EventHandler* SDLAbstractFactory::createEventHandler()
	{
		EventHandler* eventHandler = new SDLEventHandler();
		return eventHandler;
	}
}
