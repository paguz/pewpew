#include "graphics.h"
#include <iostream>
int main(){

  gfx::Init();

  bool isRunning = true;
  
  while(isRunning){

    SDL_Event event;

    while(SDL_PollEvent(&event)){
      switch(event.type){
      case SDL_QUIT:
	isRunning = false;
	break;
            
      case SDL_KEYDOWN:
	switch(event.key.keysym.sym){
	case SDLK_ESCAPE:
	  isRunning = false;
	  break;
	}
	
      }
    } // while events

      // Render
      gfx::Clear();
      gfx::renderTile(0, 10, 10);
      gfx::renderTile(1, 30, 10);
      gfx::Flip();
    
    
    } // main while

  
    // Cleanup
    gfx::Cleanup();
  
    return 0;
  
  } // main
