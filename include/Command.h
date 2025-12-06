#pragma once
#include "Game.h" // Forward declaration might be better, but keeping it simple

// Abstract Base Class
class Command {
public:
    virtual ~Command() {}
    // The "execute" method takes the entity acting (the Game or Player)
    virtual void execute(Game& game) = 0; 
};

// Concrete Command: Move Up
class MoveUpCommand : public Command {
public:
    void execute(Game& game) override {
        game.movePlayer(0, -1); // We will add this helper to Game
    }
};

// Concrete Command: Move Down
class MoveDownCommand : public Command {
public:
    void execute(Game& game) override {
        game.movePlayer(0, 1);
    }
};

// Concrete Command: Move Left
class MoveLeftCommand : public Command {
public:
    void execute(Game& game) override {
        game.movePlayer(-1, 0);
    }
};

// Concrete Command: Move Right
class MoveRightCommand : public Command {
public:
    void execute(Game& game) override {
        game.movePlayer(1, 0);
    }
};

class EscapeCommand : public Command {
public:
    void execute(Game& game) override {
        game.quit();
    }
};