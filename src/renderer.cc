#include "renderer.h"
#include <iostream>

Renderer::Renderer(unsigned int width, unsigned int height, const std::string& title) {
  // Directly initializing window_ in body as done in original, though initializer list is better.
  // Original: mWindow.create(...)
  window_.create(sf::VideoMode(width, height), title);
}

Renderer::~Renderer() {}

// Original file didn't implement other methods, so leaving them out to match logic preservation.