#include "PacMan.h"
SDL_Rect PacMan::currentSprite() const {
  return left_wide;
}
SDL_Point PacMan::currentPosition() const {
  return pos;
}
