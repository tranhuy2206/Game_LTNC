#pragma once
#ifndef MONVING_H_INCLUDED
#define MOVING_H_INCLUDED
#include <vector>
#include "Player.h"
#include "Map.h"
#include "Bullet.h"


using namespace std;

class Move
{
private:

	int velo;
	float x_val, y_val;
	bool jump = false;
	bool left = false;
	bool right = false;
	bool fire_left = false;
	bool fire_right = true;
	bool on_ground = false;
public:
	void CheckKeyBoard(SDL_Event event, int pl_x, int pl_y, vector<Bullet*> &magaz);
	void CheckInteract(int &pl_x, int &pl_y, Map &map);
	void MovePlayer();
	void Firing(SDL_Renderer* render,SDL_Texture* bullet_tex, vector<Bullet*> &magaz);
	void Set_up_Frame(SDL_Texture* temp, int frames, const int clips[][8]);
	void Update_Frame();
	bool Get_left() { return left; };
	bool Get_right() { return right; };
	const SDL_Rect* getCurrentClip() const { return &(clips[currentframe]); };
	SDL_Texture* pl_tex;
	vector<SDL_Rect> clips;
	int currentframe = 0;

};

#endif // !MONVING_H_INCLUDED
