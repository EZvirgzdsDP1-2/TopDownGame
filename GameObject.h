#pragma once

#include "app.h"

class GameObject
{
private:
	int Pxpos;
	int Pypos;
	int Expos;
	int Eypos;

	SDL_Rect EsrcRect, EdestRect;
	SDL_Texture* objTexture;
	SDL_Rect PsrcRect, PdestRect;
	SDL_Renderer* renderer;
public:

	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void playerMovement();
	void mousePosition();
	void playerUpdate();
	void playerRender();
};
class EnemyGameObject {
private:
	int Pxpos;
	int Pypos;
	int Expos;
	int Eypos;

	SDL_Rect EsrcRect, EdestRect;
	SDL_Texture* objTexture;
	SDL_Rect PsrcRect, PdestRect;
	SDL_Renderer* renderer;
public:
	EnemyGameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	void enemyRender();
	void enemyUpdate();
	void enemyMovement();
};