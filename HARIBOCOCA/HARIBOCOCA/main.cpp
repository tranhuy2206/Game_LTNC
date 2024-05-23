#include <iostream>
#include <vector>
#include "Setup.h"
#include "Init.h"
#include "Moving.h"
#include "Map.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"

using namespace std;

Init window;
Map bando;
Player plei;
Move mov;
Bullet powder;
Monster t1;
int BOSS = 0;
bool gameover = false;

void Render_Animation(int pl_x, int pl_y, Move& mov, SDL_Renderer* renderer)
{
	const SDL_Rect* clip = mov.getCurrentClip();

	SDL_Rect renderquad = { pl_x, pl_y,clip->w,clip->h };

	SDL_RenderCopy(renderer, mov.pl_tex, clip, &renderquad);
}

void Render_Boss_Animation(int mon_x, int mon_y, Monster& t1, SDL_Renderer* renderer)
{
	const SDL_Rect* b_clip = t1.GetCurrentBossclip();

	SDL_Rect b_renderquad = { mon_x,mon_y,b_clip->w,b_clip->h };

	SDL_RenderCopy(renderer, t1.boss_tex, b_clip, &b_renderquad);
}


vector<Monster*> SpawnMonster(SDL_Texture* mons_tex)
{
	vector<Monster*> Monster_list;
	Monster* mon = new Monster[9];

		Monster* demon_1 = (mon + 0);
		if (demon_1 != NULL)
		{
			demon_1->set_type_move(Monster::Move_in_area);
			demon_1->set_mon_x(TILE_SIZE * 16);
			demon_1->set_mon_y(TILE_SIZE * 9);
			demon_1->set_HP(10);

			demon_1->set_lim(11 * TILE_SIZE, 16 * TILE_SIZE);

			Monster_list.push_back(demon_1);
		} 

		Monster* demon_2 = (mon + 1);
		if (demon_2 != NULL)
		{
			demon_2->set_type_move(Monster::Move_in_area);
			demon_2->set_mon_x(TILE_SIZE * 3);
			demon_2->set_mon_y(TILE_SIZE * 9);
			demon_2->set_HP(10);

			demon_2->set_lim(3 * TILE_SIZE, 8 * TILE_SIZE);

			Monster_list.push_back(demon_2);
		}

		Monster* demon_3 = (mon + 2);
		if (demon_3 != NULL)
		{
			demon_3->set_type_move(Monster::Move_in_area);
			demon_3->set_mon_x(TILE_SIZE * 12);
			demon_3->set_mon_y(TILE_SIZE * 7);
			demon_3->set_HP(10);

			demon_3->set_lim(7 * TILE_SIZE, 12 * TILE_SIZE);

			Monster_list.push_back(demon_3);
		}

		Monster* demon_4 = (mon + 3);
		if (demon_4 != NULL)
		{
			demon_4->set_type_move(Monster::Move_in_area);
			demon_4->set_mon_x(TILE_SIZE * 19);
			demon_4->set_mon_y(TILE_SIZE * 5);
			demon_4->set_HP(10);

			demon_4->set_lim(15 * TILE_SIZE, 19 * TILE_SIZE);

			Monster_list.push_back(demon_4);
		}

		Monster* demon_5 = (mon + 4);
		if (demon_5 != NULL)
		{
			demon_5->set_type_move(Monster::Move_in_area);
			demon_5->set_mon_x(TILE_SIZE * 0);
			demon_5->set_mon_y(TILE_SIZE * 5);
			demon_5->set_HP(10);

			demon_5->set_lim(0 * TILE_SIZE, 4 * TILE_SIZE);

			Monster_list.push_back(demon_5);
		}

		Monster* demon_6 = (mon + 5);
		if (demon_6 != NULL)
		{
			demon_6->set_type_move(Monster::Move_in_area);
			demon_6->set_mon_x(TILE_SIZE * 2);
			demon_6->set_mon_y(TILE_SIZE * 3);
			demon_6->set_HP(10);

			demon_6->set_lim(2 * TILE_SIZE, 8 * TILE_SIZE);

			Monster_list.push_back(demon_6);
		}

		Monster* demon_7 = (mon + 6);
		if (demon_7 != NULL)
		{
			demon_7->set_type_move(Monster::Move_in_area);
			demon_7->set_mon_x(TILE_SIZE * 17);
			demon_7->set_mon_y(TILE_SIZE * 3);
			demon_7->set_HP(10);

			demon_7->set_lim(11 * TILE_SIZE, 17 * TILE_SIZE);

			Monster_list.push_back(demon_7);
		}

		Monster* demon_8 = (mon + 7);
		if (demon_8 != NULL)
		{
			demon_8->set_type_move(Monster::Move_in_area);
			demon_8->set_mon_x(TILE_SIZE * 19);
			demon_8->set_mon_y(TILE_SIZE * 1);
			demon_8->set_HP(10);

			demon_8->set_lim(15 * TILE_SIZE, 16 * TILE_SIZE);

			Monster_list.push_back(demon_8);
		}

		Monster* demon_9 = (mon + 8);
		if (demon_9 != NULL)
		{
			demon_9->set_type_move(Monster::Move_in_area);
			demon_9->set_mon_x(TILE_SIZE * 0);
			demon_9->set_mon_y(TILE_SIZE * 1);
			demon_9->set_HP(10);

			demon_9->set_lim(0 * TILE_SIZE, 4 * TILE_SIZE);

			Monster_list.push_back(demon_9);
		}
				
	return Monster_list;
}

