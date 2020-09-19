#include "PacMan.h"

PacMan::PacMan() :
  right_animation{right_wide, right_narrow, closed, right_narrow},
  left_animation{left_wide, left_narrow, closed, left_narrow},
  up_animation{up_wide, up_narrow, closed, up_narrow},
  down_animation{down_wide, down_narrow, closed, down_narrow} {
}

SDL_Rect PacMan::currentSprite() const {
  switch (direction) {
    case Direction::LEFT: return left_animation[animation_position];
    case Direction::RIGHT: return right_animation[animation_position];
    case Direction::UP: return up_animation[animation_position];
    case Direction::DOWN: return down_animation[animation_position];
  }
}

SDL_Point PacMan::currentPosition() const {
  return pos;
}

void PacMan::update(InputState state, const Board & board) {
  setDirection(state);
  updateAnimationPosition();
  updateMazePosition(board);
}

void PacMan::setDirection(const InputState & state) {
  if (state.left)
    direction = Direction::LEFT;
  else if (state.right)
    direction = Direction::RIGHT;
  else if (state.up)
    direction = Direction::UP;
  else if (state.down)
    direction = Direction::DOWN;
}

void PacMan::updateAnimationPosition() {
  animation_position = (animation_position + 1) % 4;
}

void PacMan::updateMazePosition(const Board & board) {
  SDL_Point updated_position = pos;
  switch (direction) {
    case Direction::LEFT:  updated_position.x -= 1; break;
    case Direction::RIGHT: updated_position.x += 1; break;
    case Direction::UP:    updated_position.y -= 1; break;
    case Direction::DOWN:  updated_position.y += 1; break;
  }

  if (board.isWalkable(updated_position))
    pos = updated_position;
}
