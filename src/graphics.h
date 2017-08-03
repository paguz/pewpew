#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#ifdef __APPLE__
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif
namespace gfx{

  void Init();
  void Cleanup();

  void renderTile(int id, int x, int y);

  void Clear();
  void Flip();
  
} // namespace gfx

#endif
