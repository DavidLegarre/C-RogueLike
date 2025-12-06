#pragma once 
#include <SFML/Graphics.hpp>
#include "InputHandler.h"

class Game {
public:
    // Constructor
    Game();
    // Main Game Loop
    void run();
    void quit();
    void movePlayer(int dx, int dy);
private:
    void processEvents();
    void update();
    void render();

    // Member Variables
    sf::RenderWindow mWindow;
    sf::Font mFont;
    sf::Text mPlayerSymbol;
    InputHandler mInputHandler;

    // Game State
    int mPlayerX;
    int mPlayerY;
};