void Load_BackGround(SDL_Renderer* renderer, SDL_Texture* back_ground) 
{
	if (back_ground == NULL) {
		back_ground = window.LoadTexture("IMG/Daisyrs.jpg");
	}

	SDL_RenderCopy(renderer, back_ground, NULL, NULL);
}

void waitUntilKeyPressed()
{
	SDL_Event e;
	while (true) {
		if (SDL_PollEvent(&e) != 0 &&
			(e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
			return;
		SDL_Delay(100);
	}
}

void MainLoop()
{
	SDL_Texture* pl_tex = window.LoadTexture("IMG/move_right.png");
	SDL_Texture* pl_tex_left = window.LoadTexture("IMG/move_left.png");
	SDL_Texture* bullet_tex = window.LoadTexture("IMG/Bullet2.png");
	SDL_Texture* mons_tex = window.LoadTexture("IMG/monster2.png");
	SDL_Texture* boss_tex = window.LoadTexture("IMG/Boss.png");
	SDL_Texture* boss_tex_left = window.LoadTexture("IMG/Boss_left.png");
	SDL_Texture* magik_tex = window.LoadTexture("IMG/Bullet.png");
	SDL_Texture* magik_tex_left = window.LoadTexture("IMG/Bullet_left.png");

	vector<Monster*> Mons_list = SpawnMonster(mons_tex);


	bando.Loadtiles(window.renderer);
	mov.Set_up_Frame(pl_tex, 8, PLAYER_SPRITE);
	t1.Set_up_Frame(boss_tex, 6, BOSS_SPIRTE);
	SDL_Texture* back_ground = window.LoadTexture("Map/DamLay.png");

	bool running = true;
	while (running)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
			mov.CheckKeyBoard(event, plei.pl_x, plei.pl_y, powder.magazine);
			if (mov.Get_right())
			{
				mov.Set_up_Frame(pl_tex, 5, PLAYER_SPRITE);
			}
			else if (mov.Get_left())
			{
				mov.Set_up_Frame(pl_tex_left, 5, PLAYER_SPRITE);
			}
		}
		if (BOSS == 1)
		{
			t1.Update_Frame();
		}
		mov.MovePlayer();
		mov.CheckInteract(plei.pl_x, plei.pl_y, bando);
		window.Clear();

		Load_BackGround(window.renderer, back_ground);

		Render_Animation(plei.pl_x, plei.pl_y, mov, window.renderer);
		bando.DrawMap(window.renderer);
		mov.Firing(window.renderer, bullet_tex, powder.magazine);

		for (int i = 0; i < Mons_list.size(); i++)
		{
			Monster* zoro = Mons_list.at(i);
			if (zoro != NULL)
			{

				if (BOSS == 1)
				{
					Render_Boss_Animation(zoro->get_mon_x(), zoro->get_mon_y(), t1, window.renderer);
					if (zoro->get_left())
					{
						zoro->Shoot(window.renderer, SCREEN_WIDTH, SCREEN_HEIGHT, magik_tex);
					}

					SDL_Rect player;
					player.x = plei.get_pl_x();
					player.y = plei.get_pl_y();
					player.w = 54;
					player.h = 54;
					bool danger = false;
					vector<Bullet*> rocket_list = zoro->get_magik_list();
					for (int l = 0; l < rocket_list.size(); l++)
					{
						Bullet* t_rocket = rocket_list.at(i);
						if (t_rocket)
						{
							danger = Cross_account::CheckTwoObj(t_rocket->get_rect(), player);
							if (danger)
							{
								zoro->Remove(l);
								gameover = true;
								running = false;
								break;
							}
						}
					}
				}
				else if (BOSS < 1)
				{
					zoro->DrawMonster(window.renderer, mons_tex);
				}
				if (zoro->get_right())
				{
					t1.Set_up_Frame(boss_tex, 6, BOSS_SPIRTE);
				}
				else if (zoro->get_left())
				{
					t1.Set_up_Frame(boss_tex_left, 6, BOSS_SPIRTE);
				}
				zoro->MoveMon(bando);
				zoro->CheckMove();
			}
		}

		vector<Bullet*> magazin = powder.get_magazine();
		for (int j = 0; j < magazin.size(); j++)
		{
			Bullet* bul = magazin.at(j);
			if (bul != NULL)
			{
				for (int k = 0; k < Mons_list.size(); k++)
				{
					Monster* kaiju = Mons_list.at(k);
					if (kaiju != NULL)
					{
						SDL_Rect mon_rect;
						mon_rect.x = kaiju->get_mon_x();
						mon_rect.y = kaiju->get_mon_y();
						mon_rect.w = kaiju->get_width_frame();
						mon_rect.h = kaiju->get_height_frame();

						SDL_Rect bul_rect = bul->get_rect();

						bool check = Cross_account::CheckTwoObj(bul_rect, mon_rect);

						if (check)
						{
							powder.Remove(j);
							kaiju->Minus_HP();
							if (kaiju->get_HP() == 0)
							{
								Mons_list.erase(Mons_list.begin() + k);
							}

						}
					}
				}
			}
		}
		if (Mons_list.size() == 0)
		{
			BOSS++;
			if (BOSS == 1)
			{
				Monster* boss = new Monster();
				if (boss != NULL)
				{
					boss->set_type_move(Monster::Move_in_area);
					boss->set_mon_x(TILE_SIZE * 9);
					boss->set_mon_y(TILE_SIZE * 3);
					boss->set_HP(100);

					boss->set_lim(6 * TILE_SIZE, 12 * TILE_SIZE);

					Bullet* bullet = new Bullet();
					boss->CastMagik(bullet);


					Mons_list.push_back(boss);
				}
			}
			else if (BOSS > 1)
			{
				running = false;
			}
		}

		window.Display();
		SDL_Delay(10);
	}
	plei.CLearPlayer(pl_tex);
}


