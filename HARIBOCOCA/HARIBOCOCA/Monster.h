#pragma once
#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include <vector>
#include "Setup.h"
#include "Map.h"
#include "Bullet.h"

using namespace std;

#define MONSTER_FRAME 5

class Monster
{
public:
	enum TypeMove
	{
		Idle_mon = 0,
		Move_in_area = 1,
	};
	SDL_Texture* boss_tex;
	vector<SDL_Rect> b_clips;
	vector<Bullet*> get_magik_list() const { return magik_list; };
	int currentbossframe = 0;

	void set_mon_xvelo(int monxvel) { mon_x_velo = monxvel; };
	void set_mon_yvelo(int monyvel) { mon_y_velo = monyvel; };

	void set_mon_x(int x_pos) { mon_x = x_pos; };
	void set_mon_y(int y_pos) { mon_y = y_pos; };
	void set_HP(int hp) { HP = hp; };
	void set_magik_list(const vector<Bullet*>& ap_list) { magik_list = ap_list; };
	void CastMagik(Bullet* bullet);
	void Shoot(SDL_Renderer* render, const int& x_lim, const int& y_lim, SDL_Texture* magik_tex);

	void set_type_move(const int& typeMov) { type_mov = typeMov; };
	void set_lim(const int& lim_l, const int& lim_r) { left_lim = lim_l; right_lim = lim_r; };

	int get_mon_x() const { return mon_x; };
	int get_mon_y() const { return mon_y; };
	bool get_right() const { return go_right; };
	bool get_left() const { return go_left; };

	const SDL_Rect* GetCurrentBossclip() const { return &(b_clips[currentbossframe]); };
	int get_HP() const { return HP; };
	int get_width_frame() const { return width_frame; };
	int get_height_frame() const { return height_frame; };

	void DrawMonster(SDL_Renderer* render, SDL_Texture* mons_tex);
	void MoveMon(Map &map);
	void CheckCollision(Map& map);
	void CheckMove();
	void Minus_HP();
	void Set_up_Frame(SDL_Texture* temp, int frames, const int clips[][6]);
	void Update_Frame();
	void Remove(int i);
private:
	vector<Bullet*> magik_list;
	int HP = 0;
	int mon_x = 0;
	int mon_y = 0;
	int mon_x_velo = 0;
	int mon_y_velo = 0;
	int width_frame = 60;
	int height_frame = 59;
	int type_mov;
	int left_lim;
	int right_lim;
	bool go_right = true;
	bool go_left = false;

};

#endif // !MONSTER_H_INCLUDED
