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
			while(eventHandler->pollEvent() != 0) //get event
			{
				quit = eventHandler->quitEvent(); // User requests quit
				if(eventHandler->keyDown()) //getting user input (arrow keys or space)
				{
					if(eventHandler->getKeyDown() == 6) //pressed space
					{
						if(house->getNumOfPlus() > 0)
						{
							context->setPlaying(!context->getPlaying(), "waiting..."); //Switch pause/unpause

							if(!player->getAliveState()) //Player got killed and is waiting for pause to restart new life
							{
								player->reset();
								for(int i=0; i < numOfEnemies;i++)
								{
									enemies[i]->reset();
								}
								if(context->getLives() <= 0) //Player lost
								{
									context->resetGame(); //set score to 0 and changes displaytext
									context->setLives(config->getLivesCount()); //gets his lives
									house->load();	//reload the house
								}
							}
						}
						else //All plus where taken TODO
						{
							for(int i=0; i< numOfEnemies;i++)
							{
								enemies[i]->reset();
								enemies[i]->speedUp(1.1);
							};
							house->load();
							player->reset();
							context->setPlaying(true, "");
						}
					}
					else if (context->getPlaying()) //change direction with arrow key
					{
						player->setDirection(eventHandler->getKeyDown());
					}
				}
			} //end of second while

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

			if(house->getNumOfPlus() == 0)
			{
				context->setPlaying(false, "all cleared");
			}

			if(!context->isExtraLiveGiven() && context->getScore() >= 10000)
			{
				context->addToLives(1);
				context->playSound(0); //TODO doesnt seem to work
			}

			ticks = clock(); //#clock ticks since running
			clock_ms = (ticks/(double)CLOCKS_PER_SEC)*1000.0; //#ms since running

			if(last_frame != clock_ms && clock_ms % timePerFrame == 0)
			{
				last_frame = clock_ms; //make sure not multiple frames in same ms

				context->clearScreen();
				house->paint();

				if(context->getPlaying()) //Playing
				{
					player->move();
					player->gotHit(enemies, numOfEnemies);
					for(int i=0; i < numOfEnemies;i++)
					{
						enemies[i]->move(player->getX(), player->getY());
					}
					context->playMusic(2); //Playing music
				}
				else //Paused
				{
					player->paint();
					for(int i=0; i < numOfEnemies;i++)
					{
						enemies[i]->paint();
					}
					context->playMusic(3); //Pause music
				}

				if(clock_ms % (fpa*timePerFrame) == 0) //every x frames animation
				{
					player->animate();
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
