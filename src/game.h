#ifndef GAME_H
#define GAME_H

#include "state.h"

namespace Game{

  extern bool isRunning;
      
  void Init();

  void Cleanup();

  void Render();

  void Tick();

  void handleInput();
  
}


class GameState : public State{

 public:
  GameState();
  void Init() override;
  void Draw() override;
  void Update() override;
  
};


#endif