int main(int argv, char* argc[])
{

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		cout << "Can't run: " << SDL_GetError() << "\n";
	}

	if (!(IMG_Init(IMG_INIT_JPG)))
	{
		cout << "Img_Init has an error: " << SDL_GetError() << "\n";
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
	}

	window.InitSDL("GUN GALE OFFLINE", SCREEN_WIDTH, SCREEN_HEIGHT);
	
	Mix_Music* menu_music = window.LoadMusic("Music/undertale.mp3");
	Mix_Music* game_music = window.LoadMusic("Music/nameless.mp3");
	Mix_Music* end_music = window.LoadMusic("Music/Refrain.mp3");
	Mix_Music* game_over = window.LoadMusic("Music/gameover.mp3");

	window.Play_music(menu_music);

	SDL_Texture* menu = window.LoadTexture("IMG/menu.jpg");
	SDL_Texture* endgame = window.LoadTexture("IMG/endgame.jpg");
	SDL_Texture* gameoverr = window.LoadTexture("IMG/gameover.jpg");

	SDL_RenderCopy(window.renderer, menu, NULL, NULL);
	window.Display();

	waitUntilKeyPressed();

	Mix_HaltMusic();
	window.Play_music(game_music);

	MainLoop();
	if (gameover)
	{
		SDL_RenderCopy(window.renderer, gameoverr, NULL, NULL);
		window.Display();
		Mix_HaltMusic();
		window.Play_music(game_over);
		waitUntilKeyPressed();
	}
	else
	{
		Mix_HaltMusic();
		window.Play_music(end_music);

		SDL_RenderCopy(window.renderer, endgame, NULL, NULL);
		window.Display();

		waitUntilKeyPressed();
	}

	bando.ClearMap();
	window.Destroy();
	Mix_FreeMusic(game_music);
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
} 