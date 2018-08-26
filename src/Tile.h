#ifndef TILE_H_
#define TILE_H_

#include <iostream>

using namespace std;

namespace PACMAN
{
	class Tile
	{
		public:
			Tile();
			virtual ~Tile();
			void SetTileType(int type);
			int* GetBoxInt();
			void RenderTile(int x, int y, int tileType, int width, int height);
			virtual void Visualize() = 0;

		protected:
			int boxInt [5];
	};
}
#endif
