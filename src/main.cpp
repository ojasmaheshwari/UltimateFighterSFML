#include <Game.h>

int main() {
  Game game;
  while (game.isRunning()) {
    game.processEvents();
    game.update();
    game.draw();
  }
}
