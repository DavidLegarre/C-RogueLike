#include "renderer.h"
#include <iostream>

Renderer::Renderer(unsigned int width, unsigned int height, const std::string& title) {
  // Directly initializing window_ in body as done in original, though initializer list is better.
  // Original: mWindow.create(...)
  window_.create(sf::VideoMode(width, height), title);
  window_.setVerticalSyncEnabled(true);
  if (!font_.loadFromFile("DejaVuSans.ttf")) { 
    std::cerr << "Error loading font" << std::endl;
  }

  tile_symbol_.setFont(font_);
  tile_symbol_.setCharacterSize(kTileSize);
}

void Renderer::Clear() {
  window_.clear();
}

void Renderer::Display() {
  window_.display();
}

bool Renderer::IsWindowOpen() const {
  return window_.isOpen();
}

bool Renderer::PollEvent(sf::Event& event) {
  return window_.pollEvent(event);
}

void Renderer::CloseWindow() {
  window_.close();
}

void Renderer::DrawPlayer(int x, int y) {
  player_symbol_.setFont(font_);
  player_symbol_.setCharacterSize(kTileSize);
  player_symbol_.setString("@");
  player_symbol_.setFillColor(sf::Color::Yellow);
  player_symbol_.setPosition(x * kTileSize, y * kTileSize);
  window_.draw(player_symbol_);
}

void Renderer::DrawDebugGrid(int cols, int rows) {
  int width = cols * kTileSize;
  int height = rows * kTileSize;

  sf::VertexArray grid(sf::Lines);

  // Vertical lines
  for (int x = 0; x <= cols; ++x) {
    grid.append(sf::Vertex(sf::Vector2f(x * kTileSize, 0), sf::Color(50, 50, 50)));
    grid.append(sf::Vertex(sf::Vector2f(x * kTileSize, height), sf::Color(50, 50, 50)));
  }

  // Horizontal lines
  for (int y = 0; y <= rows; ++y) {
    grid.append(sf::Vertex(sf::Vector2f(0, y * kTileSize), sf::Color(50, 50, 50)));
    grid.append(sf::Vertex(sf::Vector2f(width, y * kTileSize), sf::Color(50, 50, 50)));
  }

  window_.draw(grid);
}


Renderer::~Renderer() { }
