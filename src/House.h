#ifndef HOUSE_H_
#define HOUSE_H_

#include <fstream>

#include "AbstractFactory.h"
#include "Brick.h"
#include "Context.h"

using namespace std;

namespace logic
{
	class AbstractFactory; //TO USE
	class Context;
	class House
	{
		public:
			House(AbstractFactory* abstractFactory, string mapName, int tileSize);
			virtual ~House();

			void setContext(Context* pContext);
			void draw();
			Brick** getBricks();
			void destroyBrick(int brickId);
			void load();
			void createMap();
			int getwindowWidth();
			int getwindowHeight();
			int getNumOfPellets();


		protected:
			Context* mContext;

			int totalBricks;
			//TODO tile array variable size
			Brick** bricks = new Brick*[911]; //** --> Cannot instantiate abstract object
			int* destroyedBricks = new int [911];
			int numOfPellets;
			int numOfPelletsLeft;
			AbstractFactory* aFactory = NULL;
			std::ifstream map;

			int windowWidth;
			int windowHeight;
			int tileSize;
	};
}

#endif
