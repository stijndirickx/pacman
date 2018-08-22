#include "AbstractFactory.h"

namespace logic
{
	AbstractFactory::AbstractFactory()
	{
		mConfig = NULL;
		mContext = NULL;
		mHouse = NULL;
	}

	AbstractFactory::~AbstractFactory()
	{
		delete mConfig;
		delete mContext;
		delete mHouse;
	}

	Config* AbstractFactory::getConfig()
	{
		mConfig = new Config();
		return mConfig;
	}

	House* AbstractFactory::getHouse()
	{
		mHouse = new House(this, mConfig->getFileName(), mConfig->getBrickSize());
		this->createVisualization();
		mHouse->createHouse();
		return mHouse;
	}
}

