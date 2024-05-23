#pragma once
#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include <vector>
#include "Setup.h"
#include "Init.h"

using namespace std;


class Bullet : public Init
{
public:

	vector<Bullet*> magazine;
	enum Bullet_direction
	{
		bul_right = 5,
		bul_left = 6,
	};
	void set_x_bul(const int& x_val) { x_bul_val = x_val; };
	void set_y_bul(const int& y_val) { y_bul_val = y_val; };
	void set_move(const bool& mov) { is_move = mov; };
	void set_direct(const unsigned int& direct) { bullet_direct = direct; };

	int get_x_bul() const { return x_bul_val; };
	int get_y_bul() const { return y_bul_val; };
	int get_direct() const { return bullet_direct; };
	bool get_mov() const { return is_move; };
	vector<Bullet*> get_magazine() 
	{
		return magazine;
	}
	SDL_Rect get_rect() { return gun; };

	void Fire(const int& x_border, const int& y_border);
	void DrawBullet(SDL_Renderer* render, SDL_Texture* bullet_tex);
	void Set_Rect(int pl_x, int pl_y);
	void Remove(int i);
	
private:
	int x_bul_val = 0;
	int y_bul_val = 0;
	unsigned int bullet_direct;
	bool is_move = false;
	SDL_Rect gun;
};



#endif // !BULLET_H_INCLUDED
