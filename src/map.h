#ifndef MAP_H
#define MAP_H

#include "helper.h"
#include "constants.h"
#include <vector>


class baseTile{

 public:
  baseTile(){
    pos.x = 0;
    pos.y = 0;
    tileType = 0;
  }

  baseTile(int x, int y, int type){
    pos.x = x;
    pos.y = y;
    tileType = type;
  }

  ~baseTile(){
  }

  void modifyType(int type){
    tileType = type;
  }

  void setSolid(bool isSolid){
    solid = isSolid;
  }

  int getType(){
    return tileType;
  }

  int getX(){
    return pos.x;
  }

  int getY(){
    return pos.y;
  }

 protected:
  P pos;
  int tileType;
  bool solid;
  
};

namespace Map{

  extern std::vector<baseTile> mapTiles;
  
  void Init();

  void Cleanup();

  void Render();  
  
}


#endif
