#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace gfx{

  void Init();
  void Cleanup();

  void renderTile(int id, int x, int y);

  void Clear();
  void Flip();
  
} // namespace gfx

#endif
