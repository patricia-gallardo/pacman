#ifndef PACMAN_GAMEWINDOW_H
#define PACMAN_GAMEWINDOW_H

#include <memory>

#include <SDL2/SDL.h>

struct SDL_Window_Deleter {
  void operator()(SDL_Window * window) {
    SDL_DestroyWindow(window);
  }
};

struct SDL_Renderer_Deleter {
  void operator()(SDL_Renderer * renderer) {
    SDL_DestroyRenderer(renderer);
  }
};

struct SDL_Surface_Deleter {
  void operator()(SDL_Surface * surface) {
    SDL_FreeSurface(surface);
  }
};

struct SDL_Texture_Deleter {
  void operator()(SDL_Texture * texture) {
    SDL_DestroyTexture(texture);
  }
};

class GameWindow {
public:
  explicit GameWindow(int width, int height);
  void update();

private:
  std::unique_ptr<SDL_Window, SDL_Window_Deleter> window;
  std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter> renderer;
  std::unique_ptr<SDL_Surface, SDL_Surface_Deleter> window_surface;
  SDL_Window * createWindow(int width, int height);
  SDL_Renderer * createRenderer(SDL_Window * window);
  void createWindowSurface(SDL_Window * sdl_window);
  static void initSDL();
  static void initSDLImage();
  static void setDrawColor(SDL_Renderer * sdl_renderer);
  static void renderMaze(SDL_Renderer * sdl_renderer);
  static void exitFailure(const std::string& message);
  static void exitImgFailure(const std::string& message);
};

#endif //PACMAN_GAMEWINDOW_H
