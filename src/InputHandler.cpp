#include "InputHandler.h"
#include "Command.h" 

// Constructor: Bind keys to commands
InputHandler::InputHandler() {
    m_buttonUp = std::make_unique<MoveUpCommand>();
    m_buttonDown = std::make_unique<MoveDownCommand>();
    m_buttonLeft = std::make_unique<MoveLeftCommand>();
    m_buttonRight = std::make_unique<MoveRightCommand>();
    m_buttonEscape = std::make_unique<EscapeCommand>();
}

// Destructor (Required for unique_ptr cleanups in some contexts)
InputHandler::~InputHandler() {}

// The Logic
Command* InputHandler::handleInput(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::W || key == sf::Keyboard::Up) return m_buttonUp.get();
    if (key == sf::Keyboard::S || key == sf::Keyboard::Down) return m_buttonDown.get();
    if (key == sf::Keyboard::A || key == sf::Keyboard::Left) return m_buttonLeft.get();
    if (key == sf::Keyboard::D || key == sf::Keyboard::Right) return m_buttonRight.get();
    if (key == sf::Keyboard::Escape) return m_buttonEscape.get();
    
    return nullptr;
}