#include "Game.h"
#include <fstream>

namespace logic
{
	Game::Game(AbstractFactory*& pAbstractFactory)
	{
		mAbstractFactory = pAbstractFactory;
		config = mAbstractFactory->createConfig();
	}

	Game::~Game(){}

	void Game::start()
	{
		EventHandler* eventHandler = mAbstractFactory->createEventHandler();
		House* house = mAbstractFactory->createHouse();
		Context* context = mAbstractFactory->createContext();

		//Set data from config file
		context->setBrickSize(config->getBrickSize());
		context->setLives(config->getLivesCount());

		//Create player + set its speed
		Player* player = mAbstractFactory->createPlayer();
		player->setSpeed(config->getPlayerSpeed());

		//Create enemies + their speed
		int numOfEnemies = config->getEnemiesCount();
		context->setNumOfEnemies(numOfEnemies);
		Enemy* enemies[numOfEnemies];
		for(int i = 0; i < numOfEnemies; i++)
		{
			enemies[i] = mAbstractFactory->createEnemy(i);
			enemies[i]->setSpeed(config->getEnemySpeed());
		}


		// Timing
		int fpa = config->getFpa(); // frames per animationSprite
		int timePerFrame = 1000/config->getFps(); // in ms
		int last_frame = 0;
		clock_t ticks = 0;
		int clock_ms = 0; //clock in ms
		int countingAttack = 0;
		bool quit = false;

		while(!quit) // Start of gameloop
		{
			while(eventHandler->pollEvent() != 0)
			{
				//User requests quit
				if(eventHandler->quitEvent())
				{
					quit = true;
				}
				else if(eventHandler->keyDown())
				{
					if(eventHandler->getKeyDown() == 6) //pressed space
					{
						if(house->getNumOfPlusLeft() > 0)
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
									context->setLives(config->getLivesCount());
									house->load();
								}
								player->setDirection(4);
							}
						}
						else
						{
							house->load();
							player->setAliveState(true);
							player->setDirection(4);
							context->setPlaying(true, "Paused");
						}
					}
					else if (context->getPlaying()) //not changing direction while paused
					{
						player->setDirection(eventHandler->getKeyDown());
					}
				}
			}

			if(!enemies[0]->getAttackingState()) //if ghosts vulnerable
			{
				if(countingAttack == 0)
				{
					countingAttack = 8000 / timePerFrame; //8s
				}
				else if(countingAttack == 1)
				{
					for(int j=0; j < numOfEnemies;j++) // set ghosts back to attacking
					{
						enemies[j]->setAttackingState(true);
					}
				}
			}

			if(house->getNumOfPlusLeft() == 0)
			{
				context->setPlaying(false, "Winner");
			}

			ticks = clock(); //#clock ticks since running
			clock_ms = (ticks/(double)CLOCKS_PER_SEC)*1000.0; //#ms since running

			if(last_frame != clock_ms && clock_ms % timePerFrame == 0)
			{
				last_frame = clock_ms; //make sure not multiple frames in same ms

				context->clearScreen();
				house->paint();
				if(context->getPlaying())
				{
					player->move();
					enemies[0]->moveTo(player->getX(), player->getY());
					enemies[1]->moveInFront(player->getX(), player->getY());
					player->gotHit(enemies, numOfEnemies);
					for(int j=2; j < numOfEnemies;j++)
					{
						enemies[j]->move();
					}
					context->playMusic(2);
				}
				else
				{
					player->paint();
					for(int j=0; j < numOfEnemies;j++)
					{
						enemies[j]->paint();
					}
					context->playMusic(1);
				}

				if(clock_ms % (fpa*timePerFrame) == 0) //every x frames animation
				{
					player->animate();
					//TODO enemies too
				}

				if(countingAttack > 0)
				{
					countingAttack--;
					if(countingAttack <= 30 && clock_ms % (fpa*timePerFrame) == 0)
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
		delete context;
		delete player;
		delete eventHandler;
	}
}
