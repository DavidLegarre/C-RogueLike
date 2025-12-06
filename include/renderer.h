#ifndef ROGUE_INCLUDE_RENDERER_H_
#define ROGUE_INCLUDE_RENDERER_H_

#include <SFML/Graphics.hpp>
#include <string>

class Game;

class Renderer {
 public:
  Renderer(unsigned int width, unsigned int height, const std::string& title);
  ~Renderer();


  // Core Loop methods
  void Clear();
  void Display();
  bool IsWindowOpen() const;
  bool PollEvent(sf::Event& event);
  void CloseWindow();

  // Drawing methods
  void DrawPlayer(int x, int y);
  void DrawDebugGrid(int cols, int rows);

 private:
  sf::RenderWindow window_;
  sf::Font font_;
  sf::Text player_symbol_;
  sf::Text tile_symbol_;

  static constexpr int kTileSize = 24;
  static constexpr int kCols = 40;
  static constexpr int kRows = 30;
};

#endif  // ROGUE_INCLUDE_RENDERER_H_
