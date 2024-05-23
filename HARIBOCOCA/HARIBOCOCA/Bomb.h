#pragma once
#ifndef BOMB_H_INCLUDED
#define BOMB_H_INCLUDED
#include "Setup.h"
#include "Init.h"

class Bomb
{
public:
	void DrawBomb(SDL_Texture* bomb,SDL_Renderer* render, int pl_x, int pl_y);
	void UpdatePos(int x, int y);
	void Explosion();

	int temp_pl_x;
	int temp_pl_y;
};

#endif 
