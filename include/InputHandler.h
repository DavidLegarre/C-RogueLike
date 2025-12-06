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
    Command* handleInput(sf::Keyboard::Key key);

private:
    // We own the command objects
    std::unique_ptr<Command> m_buttonUp;
    std::unique_ptr<Command> m_buttonDown;
    std::unique_ptr<Command> m_buttonLeft;
    std::unique_ptr<Command> m_buttonRight;
    std::unique_ptr<Command> m_buttonEscape;
};