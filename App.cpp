#include "App.h"

#include "TextureManager.h"
#include "GameObject.h"
#include "EnemyObject.h"

#include "forwardDeclerations.h"

GameObject* player;
EnemyObject* enemy;


void App::init(const char* title, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenWidth, m_screenHeight, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			//SDL_SetRenderDrawColor(renderer, 3, 156, 90, 55);
			
			backgroundImage = IMG_Load("assets/background.png");
			backgroundSurface = SDL_CreateTextureFromSurface(renderer, backgroundImage);
		}

		isRunning = true;
	}
	
	player = new GameObject("assets/redditor.png", renderer, 0, 0);
	enemy = new EnemyObject("assets/dumbshit.png", renderer, getRandomNumber(100, 1400), getRandomNumber(800,1000));
}

void App::runApp()
{
	frameStart = SDL_GetTicks();

	handleEvent();
	update();
	render();

	frameTime = SDL_GetTicks() - frameStart;

	if (frameDelay > frameTime)
	{
		SDL_Delay(frameDelay - frameTime);
	}
}


void App::update()
{
	
	
	player->update();
	player->getPlayerLocation(&playerX, &playerY);
	
	enemy->passPlayerCoord(&playerX, &playerY);
	enemy->enemyUpdate();


	checkCollision();
}

void App::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundSurface, NULL, NULL);

	player->render();
	
	enemy->enemyRender();
	

	SDL_RenderPresent(renderer);
}

void App::clean()
{
	SDL_DestroyWindow(window);
	SDL_FreeSurface(backgroundImage);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}



void App::handleEvent()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void App::checkCollision()
{
	SDL_Rect tempEnemyRect = enemy->getEnemyRect();
	SDL_Rect tempPlayerRect = player->getPlayerRect();
	
	
	SDL_bool collision = SDL_HasIntersection(&tempEnemyRect, &tempPlayerRect);

	if (collision)
	{
		player->deletePlayerTexture();
		enemy->deleteEnemyTexture();
	}
}

App::App()
{
}

App::~App()
{
}