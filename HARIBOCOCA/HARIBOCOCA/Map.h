#pragma once
#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "Setup.h"
#include "Init.h"

struct Map
{
	int Tile_map[MAP_HEIGHT][MAP_WIDTH];
	SDL_Texture* Tile_texture[4] = { NULL, NULL, NULL, NULL };
	SDL_Rect src = { 0,0,TILE_SIZE, TILE_SIZE };
	SDL_Rect dst;
	void Loadtiles(SDL_Renderer* renderer);
	void DrawMap(SDL_Renderer* renderer);
	void ClearMap();
};



#endif // MAP_H_INCLUDED
