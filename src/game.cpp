#include "game.h"
#include "graphics.h"
#include "map.h"

namespace Game{

  bool isRunning = false;

  void Init(){    
    isRunning = true;
    Map::Init();
  }

  void Cleanup(){
    Map::Cleanup();
  }

  void Render(){
    gfx::Clear();

    // Render Stuff Here
    Map::Render();
    
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
