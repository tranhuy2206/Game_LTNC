#include "Bomb.h"

void Bomb::DrawBomb(SDL_Texture* bomb,SDL_Renderer* render, int pl_x, int pl_y)
{
	SDL_Rect dst;
	dst.x = pl_x;
	dst.y = pl_y;

	SDL_QueryTexture(bomb, NULL, NULL, &dst.w, &dst.h);

	SDL_RenderCopy(render, bomb, NULL, &dst);
}

void Bomb::UpdatePos(int x, int y)
{
	temp_pl_x = x;
	temp_pl_y = y;
}

Uint32 ExplosionCallback(Uint32 interval, void* param)
{
	return 0;
}

void Bomb::Explosion()
{
	const Uint32 explosionTime = 5000;
	SDL_TimerID timerID = SDL_AddTimer(explosionTime, ExplosionCallback, nullptr);
	
}

