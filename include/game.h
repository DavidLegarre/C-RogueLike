#ifndef ROGUE_INCLUDE_GAME_H_
#define ROGUE_INCLUDE_GAME_H_

#include <SFML/Graphics.hpp>
#include "input_handler.h"

class Game {
 public:
  Game();
  
  void Run();
  void Quit();
  void MovePlayer(int dx, int dy);

 private:
  void ProcessEvents();
  void Update();
  void Render();

  sf::RenderWindow window_;
  sf::Font font_;
  sf::Text player_symbol_;
  InputHandler input_handler_;

  int player_x_;
  int player_y_;
};

#endif  // ROGUE_INCLUDE_GAME_H_