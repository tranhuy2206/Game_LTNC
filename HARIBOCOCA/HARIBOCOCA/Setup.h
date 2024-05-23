#pragma once
#ifndef SETUP_H_INCLUDED
#define SETUP_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 768;
#define MAX_TILES 2
#define TILE_SIZE 64
#define MAP_WIDTH 20
#define MAP_HEIGHT 12
#define BLANK_TILE 1
#define VELOCITY 1
#define JUMP_VELO 10
#define HEIGHT_FRAME 54
#define WIDTH_FRAME 54
#define MONSTER_FRAME 5
#define PLAYER_FRAME 5

const int PLAYER_SPRITE[][8] =
{
	{0,0,54,54},
	{54,0,54,54},
	{54 * 2,0,54,54},
	{54 * 3,0,54,54},
	{54 * 4,0,54,54},
	{54 * 5,0,54,54},
	{54 * 6,0,54,54},
	{54 * 7,0,0,54},
};



const int BOSS_SPIRTE[][6] =
{
	{0,0,75,75},
	{75,0,75,75},
	{75 * 2,0,75,75},
	{75 * 3,0,75,75},
	{75 * 4,0,75,75},
	{75 * 5,0,75,75},
};

namespace Cross_account
{
	bool CheckTwoObj(const SDL_Rect& obj_1, const SDL_Rect& obj_2);
}

#endif // !SETUP_H_INCLUDED
