#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include <SDL2/SDL_rect.h>
class PacMan {
public:
  [[nodiscard]] SDL_Rect currentSprite() const;
  [[nodiscard]] SDL_Point currentPosition() const;

private:
  SDL_Point pos = {14, 23};
  const SDL_Rect right_wide   = {0*32, 0, 32, 32};
  const SDL_Rect right_narrow = {1*32, 0, 32, 32};
  const SDL_Rect closed       = {2*23, 0, 32, 32};
  const SDL_Rect left_narrow  = {3*32, 0, 32, 32};
  const SDL_Rect left_wide    = {4*32, 0, 32, 32};
  const SDL_Rect up_wide      = {5*32, 0, 32, 32};
  const SDL_Rect up_narrow    = {6*32, 0, 32, 32};
  const SDL_Rect down_wide    = {7*32, 0, 32, 32};
  const SDL_Rect down_narrow  = {8*32, 0, 32, 32};
};

#endif //PACMAN_PACMAN_H
