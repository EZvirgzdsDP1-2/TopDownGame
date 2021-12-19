#include "EnemyObject.h"

#include "TextureManager.h"



EnemyObject::EnemyObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

	m_CoordinatesX = x;
	m_CoordinatesY = y;
}

EnemyObject::~EnemyObject()
{
}

void EnemyObject::passPlayerCoord(int* x, int* y)
{
	m_playerCoordinatesX = *x;
	m_playerCoordinatesY = *y;
}

SDL_Rect EnemyObject::getEnemyRect()
{
    return m_destRect;
}



void EnemyObject::enemyMovement()
{
    if (m_CoordinatesX < m_playerCoordinatesX) {
        m_CoordinatesX += 2;
    }
    if (m_CoordinatesX > m_playerCoordinatesX) {
        m_CoordinatesX -= 2;
    }
    if (m_CoordinatesY > m_playerCoordinatesY) {
        m_CoordinatesY -= 2;
    }
    if (m_CoordinatesY < m_playerCoordinatesY) {
        m_CoordinatesY += 2;
    }
    

    m_srcRect.h = 65;
    m_srcRect.w = 65;
    m_srcRect.x = 0;
    m_srcRect.y = 0;

    m_destRect.x = m_CoordinatesX;
    m_destRect.y = m_CoordinatesY;
    m_destRect.w = m_srcRect.w;
    m_destRect.h = m_srcRect.h;

}

void EnemyObject::enemyUpdate()
{
	m_Delta_x = m_CoordinatesX - m_playerCoordinatesX;
	m_Delta_y = m_CoordinatesY - m_playerCoordinatesY;

	m_enemyAngle = (atan2(m_Delta_y, m_Delta_x) * 180.0000) / 3.14159265;
    
    enemyMovement();
}

void EnemyObject::enemyRender()
{
	SDL_RenderCopyEx(renderer, objTexture, &m_srcRect, &m_destRect, m_enemyAngle, &m_enemyCenter, SDL_FLIP_NONE);

    SDL_RenderPresent(renderer);
}

void EnemyObject::deleteEnemyTexture()
{
    SDL_DestroyTexture(objTexture);
}
