#include "input_handler.h"
#include "command.h"

InputHandler::InputHandler() {
  button_up_ = std::make_unique<MoveUpCommand>();
  button_down_ = std::make_unique<MoveDownCommand>();
  button_left_ = std::make_unique<MoveLeftCommand>();
  button_right_ = std::make_unique<MoveRightCommand>();
  button_escape_ = std::make_unique<EscapeCommand>();
}

InputHandler::~InputHandler() {}

Command* InputHandler::HandleInput(sf::Keyboard::Key key) {
  if (key == sf::Keyboard::W || key == sf::Keyboard::Up) return button_up_.get();
  if (key == sf::Keyboard::S || key == sf::Keyboard::Down) return button_down_.get();
  if (key == sf::Keyboard::A || key == sf::Keyboard::Left) return button_left_.get();
  if (key == sf::Keyboard::D || key == sf::Keyboard::Right) return button_right_.get();
  if (key == sf::Keyboard::Escape) return button_escape_.get();

  return nullptr;
}