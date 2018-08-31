#ifndef HOUSE_H_
#define HOUSE_H_

#include "AbstractFactory.h"

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

			void createHouse();
			void load();
			void paint();

			Brick** getBricks();
			void destroyBrick(int brickId);

			int getNumOfPlus();
			void resetNumOfPlus();
			int getwindowHeight();
			int getwindowWidth();

		protected:
			AbstractFactory* mAbstractFactory = NULL;
			std::ifstream file;
			int mBrickSize;

			Context* mContext = NULL;

			int totalBricks;
			Brick** bricks = 0;
			int* destroyedBricks = 0;

			int maxNumOfPlus = 0;
			int numOfPlus = 0;
			int windowWidth;
			int windowHeight;
	};
}

#endif
