#include "AbstractFactory.h"

namespace logic
{
	AbstractFactory::AbstractFactory()
	{
		house = NULL;
		config = NULL;
		context = NULL;
	}

	AbstractFactory::~AbstractFactory()
	{
		delete house;
		delete context;
		delete config;
	}

	Config* AbstractFactory::createConfig()
	{
		config = new Config();
		return config;
	}

	House* AbstractFactory::createHouse()
	{
		house = new House(this, config->getMapFile(), config->getBrickSize());
		this->createSDLHelper();
		house->createHouse();
		return house;
	}
}
