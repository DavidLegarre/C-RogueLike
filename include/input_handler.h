#pragma once
#include <SFML/Graphics.hpp>
#include <memory> // For std::unique_ptr

// Forward declare Command to break circular dependency with Game.h
class Command;

class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    // Returns a pointer to the command, or nullptr if no relevant key was pressed
    Command* HandleInput(sf::Keyboard::Key key);

private:
    // We own the command objects
    std::unique_ptr<Command> button_up_;
    std::unique_ptr<Command> button_down_;
    std::unique_ptr<Command> button_left_;
    std::unique_ptr<Command> button_right_;
    std::unique_ptr<Command> button_escape_;
};