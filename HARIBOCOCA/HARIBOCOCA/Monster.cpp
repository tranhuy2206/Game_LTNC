#include "Monster.h"

void Monster::DrawMonster(SDL_Renderer* render, SDL_Texture* mons_tex)
{
	SDL_Rect mons;
	mons.x = mon_x;
	mons.y = mon_y;

	SDL_QueryTexture(mons_tex, NULL, NULL, &mons.w, &mons.h);

	SDL_RenderCopy(render, mons_tex, NULL, &mons);
}

void Monster::CheckCollision(Map& map)
{
	int x1 = (mon_x + mon_x_velo) / TILE_SIZE;
	int x2 = (mon_x+ mon_x_velo + WIDTH_FRAME - 1) / TILE_SIZE;

	int y1 = mon_y / TILE_SIZE;
	int y2 = (mon_y + HEIGHT_FRAME - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAP_WIDTH && y1 >= 0 && y2 < MAP_HEIGHT)
	{
		if (mon_x_velo > 0)
		{
			if (map.Tile_map[y1][x2] != BLANK_TILE || map.Tile_map[y2][x2] != BLANK_TILE)
			{
				mon_x = x2 * TILE_SIZE;
				mon_x -= WIDTH_FRAME + 1;
				mon_x_velo = 0;
			}
		}
		else if (mon_x_velo < 0)
		{
			if (map.Tile_map[y1][x1] != BLANK_TILE || map.Tile_map[y2][x1] != BLANK_TILE)
			{
				mon_x = (x1 + 1) * TILE_SIZE;
				mon_x_velo = 0;
			}
		}
	}

	x1 = mon_x / TILE_SIZE;
	x2 = (mon_x + WIDTH_FRAME) / TILE_SIZE;

	y1 = (mon_y + mon_y_velo) / TILE_SIZE;
	y2 = (mon_y + mon_y_velo + HEIGHT_FRAME - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAP_WIDTH && y1 >= 0 && y2 < MAP_HEIGHT)
	{
		if (mon_y_velo > 0)
		{
			if (map.Tile_map[y2][x1] != BLANK_TILE || map.Tile_map[y2][x2] != BLANK_TILE)
			{
				mon_y = y2 * TILE_SIZE;
				mon_y -= HEIGHT_FRAME + 1;
				mon_y_velo = 0;
			}
		}
		else if (mon_y_velo < 0)
		{
			if (map.Tile_map[y1][x1] != BLANK_TILE || map.Tile_map[y1][x2] != BLANK_TILE)
			{
				mon_y = (y1 + 1) * TILE_SIZE;
				mon_y_velo = 0;
			}
		}
	}

	mon_x += mon_x_velo;
	mon_y += mon_y_velo;
}

void Monster::MoveMon(Map &map)
{
	mon_x_velo = 0;
	mon_y_velo = 0;
	if (go_left)
	{
		mon_x_velo -= VELOCITY;
	}
	else if (go_right)
	{
		mon_x_velo+= VELOCITY;
	}

	CheckCollision(map);
}

void Monster::CheckMove()
{
	if (type_mov == Idle_mon)
	{
		;
	}
	else
	{
		if (mon_x > right_lim)
		{
			go_left = true;
			go_right = false;
		}
		else if (mon_x < left_lim)
		{
			go_right = true;
			go_left = false;
		}

	}
}

void Monster::Minus_HP()
{
	HP--;
}

void Monster::Set_up_Frame(SDL_Texture* temp, int frames, const int clips[][6])
{
	boss_tex = temp;
	SDL_Rect clip;
	for (int i = 0; i < frames; i++) 
	{
		clip.x = clips[i][0];
		clip.y = clips[i][1];
		clip.w = clips[i][2];
		clip.h = clips[i][3];
		b_clips.push_back(clip);
	}
}

void Monster::Update_Frame()
{
	currentbossframe = (currentbossframe + 1) % b_clips.size();
}

void Monster::CastMagik(Bullet* bullet)
{
	if (bullet != NULL)
	{
		bullet->set_move(true);
		bullet->set_direct(Bullet::bul_left);
		bullet->Set_Rect(mon_x + 20, mon_y + 10);
		bullet->set_x_bul(10);
		magik_list.push_back(bullet);
	}
}

void Monster::Shoot(SDL_Renderer* render, const int& x_lim, const int& y_lim, SDL_Texture* magik_tex)
{
	for (int i = 0; i < magik_list.size(); i++)
	{
		Bullet* bul = magik_list.at(i);
		if (bul!= NULL)
		{
			if (bul->get_mov())
			{
				bul->Fire(x_lim, y_lim);
				bul->DrawBullet(render,magik_tex);
			}
			else
			{
				bul->set_move(true);
				bul->Set_Rect(mon_x + 20, mon_y + 10);
			}
		}
	}
}

void Monster::Remove(int i)
{
	size_t size = magik_list.size();

	if (size > 0 && i < size)
	{
		Bullet* bul = magik_list.at(i);
		magik_list.erase(magik_list.begin() + i);

		if (bul)
		{
			delete bul;
			bul = NULL;
		}
	}
}
