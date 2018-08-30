#ifndef HOUSE_H_
#define HOUSE_H_

#include <fstream>

#include "AbstractFactory.h"
#include "Brick.h"
#include "Context.h"

using namespace std;

namespace logic
{
	class AbstractFactory;
	class Context;
	class House
	{
		public:
			House(AbstractFactory* pAbstractFactory, string mapName, int pBrickSize);
			virtual ~House();

			void setContext(Context* pContext);
			void paint();
			Brick** getBricks();
			void destroyBrick(int brickId);
			void load();
			void createHouse();
			int getwindowWidth();
			int getwindowHeight();
			int getNumOfPlus();


		protected:
			Context* mContext = NULL;

			int totalBricks;
			Brick** bricks = 0;
			int* destroyedBricks = 0;


			int numOfPlus = 0;
			AbstractFactory* mAbstractFactory = NULL;
			std::ifstream file;

			int windowWidth;
			int windowHeight;
			int mBrickSize;
	};
}

#endif
