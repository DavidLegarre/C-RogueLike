#ifndef ROGUE_INCLUDE_COMMAND_H_
#define ROGUE_INCLUDE_COMMAND_H_

#include "game.h"

class Command {
 public:
  virtual ~Command() {}
  virtual void Execute(Game& game) = 0;
};

class MoveUpCommand : public Command {
 public:
  void Execute(Game& game) override {
    game.MovePlayer(0, -1);
  }
};

class MoveDownCommand : public Command {
 public:
  void Execute(Game& game) override {
    game.MovePlayer(0, 1);
  }
};

class MoveLeftCommand : public Command {
 public:
  void Execute(Game& game) override {
    game.MovePlayer(-1, 0);
  }
};

class MoveRightCommand : public Command {
 public:
  void Execute(Game& game) override {
    game.MovePlayer(1, 0);
  }
};

class EscapeCommand : public Command {
 public:
  void Execute(Game& game) override {
    game.Quit();
  }
};

#endif  // ROGUE_INCLUDE_COMMAND_H_