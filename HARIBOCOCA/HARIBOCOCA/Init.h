#pragma once
#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED
#include "Setup.h"

struct Init
{
public:
	void InitSDL(const char* title, int screen_width, int screen_height);
	void Destroy();
	void Clear();
	void Display();
	void Play_music(Mix_Music* music);
	Mix_Music* LoadMusic(const char* path);
	SDL_Texture* LoadTexture(const char* filename);
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
};

#endif // !INIT_H_INCLUDED
