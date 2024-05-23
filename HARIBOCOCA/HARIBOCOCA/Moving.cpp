#include "Setup.h"
#include "Moving.h"
#include "Player.h"
#include "iostream"
using namespace std;


void Move::CheckKeyBoard(SDL_Event event, int pl_x, int pl_y, vector<Bullet*>& magaz)
{

	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_d:
		{
			right = true;
			left = false;
			fire_right = true;
			fire_left = false;
			Update_Frame();

		}
		break;
		case SDLK_a:
		{
			left = true;
			right = false;
			fire_left = true;
			fire_right = false;
			Update_Frame();

		}
		break;
		case SDLK_l:
		{

			Bullet* bullet = new Bullet();
			if (fire_right)
			{
				bullet->set_direct(Bullet::bul_right);
				bullet->Set_Rect(pl_x + WIDTH_FRAME, pl_y + (HEIGHT_FRAME / 2));
			}
			else if (fire_left)
			{
				bullet->set_direct(Bullet::bul_left);
				bullet->Set_Rect(pl_x, pl_y + (HEIGHT_FRAME / 2));
			}
			bullet->set_x_bul(2);
			bullet->set_y_bul(2);
			bullet->set_move(true);

			magaz.push_back(bullet);
		}
		break;
		case SDLK_SPACE:
		{
			jump = true;
		}

		}
	}
	else if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_d:
		{
			right = false;
		}
		break;
		case SDLK_a:
		{
			left = false;
		}
		break;
		case SDLK_SPACE:
		{
			jump = false;
			on_ground = false;
		}
		break;
		}
	}
}

void Move::Firing(SDL_Renderer* render,SDL_Texture* bullet_tex, vector<Bullet*> &magaz)
{
	
	for (int i = 0; i < magaz.size(); i++)
	{
		Bullet* bullet = magaz.at(i);
		if (bullet != NULL)
		{
			if (bullet->get_mov() == true)
			{
				bullet->Fire(SCREEN_WIDTH, SCREEN_HEIGHT);
				bullet->DrawBullet(render,bullet_tex);
			}
			else
			{
				magaz.erase(magaz.begin() + i);
				if (bullet != NULL)
				{
					delete bullet;
					bullet = NULL;
				}
			}
		}
	}
}


void Move::MovePlayer()
{
	x_val = 0;
	y_val += 0.3;

	if (y_val >= 10)
	{
		y_val = 10;
	}

	if (left)
	{
		x_val -= VELOCITY;
	}
	else if (right)
	{
		x_val += VELOCITY;
	}
	else if (jump)
	{
		if (on_ground)
		{
			y_val -= JUMP_VELO;
		}
		on_ground = false;
		jump = false;
	}
}

void Move::CheckInteract(int &pl_x, int &pl_y, Map &map)
{
	
	int x1 = (pl_x + x_val) / TILE_SIZE;
	int x2 = (pl_x + x_val + WIDTH_FRAME - 1) / TILE_SIZE;

	int y1 = pl_y / TILE_SIZE;
	int y2 = (pl_y + HEIGHT_FRAME - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAP_WIDTH && y1 >= 0 && y2 < MAP_HEIGHT)
	{
		if (x_val > 0)
		{
			if (map.Tile_map[y1][x2] != BLANK_TILE || map.Tile_map[y2][x2] != BLANK_TILE)
			{
				pl_x = x2 * TILE_SIZE;
				pl_x -= WIDTH_FRAME + 1;
				x_val = 0;
			}
		}
		else if (x_val < 0)
		{
			if (map.Tile_map[y1][x1] != BLANK_TILE || map.Tile_map[y2][x1] != BLANK_TILE)
			{
				pl_x = (x1 + 1) * TILE_SIZE;
				x_val = 0;
			}
		}
	}

	x1 = pl_x / TILE_SIZE;
	x2 = (pl_x + WIDTH_FRAME) / TILE_SIZE;

	y1 = (pl_y + y_val) / TILE_SIZE;
	y2 = (pl_y + y_val + HEIGHT_FRAME - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAP_WIDTH && y1 >= 0 && y2 < MAP_HEIGHT)
	{
		if (y_val > 0)
		{
			if (map.Tile_map[y2][x1] != BLANK_TILE || map.Tile_map[y2][x2] != BLANK_TILE)
			{
				pl_y = y2 * TILE_SIZE;
				pl_y -= HEIGHT_FRAME + 1;
				y_val = 0;
				on_ground = true;
			}
		}
		else if (y_val < 0)
		{
			if (map.Tile_map[y1][x1] != BLANK_TILE || map.Tile_map[y1][x2] != BLANK_TILE)
			{
				pl_y = (y1 + 1) * TILE_SIZE;
				y_val = 0;
			}
		}
	}
	
	pl_x += x_val;
	pl_y += y_val;

}

void Move::Set_up_Frame(SDL_Texture* temp, int frames, const int _clips[][8])
{
	pl_tex = temp;
	SDL_Rect clip;
	for (int i = 0; i < frames; i++)
	{
		clip.x = _clips[i][0];
		clip.y = _clips[i][1];
		clip.w = _clips[i][2];
		clip.h = _clips[i][3];
		clips.push_back(clip);
	}
}

void Move::Update_Frame()
{
	currentframe = (currentframe + 1) % clips.size();
}