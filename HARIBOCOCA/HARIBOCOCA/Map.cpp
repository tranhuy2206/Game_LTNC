#include "Setup.h"
#include "iostream"
#include "fstream"
#include "Map.h"
using namespace std;

void Map::Loadtiles(SDL_Renderer* renderer) {
    ifstream InputMap("Map/map.dat");
    if (!InputMap) {
        cout << "Can't open file!";
        return;
    }

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            InputMap >> Tile_map[i][j];
        }
    }
    InputMap.close();

    SDL_Surface* surface;

    
    surface = IMG_Load("Map/gr14.png");
    if (surface == NULL) {
        cout << "IMG_Load Error: " << IMG_GetError() << "\n";
    }
    else {
        Tile_texture[0] = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    
    surface = IMG_Load("Map/1.jpg");
    if (surface == NULL) {
        cout << "IMG_Load Error: " << IMG_GetError() << "\n";
    }
    else {
        Uint32 colorKey = SDL_MapRGB(surface->format, 255, 255, 255); 
        SDL_SetColorKey(surface, SDL_TRUE, colorKey);
        Tile_texture[1] = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
}


void Map::DrawMap(SDL_Renderer* renderer)
{

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			dst = { j * TILE_SIZE,i * TILE_SIZE,TILE_SIZE,TILE_SIZE };
			SDL_RenderCopy(renderer, Tile_texture[Tile_map[i][j]], &src, &dst);
		}
	}
}

void Map::ClearMap()
{
	for (int i = 0; i < 4; i++)
	{
		SDL_DestroyTexture(Tile_texture[i]);
	}
}
