#pragma once

#include "App.h"

class EnemyObject
{
private:
	int m_CoordinatesX;
	int m_CoordinatesY;

	int m_playerCoordinatesX;
	int m_playerCoordinatesY;

	double m_enemyAngle{};

	int m_Delta_x{ 0 };
	int m_Delta_y{ 0 };

	SDL_Point m_enemyCenter{ 30, 30 };

	SDL_Texture* objTexture;
	SDL_Rect m_srcRect, m_destRect;
	SDL_Renderer* renderer;
public:
	EnemyObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~EnemyObject();

	void passPlayerCoord(int *x,int *y);

	void enemyMovement();
	void enemyUpdate();
	void enemyRender();
};

