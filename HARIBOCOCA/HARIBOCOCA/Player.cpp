#include "Setup.h"
#include "Player.h"
#include "iostream"


void Player::CLearPlayer(SDL_Texture* pl_tex)
{
	SDL_DestroyTexture(pl_tex);
}