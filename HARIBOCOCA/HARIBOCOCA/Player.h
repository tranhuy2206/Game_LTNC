#pragma once
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Setup.h"


class Player
{
public:
	int pl_x = TILE_SIZE*0;
	int pl_y = TILE_SIZE*11;
	int get_pl_x() const { return pl_x; };
	int get_pl_y() const { return pl_y; };
	void CLearPlayer(SDL_Texture* pl_tex);
};

#endif // !PLAYER_H_INCLUDED
