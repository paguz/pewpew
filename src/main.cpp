#include "game.h"
#include "graphics.h"
#include "debug.h"
#include <iostream>
#include <memory>

class GameState;

int main(int argc, char *argv[]){

  if(argc >= 2){
    std::string debugFlag = argv[1];
    if(debugFlag == "-d"){
      Debug::Init(true);
    }
    else{
      Debug::Init(false);
    }
  }
  
  gfx::Init();

  std::unique_ptr<State> gameState(new GameState());
  states::push(std::move(gameState));

  while(!states::is_empty()){

    states::start();

    if(states::is_empty()){
      break;
    }

    states::draw();

    states::update();
    
  } // while

  gfx::Cleanup();
  
  return 0;
  
} // main
