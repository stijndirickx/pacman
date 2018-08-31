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

	Brick* SDLAbstractFactory::createBrick(int x, int y, int size, int type)
	{
		Brick* brick = new SDLBrick(helper->getRenderer(), helper->getBrickTexture());
		brick->renderBrick(x, y, size, type);
		return brick;
	}

	Context* SDLAbstractFactory::createContext()
	{
		context = new SDLContext(helper);
		context->setHouse(house);
		house->setContext(context);
		return context;
	}

	Enemy* SDLAbstractFactory::createEnemy(int type)
	{
		Enemy* enemy = new SDLEnemy(type, helper->getRenderer(), helper->getSurface());
		enemy->setAbstractFactory(this);
		enemy->setContext(context);
		context->addEnemy(enemy);
		return enemy;
	}

	EventHandler* SDLAbstractFactory::createEventHandler()
	{
		EventHandler* eventHandler = new SDLEventHandler();
		return eventHandler;
	}

	Player* SDLAbstractFactory::createPlayer()
	{
		Player* player = new SDLPlayer(helper->getRenderer(), helper->getSurface());
		player->setAbstractFactory(this);
		player->setContext(context);
		return player;
	}

	void SDLAbstractFactory::createSDLHelper()
	{
		helper = new SDLHelper(house->getwindowWidth(), house->getwindowHeight(), config->getSpritesFile());
	}
}
