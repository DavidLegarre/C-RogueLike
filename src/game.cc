#include "game.h"
#include "command.h"
#include <iostream>

// Constants
namespace {
const int kTileSize = 24;
const int kCols = 40;
const int kRows = 30;
}  // namespace

Game::Game() 
    : player_x_(10), player_y_(10) {
    window_.create(sf::VideoMode(kCols * kTileSize, kRows * kTileSize), "My C++ Rogue Clone");
    
    // Load Font
    if (!font_.loadFromFile("DejaVuSans.ttf")) { 
        std::cerr << "Error loading font" << std::endl;
    }

    // Setup Player
    player_symbol_.setFont(font_);
    player_symbol_.setString("@");
    player_symbol_.setCharacterSize(24);
    player_symbol_.setFillColor(sf::Color::Yellow);
}

void Game::Run() {
    while (window_.isOpen()) {
        ProcessEvents();
        Update();
        Render();
    }
}

void Game::MovePlayer(int dx, int dy) {
    player_x_ += dx;
    player_y_ += dy;
}

void Game::ProcessEvents() {
    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window_.close();
 
        if (event.type == sf::Event::KeyPressed) {
            Command* command = input_handler_.HandleInput(event.key.code);
            
            if (command) {
                command->Execute(*this);
            }
        }
    }
}

void Game::Update() {
    player_symbol_.setPosition(player_x_ * kTileSize, player_y_ * kTileSize);
}

void Game::Render() {
    window_.clear();
    window_.draw(player_symbol_);
    window_.display();
}

void Game::Quit() {
    window_.close();
}
