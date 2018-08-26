#ifndef GAMECONTEXT_H_
#define GAMECONTEXT_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "Ghost.h"
#include "Map.h"

using namespace std;

namespace PACMAN
{
	class Ghost;
	class Map;
	class GameContext
	{
		public:
			GameContext();
			virtual ~GameContext();

			int GetLives();
			int SubtractLives(int subtraction);
			int SetLives(int numOfLives);
			bool GetPlaying();
			bool SetPlaying(bool play, string text);
			int GetScore();
			int AddToScore(int addition);
			int SetScreenWidth(int sWidth);
			int SetScreenHeight(int sHeight);
			int GetScreenWidth();
			int GetScreenHeight();
			int SetTotalTiles(int totalTiles);
			int GetTotalTiles();
			int SetTileSize(int size);
			int GetTileSize();
			void ResetGame();
			bool CheckCollision(int* a, int* b);
			void AddGhost(Ghost* ghost);
			std::vector<Ghost*> GetGhosts();
			void SetMap(Map* map);
			Tile** GetMapTiles();
			void DestroyTile(int tile);
			int SetHighscore(int score);
			int GetHighscore();
			int SetNumOfGhosts(int nrGhosts);
			int GetNumOfGhosts();

			virtual void UpdateText() = 0;
			virtual void PlaySound(string sound) = 0;
			virtual void ClearScreen() = 0;
			virtual void UpdateScreen() = 0;
			virtual void QuitVis() = 0;

		protected:
			int screenWidth = 0;
			int screenHeight = 0;
			int numOfTiles = 0;
			int numOfGhosts = 0;
			std::vector<Ghost*> ghosts;
			Map* tileMap = NULL;
			std::fstream hs;

			int highScore = 0;
			int score = 0;
			bool playing = false;
			string startText = "Start";

			int tileSize = 20;
			int lives = 3;
	};
}

#endif
