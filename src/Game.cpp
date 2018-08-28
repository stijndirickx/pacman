#include "Game.h"
#include <fstream>

namespace PACMAN
{
	Game::Game(AbstractFactory*& abstractFactory)
	{
		aFactory = abstractFactory;

		cFile = aFactory->createConfig();
		numOfEnemies = cFile->getEnemiesCount();
		animationSpeed = cFile->getFpa(); //every x frames sprite change
		fps = cFile->getFps();
		mspf = 1000/fps; //ms per f: 30FPS --> every 33.3 ms a frame
		countToAttacking = 8000 / mspf; // 8 sec / ms per frame = # frames to go
	}

	Game::~Game(){}

	void Game::start()
	{
		House* map = aFactory->createHouse();
		Context* context = aFactory->createContext();
		context->setTileSize(cFile->getBrickSize());
		context->setLives(cFile->getLivesCount());
		context->setNumOfEnemies(numOfEnemies);

		Player* player = aFactory->createPlayer();
		player->setSpeed(cFile->getPlayerSpeed());
		Enemy* enemies[numOfEnemies];
		for(int i = 0; i < numOfEnemies; i++)
		{
			enemies[i] = aFactory->createEnemy(i);
		}

		EventHandler* ev = aFactory->createEventHandler();
		int last_frame = 0;
		clock_t ticks = 0;
		int clock_ms = 0; //clock in ms
		int countingAttack = 0;
		bool quit = false;

		while(!quit)
		{
			while(ev->PollEvent() != 0)
			{
				//User requests quit
				if(ev->QuitEvent())
				{
					quit = true;
				}
				else if(ev->KeyDown())
				{
					if(ev->GetKeyDown() == 6) //pressed enter
					{
						if(map->getNumOfPellets() > 0)
						{
							context->setPlaying(!context->getPlaying(), "Paused");
							if(!player->getAliveState())
							{
								player->setAliveState(true);
								for(int j=0; j < numOfEnemies;j++)
								{
									enemies[j]->resetEnemy();
								}
								if(context->getLives() <= 0)
								{
									context->resetGame();
									context->setLives(cFile->getLivesCount());
									map->load();
								}
								player->setDirection(4);
							}
						}
						else
						{
							map->load();
							player->setAliveState(true);
							player->setDirection(4);
							context->setPlaying(true, "Paused");
						}
					}
					else if (context->getPlaying()) //not changing direction while paused
					{
						player->setDirection(ev->GetKeyDown());
					}
				}
			}

			if(!enemies[0]->getAttackingState()) //if ghosts vulnerable
			{
				if(countingAttack == 0)
				{
					countingAttack = countToAttacking;
				}
				else if(countingAttack == 1)
				{
					for(int j=0; j < numOfEnemies;j++) // set ghosts back to attacking
					{
						enemies[j]->setAttackingState(true);
					}
				}
			}

			if(map->getNumOfPellets() == 0)
			{
				context->setPlaying(false, "Winner");
			}

			ticks = clock(); //#clock ticks since running
			clock_ms = (ticks/(double)CLOCKS_PER_SEC)*1000.0; //#ms since running

			if(last_frame != clock_ms && clock_ms % mspf == 0)
			{
				last_frame = clock_ms; //make sure not multiple frames in same ms

				context->clearScreen();
				map->draw();
				if(context->getPlaying())
				{
					player->move();
					enemies[0]->moveTo(player->getX(), player->getY());
					enemies[1]->moveInFront(player->getX(), player->getY());
					player->gotCaptured(enemies, numOfEnemies);
					for(int j=2; j < numOfEnemies;j++)
					{
						enemies[j]->move();
					}
					context->playSound("pacman");
				}
				else
				{
					player->paint();
					for(int j=0; j < numOfEnemies;j++)
					{
						enemies[j]->paint();
					}
					context->playSound("beginning");
				}

				if(clock_ms % (animationSpeed*mspf) == 0) //every x frames animation
				{
					player->animate();
				}

				if(countingAttack > 0)
				{
					countingAttack--;
					if(countingAttack <= 30 && clock_ms % (animationSpeed*mspf) == 0)
					{
						for(int j=0; j < numOfEnemies;j++)
						{
							enemies[j]->setFlashingState(!enemies[j]->getFlashingState());
						}
					}
				}

				context->updateText();
				context->updateScreen();
			}
		}

		// Game ended
		for(int i = 0; i < numOfEnemies; i++)
		{
			delete enemies[i];
		}
		context->quitVis();
		delete player;
		delete ev;
	}
}

