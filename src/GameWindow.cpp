#include "GameWindow.h"
#include "PacMan.h"

#include <SDL2/SDL_image.h>
#include <iostream>

GameWindow::GameWindow(int width, int height) {
  initSDL();
  initSDLImage();
  auto sdl_window = createWindow(width, height);
  auto sdl_renderer = createRenderer(sdl_window);
  createWindowSurface(sdl_window);
  setDrawColor(sdl_renderer);
  maze_texture = loadTexture(sdl_renderer, "../../../assets/maze.png");
  sprite_texture = loadTexture(sdl_renderer, "../../../assets/sprites32.png");
}

void GameWindow::update(const PacMan &  pacMan) {
  SDL_RenderClear(renderer.get());

  renderMaze();
  renderPacMan(pacMan);

  SDL_RenderPresent(renderer.get());
}

void GameWindow::renderMaze() const {
  if (SDL_RenderCopy(renderer.get(), maze_texture.get(), nullptr, nullptr) < 0)
    exitFailure("Failed to copy texture to renderer");
}

void GameWindow::renderPacMan(const PacMan & pac_man) const {
  SDL_Rect sprite_rect = pac_man.currentSprite();
  SDL_Point maze_position = pac_man.currentPosition();
  SDL_Rect maze_rect = { 32*maze_position.x, 32*maze_position.y, 32, 32};
  if (SDL_RenderCopy(renderer.get(), sprite_texture.get(), &sprite_rect, &maze_rect) < 0)
    exitFailure("Failed to copy texture to renderer");
}

void GameWindow::initSDL() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    exitFailure("Failed to initialize the SDL2 library");
}

void GameWindow::initSDLImage() {
  int img_flags = IMG_INIT_PNG;
  if (IMG_Init(img_flags) != img_flags)
    exitImgFailure("Failed to init SDL_Image with png");
}

SDL_Window * GameWindow::createWindow(int width, int height) {
  window = std::unique_ptr<SDL_Window, SDL_Window_Deleter>(SDL_CreateWindow(
    "Pacman",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    width,
    height,
    SDL_WINDOW_OPENGL));

  if (!window)
    exitFailure("Failed to create window");

  return window.get();
}

SDL_Renderer * GameWindow::createRenderer(SDL_Window * sdl_window) {
  renderer = std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter>(SDL_CreateRenderer(
    sdl_window,
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

  if (!renderer)
    exitFailure("Failed to create renderer");

  return renderer.get();
}

void GameWindow::createWindowSurface(SDL_Window * sdl_window) {
  window_surface = std::unique_ptr<SDL_Surface, SDL_Surface_Deleter>(SDL_GetWindowSurface(sdl_window));
  if (!window_surface)
    exitFailure("Failed to get the surface from the window");
}

void GameWindow::setDrawColor(SDL_Renderer * sdl_renderer) {
  if (SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) < 0)
    exitFailure("Failed to set renderer color");
}

std::unique_ptr<SDL_Texture, SDL_Texture_Deleter> GameWindow::loadTexture(SDL_Renderer * sdl_renderer, const std::string& path) {
  auto surface = std::unique_ptr<SDL_Surface, SDL_Surface_Deleter>(IMG_Load(path.c_str()));
  if (!surface)
    exitImgFailure("Failed to load image");

  auto texture = std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>(SDL_CreateTextureFromSurface(sdl_renderer, surface.get()));
  if (!texture)
    exitFailure("Failed to create texture from surface");
  return texture;
}

void GameWindow::exitFailure(const std::string& message) {
  std::cerr << message << "\n";
  std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
  exit(1);
}

void GameWindow::exitImgFailure(const std::string& message) {
  std::cerr << message << "\n";
  std::cerr << "SDL2_Image Error: " << IMG_GetError() << "\n";
  exit(1);
}
