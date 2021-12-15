#pragma once

#include "app.h"

class GameObject
{
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();


	void characterMovement();
	void mousePosition();
	void update();
	void render();
};

