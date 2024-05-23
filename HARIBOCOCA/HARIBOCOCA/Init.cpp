#include "Setup.h"
#include "Init.h"
#include "Moving.h"
#include<iostream>
using namespace std;

void Init::InitSDL(const char* title, int screen_width, int screen_height)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		cout << "Can't initialize window: " << SDL_GetError() << "\n";
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		cout << "Can't initialize renderer: " << SDL_GetError() << "\n";
	}


}

SDL_Texture* Init::LoadTexture(const char* filename)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* sur = IMG_Load(filename);
	
	Uint32 coloreky = SDL_MapRGB(sur->format, 255, 255, 255);
	
	texture = SDL_CreateTextureFromSurface(renderer, sur);
	SDL_FreeSurface(sur);
	
	if (texture == NULL)
	{
		cout << "Can't open image: " << SDL_GetError() << "\n";
	}
	return texture;
}

Mix_Music* Init::LoadMusic(const char* path)
{
	Mix_Music* music = Mix_LoadMUS(path);
	if (music == nullptr) {
		SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
			SDL_LOG_PRIORITY_ERROR,
			"Could not load music! SDL_mixer Error: %s", Mix_GetError());
	}
	return music;

}

void Init::Play_music(Mix_Music* music)
{
	if (music == nullptr) return;

	if (Mix_PlayingMusic() == 0) {
		Mix_PlayMusic(music, -1);
	}
	else if (Mix_PausedMusic() == 1) {
		Mix_ResumeMusic();
	}

}
void Init::Display()
{
	SDL_RenderPresent(renderer);
}

void Init::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Init::Clear()
{
	SDL_RenderClear(renderer);
}