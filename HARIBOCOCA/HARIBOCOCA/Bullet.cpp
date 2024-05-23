#include "Bullet.h"

void Bullet::Fire(const int& x_border, const int& y_border)
{
	if (bullet_direct == bul_right)
	{
		gun.x += x_bul_val;
		if (gun.x > x_border)
		{
			is_move = false;
		}
	}
	else if (bullet_direct == bul_left)
	{
		gun.x -= x_bul_val;
		if (gun.x < 0)
		{
			is_move = false;
		}
	}

}

void Bullet::Set_Rect(int pl_x, int pl_y)
{
	gun.x = pl_x;
	gun.y = pl_y;
} 



void Bullet::DrawBullet(SDL_Renderer* renderer, SDL_Texture* bullet_tex)
{

	SDL_QueryTexture(bullet_tex, NULL, NULL, &gun.w, &gun.h);

	SDL_RenderCopy(renderer, bullet_tex, NULL, &gun);
}

void Bullet::Remove(int i)
{
	size_t size = magazine.size();

	if (size > 0 && i < size)
	{
		Bullet* bul = magazine.at(i);
		magazine.erase(magazine.begin() + i);

		if (bul)
		{
			delete bul;
			bul = NULL;
		}
	}
}