#include "map.h"
#include "graphics.h"

namespace Map{

  std::vector<baseTile> mapTiles;
  
  void Init(){

    unsigned int counter = 0;
    
    for(int y = 0; y < g::MAP_SIZE; ++y){
      for(int x = 0; x < g::MAP_SIZE; ++x){

	mapTiles.push_back(baseTile(x*g::TILE_SIZE, y*g::TILE_SIZE, 0));
	
	if(y == 30){
	  mapTiles[counter].modifyType(1);
	}

	counter++;
	
      }
    }
    
  }

  void Cleanup(){

  }

  void Render(){
    
    for(unsigned int i = 0; i < mapTiles.size(); ++i){
      gfx::renderTile(mapTiles[i].getType(), mapTiles[i].getX(), mapTiles[i].getY());
    }
    
  }
  
}
