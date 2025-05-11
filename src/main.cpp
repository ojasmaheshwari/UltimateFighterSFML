#include "include/Game.h"

#include <iostream>

int main() {
	std::cout << "Starting game\n";
  Game game;
  while (game.isRunning()) {
    game.processEvents();
    game.update();
    game.draw();
  }
}
