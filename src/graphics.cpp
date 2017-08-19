#include "graphics.h"
#include <iostream>
#include "constants.h"

namespace gfx{

    namespace{
      SDL_Window* _window;
      SDL_Renderer* _renderer;
      SDL_Texture* _tilesheet;

      SDL_Rect getTileFromId(int id){

	SDL_Rect rect = {0,0,g::TILE_SIZE,g::TILE_SIZE};
	switch(id){
	case 0:
	  rect.x = 0;
	  rect.y = 0;
	  break;
	case 1:
	  rect.x = g::TILE_SIZE;
	  rect.y = 0;
	  break;
	}
	return rect;
      }
      
    }

  void Init(){

    SDL_Init(SDL_INIT_VIDEO);

    _window = SDL_CreateWindow("Pewpew!",
			       SDL_WINDOWPOS_UNDEFINED,
			       SDL_WINDOWPOS_UNDEFINED,
			       g::SCREEN_WIDTH,
			       g::SCREEN_HEIGHT,
			       SDL_WINDOW_SHOWN);

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface* surf = IMG_Load("../gfx/16x16.png");

    if(surf == NULL)
      std::cout << "Could not open gfx/16x16.png" << std::endl;

    SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format,
					       255,
					       0,
					       255));

    _tilesheet = SDL_CreateTextureFromSurface(_renderer, surf);

    SDL_FreeSurface(surf);

    Clear();
    Flip();
  
    
  }

  void Cleanup(){
    SDL_DestroyTexture(_tilesheet);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
  } // Cleanup

  void renderTile(int id, int x, int y){

    SDL_Rect srcRct = getTileFromId(id);
    
    SDL_Rect dstRct = {x, y, g::TILE_SIZE, g::TILE_SIZE};
    
    SDL_RenderCopy(_renderer, _tilesheet, &srcRct, &dstRct);
    
  }  

  void Clear(){
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
  } // clear

  void Flip(){
    SDL_RenderPresent(_renderer);
  } // flip
  
}
