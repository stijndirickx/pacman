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
		int vulnerableTime = 0;
		bool quit = false;

		while(!quit) // Start of gameloop
		{

			// 1. Get user input
			while(eventHandler->pollEvent() != 0)
			{
				quit = eventHandler->quitEvent(); // User requests quit
				if(eventHandler->keyDown()) //getting user input (arrow keys or space)
				{
					if(eventHandler->getKeyDown() == 6) //pressed space
					{
						//if(house->getNumOfPlus() > 0)
						//{
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
						//}
					}
					else if (context->getPlaying()) //change direction with arrow key
					{
						player->setDirection(eventHandler->getKeyDown());
					}
				}
			} // --- end of user input ---



			// 2. --- How long enemies are vulnerable ---
			for(int j = 0; j < numOfEnemies; j++){
				if(!enemies[j]->getAttackingState())
				{
					if(vulnerableTime == 0)
					{
						vulnerableTime = context->getVulnerableTime() / timePerFrame;
					}
					else if(vulnerableTime == 1)
					{
						enemies[j]->setAttackingState(true);
					}
				}
			} // --- end 2



			// 3. --- Level is cleared, go to next level---
			if(house->getNumOfPlus() == 0)
			{
				context->nextLevel();
				context->setPlaying(false, "level " + std::to_string(context->getLevel()));
				house->resetNumOfPlus();
				for(int i=0; i< numOfEnemies;i++)
				{
					enemies[i]->reset();
				};
				house->load();
				player->reset();
			} // --- end 3



			// 4. --- Check if extra life can be given ---
			if(!context->isExtraLiveGiven() && context->getScore() >= 10000)
			{
				context->addToLives(1);
				context->playSound(0);
			} // --- end 4



			// 5. --- Timing
			ticks = clock(); //#clock ticks since running
			clock_ms = (ticks/(double)CLOCKS_PER_SEC)*1000.0; //#ms since running

			if(last_frame != clock_ms && clock_ms % timePerFrame == 0)
			{
				last_frame = clock_ms; //make sure not multiple frames in same ms
				context->clearScreen();
				house->paint();

				if(context->getPlaying()) //Playing --- move the entities
				{
					player->move();
					player->gotHit(enemies, numOfEnemies);
					for(int i=0; i < numOfEnemies;i++)
					{
						enemies[i]->move(player->getX(), player->getY());
					}
					context->playMusic(2); //Playing music
				}
				else // Paused --- paint entities
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

				if(vulnerableTime > 0)
				{
					vulnerableTime--;
					if(vulnerableTime <= 30 && clock_ms % (fpa*timePerFrame) == 0)
					{
						for(int i=0; i < numOfEnemies;i++)
						{
							enemies[i]->setFlashingState(!enemies[i]->getFlashingState());
						}
					}
				}

				context->updateText();
				context->updateScreen();
			} // 5. --- End of timing ---


		} // End of game loop


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
