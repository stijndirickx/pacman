#include "GameContext.h"

namespace PACMAN {
	GameContext::GameContext() {
		this->GetHighscore();
	}

	GameContext::~GameContext() {

	}

	int GameContext::GetLives(){
		return lives;
	}


	int GameContext::SubtractLives(int subtraction){
		lives = lives - subtraction;
		return lives;
	}

	int GameContext::SetLives(int numOfLives){
		lives = numOfLives;
		return lives;
	}

	bool GameContext::GetPlaying(){
		return playing;
	}

	bool GameContext::SetPlaying(bool play, string text){
		if(lives <= 0){
			playing = false;
			startText = "Game Over";
			if(score > highScore){
				this->SetHighscore(score);
			}
		} else {
			playing = play;
			startText = text;
		}
		return playing;
	}

	int GameContext::GetScore(){
		return score;
	}

	int GameContext::AddToScore(int addition){
		score = score + addition;
		return score;
	}

	int GameContext::SetScreenWidth(int sWidth){
		screenWidth = sWidth;
		return screenWidth;
	}
	int GameContext::SetScreenHeight(int sHeight){
		screenHeight = sHeight;
		return screenHeight;
	}

	int GameContext::GetScreenWidth(){
		return screenWidth;
	}

	int GameContext::GetScreenHeight(){
		return screenHeight;
	}

	int GameContext::SetTotalTiles(int totalTiles){
		numOfTiles = totalTiles;
		return numOfTiles;
	}
	int GameContext::GetTotalTiles(){
		return numOfTiles;
	}

	int GameContext::SetTileSize(int size){
		tileSize = size;
		return tileSize;
	}

	int GameContext::GetTileSize(){
		return tileSize;
	}

	void GameContext::ResetGame(){
		score = 0;
		startText = "Start again";
	}

	bool GameContext::CheckCollision(int* entityBox, int* tileBox){
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		leftA = entityBox[0];
		rightA = entityBox[0] + entityBox[2]; // + width
		topA = entityBox[1];
		bottomA = entityBox[1] + entityBox[3]; // + height

		leftB = tileBox[0];
		rightB = tileBox[0] + tileBox[2]; // + width
		topB = tileBox[1];
		bottomB = tileBox[1] + tileBox[3]; // + height

		if( rightA > leftB && leftA < rightB && topA < bottomB && bottomA > topB)
		{
			return true;
		}

		return false;
	}

	void GameContext::AddGhost(Ghost* ghost){
		ghosts.push_back(ghost);
	}

	std::vector<Ghost*> GameContext::GetGhosts(){
		return ghosts;
	}

	void GameContext::SetMap(Map* map){
		tileMap = map;
	}

	Tile** GameContext::GetMapTiles() {
		return tileMap->GetTiles();
	}

	void GameContext::DestroyTile(int tile){
		tileMap->DestroyTile(tile);
	}

	int GameContext::SetHighscore(int hscore){
		highScore = hscore;
		hs.open("Assets/highscore.ini", std::ios::out);
		hs << hscore;
		hs.close();
		return highScore;
	}

	int GameContext::GetHighscore(){
		hs.open("Assets/highscore.ini", std::ios::in);
		hs >> highScore;
		hs.close();
		return highScore;
	}

	int GameContext::SetNumOfGhosts(int nrGhosts){
		numOfGhosts = nrGhosts;
		return numOfGhosts;
	}

	int GameContext::GetNumOfGhosts(){
		return numOfGhosts;
	}
}
