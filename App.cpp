#include "App.h"

#include "TextureManager.h"
#include "GameObject.h"
GameObject* player;
EnemyGameObject* enemy;



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
			SDL_SetRenderDrawColor(renderer, 3, 156, 90, 55);
		}

		isRunning = true;
	}
	
	player = new GameObject("assets/redditor.png", renderer, 0, 0);
	enemy = new EnemyGameObject("assets/dumbshit.png", renderer, 1000, 0);
	
	
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

	player->playerUpdate();
	enemy->enemyUpdate();
	
	
}

void App::render()
{
	SDL_RenderClear(renderer);
	player->playerRender();
	enemy->enemyRender();
	

	SDL_RenderPresent(renderer);
}

void App::clean()
{
	SDL_DestroyWindow(window);
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
	}

}

App::App()
{
}

App::~App()
{
}