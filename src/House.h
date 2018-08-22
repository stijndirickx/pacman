#ifndef HOUSE_H_
#define HOUSE_H_

//#include <iostream>
#include <fstream> //TODO test this, if really needed and whats different with io

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
			House(AbstractFactory* pAbstractFactory, string pFileName, int pBrickSize);
			virtual ~House();

			void setContext(Context* pContext);
			void draw(); //?
			Brick** getBricks(); 				//** --> Pointer to pointer
			void destroyBrick(int brick);
			void load();
			void createHouse();
			int getScreenWidth();
			int getScreenHeight();
			int getNumOfPellets();

		protected:
			Context* mContext;
			int totalBricks;
			Brick** brickSet = new Brick*[911]; 	//TODO change number
			int* destroyedBricks = new int [911]; 	//TODO change number
			int numOfPellets;
			int numOfPelletsLeft;
			AbstractFactory* mAbstractFactory = NULL;
			std::ifstream stream;

			int screenWidth;
			int screenHeight;
			int mBrickSize;
	};

}

#endif
