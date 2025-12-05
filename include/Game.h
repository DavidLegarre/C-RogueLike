#pragma once 
#include <SFML/Graphics.hpp>

class Game {
public:
    // Constructor
    Game();
    // Main Game Loop
    void run();
private:
    void processEvents();
    void update();
    void render();

    // Member Variables
    sf::RenderWindow mWindow;
    sf::Font mFont;
    sf::Text mPlayerSymbol;

    // Game State
    int mPlayerX;
    int mPlayerY;
};