#include <SFML/Graphics.hpp>
#include <iostream>

// Constants for our Grid
const int TILE_SIZE = 24;
const int COLS = 40;
const int ROWS = 30;

int main() {
    // 1. Create the Window
    sf::RenderWindow window(sf::VideoMode(COLS * TILE_SIZE, ROWS * TILE_SIZE), "My C++ Rogue Clone");
    
    // 2. Load a Font (Essential for ASCII in a window)
    sf::Font font;
    // Note: You need a .ttf file in your project folder. 
    // "Consolas" or "Courier New" work best for ASCII.
    if (!font.loadFromFile("arial.ttf")) { 
        std::cerr << "Error loading font" << std::endl;
        return -1;
    }

    // 3. Setup the Player (The @ symbol)
    sf::Text playerSymbol;
    playerSymbol.setFont(font);
    playerSymbol.setString("@");
    playerSymbol.setCharacterSize(24);
    playerSymbol.setFillColor(sf::Color::Yellow);
    
    // Player Grid Position
    int playerX = 10;
    int playerY = 10;

    // 4. The Game Loop
    while (window.isOpen()) {
        sf::Event event;
        
        // --- Input Phase ---
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Simple Turn-Based Movement
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) playerY--;
                if (event.key.code == sf::Keyboard::Down) playerY++;
                if (event.key.code == sf::Keyboard::Left) playerX--;
                if (event.key.code == sf::Keyboard::Right) playerX++;
            }
        }

        // --- Update Phase ---
        // Snap the text object to the grid coordinates
        playerSymbol.setPosition(playerX * TILE_SIZE, playerY * TILE_SIZE);

        // --- Render Phase ---
        window.clear(); // Clear old frame
        
        // In a real game, you would loop through your map vector and draw the walls here
        
        window.draw(playerSymbol); // Draw player
        window.display(); // Flip the buffer to show the frame
    }

    return 0;
}