#include "game.h"
#include "graphics.h"

namespace Game{

  bool isRunning = false;

  void Init(){    
    isRunning = true;    
  }

  void Cleanup(){

  }

  void Render(){
    gfx::Clear();

    // Render Stuff Here
    gfx::renderTile(0, 10, 10);
    gfx::renderTile(1, 30, 10);
    
    gfx::Flip();
    
  }

  void Tick(){
    if(!isRunning){
      states::popAll();
    }

    handleInput();    
    
  }

  void handleInput(){    
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
    
  } // handleInput

  
} //namespace game

GameState::GameState(){

}

void GameState::Init(){
  Game::Init();
}

void GameState::Draw(){
  Game::Render();
}

void GameState::Update(){
  Game::Tick();
}
