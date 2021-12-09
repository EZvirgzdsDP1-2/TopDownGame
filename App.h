#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class App
{
private:
	const int m_screenWidth{1280};
	const int m_screenHeight{720};

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	bool isRunning{ false };

	SDL_Texture* playerTexture;
	SDL_Rect srcR, destR;

	SDL_Surface* tempSurface = IMG_Load("assets/redditor.png");

	SDL_Window* window;

	SDL_Renderer* renderer;


	void update();
	void render();
	void handleEvent();

public:
	bool runningStatus() { return isRunning; }
	
	void init(const char* title, bool fullscreen);
	
	App();
	~App();

	void runApp();

	void clean();
};

