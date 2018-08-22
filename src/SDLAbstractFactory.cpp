#include "SDLAbstractFactory.h"

namespace graphics_SDL
{
	SDLAbstractFactory::SDLAbstractFactory()
	{
		mSDLHelper = NULL;
	}

	SDLAbstractFactory::~SDLAbstractFactory()
	{
		delete mSDLHelper;
	}

	Brick* SDLAbstractFactory::createBrick(int x, int y, int width, int height, int type)
	{
		Brick* brick = new SDLBrick(mSDLHelper->getRenderer(), mSDLHelper->getTexture());
		brick->createBrick(x, y, width, height, type);
		return brick;
	}

	Context* SDLAbstractFactory::createContext()
	{
		mContext = new SDLContext(mSDLHelper);
		mContext->setHouse(mHouse);
		mHouse->setContext(mContext);
		return mContext;
	}

	Enemy* SDLAbstractFactory::createEnemy(int type)
	{
		Enemy* enemy = new SDLEnemy(mSDLHelper->getRenderer(), mSDLHelper->getSurface(), type);
		enemy->setAbstractFactory(this);
		enemy->setContext(mContext);
		mContext->addEnemy(enemy);
		return enemy;
	}

	EventHandler* SDLAbstractFactory::createEventHandler()
	{
		EventHandler* eventHandler = new SDLEventHandler();
		return eventHandler;
	}

	Player* SDLAbstractFactory::createPlayer()
	{
		Player* player = new SDLPlayer(mSDLHelper->getRenderer(), mSDLHelper->getSurface());
		player->setAbstractFactory(this);
		player->setContext(mContext);
		return player;
	}

	void SDLAbstractFactory::createVisualization()
	{
		mSDLHelper = new SDLHelper(mHouse->getScreenWidth(), mHouse->getScreenHeight());
	}
}




