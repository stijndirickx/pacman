#ifndef MAP_H_
#define MAP_H_

#include <fstream>

#include "Factory.h"
#include "Tile.h"
#include "GameContext.h"

using namespace std;

namespace PACMAN
{
	class Factory; //TO USE
	class GameContext;
	class Map
	{
		public:
			Map(Factory* abstractFactory, string mapName, int tileSize);
			void SetContext(GameContext* GameContext);
			void Draw();
			Tile** GetTiles();
			void DestroyTile(int tile);
			void Load();
			void CreateMap();
			int GetScreenWidth();
			int GetScreenHeight();
			int GetNumOfPellets();
			virtual ~Map();

		protected:
			GameContext* gContext;

			int totalTiles;
			//TODO tile array variable size
			Tile** tileSet = new Tile*[911]; //** --> Cannot instantiate abstract object
			int* destroyedTiles = new int [911];
			int numOfPellets;
			int numOfPelletsLeft;
			Factory* aFactory = NULL;
			std::ifstream map;

			int screenWidth;
			int screenHeight;
			int tileSize;
	};
}

#endif
