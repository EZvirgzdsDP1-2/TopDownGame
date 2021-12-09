#include "App.h"

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
	
	SDL_Surface* tempSurface = IMG_Load("assets/redditor.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);

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
	destR.h = 512;
	destR.w = 512;
	destR.x = 428;
	destR.y = 120;
}

void App::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTexture, nullptr, &destR);
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
	default:
		break;
	}
}

App::App()
{
}

App::~App()
{
}