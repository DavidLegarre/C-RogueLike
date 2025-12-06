#include "Game.h"
#include "Command.h"
#include <iostream>

// Constants (Keep them local to this file if only used here)
const int TILE_SIZE = 24;
const int COLS = 40;
const int ROWS = 30;

// Constructor: Initialize variables and load resources
Game::Game() 
    : mPlayerX(10), mPlayerY(10) // Member Initialization List
{
    mWindow.create(sf::VideoMode(COLS * TILE_SIZE, ROWS * TILE_SIZE), "My C++ Rogue Clone");
    
    // Load Font
    // Note: Ensure the path is correct as discussed previously!
    if (!mFont.loadFromFile("DejaVuSans.ttf")) { 
        std::cerr << "Error loading font" << std::endl;
        // In a real engine, we might throw an exception here
    }

    // Setup Player
    mPlayerSymbol.setFont(mFont);
    mPlayerSymbol.setString("@");
    mPlayerSymbol.setCharacterSize(24);
    mPlayerSymbol.setFillColor(sf::Color::Yellow);
}

// The Main Loop
void Game::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::movePlayer(int dx, int dy) {
    mPlayerX += dx;
    mPlayerY += dy;
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();

       if (event.type == sf::Event::KeyPressed) {
            // Ask the handler: "Does this key mean anything?"
            Command* command = mInputHandler.handleInput(event.key.code);
            
            // If it does, execute it on *this* game instance
            if (command) {
                command->execute(*this);
            }
        }
    }
}

// 4. Update Game Logic
void Game::update() {
    // Snap position to grid
    mPlayerSymbol.setPosition(mPlayerX * TILE_SIZE, mPlayerY * TILE_SIZE);
}

// 5. Draw to Screen
void Game::render() {
    mWindow.clear();
    mWindow.draw(mPlayerSymbol);
    mWindow.display();
}

void Game::quit() {
    mWindow.close();
}
