#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include "InputState.h"

#include <SDL2/SDL_rect.h>

class PacMan {
public:
  PacMan();
  [[nodiscard]] SDL_Rect currentSprite() const;
  [[nodiscard]] SDL_Point currentPosition() const;

  void update(InputState state);

private:

  enum class Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
  };

  Direction direction = Direction::LEFT;
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
  const SDL_Rect right_animation[4];
  const SDL_Rect left_animation[4];
  const SDL_Rect up_animation[4];
  const SDL_Rect down_animation[4];
  uint8_t animation_position = 0;

  void setDirection(const InputState & state);
  void updateAnimationPosition();
  void updateMazePosition();
};

#endif //PACMAN_PACMAN_H
