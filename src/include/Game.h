#pragma once

#include <MainWindow.h>
#include <StateManager.h>
#include <States/GameState.h>
#include <States/MainMenuState.h>
#include <utils/Logging.h>
#include <SFML/Window/Event.hpp>

class Game {
public:
  Game();
  ~Game();
  bool isRunning() const;
  void update();
  void draw();
  void quit();
  void processEvents();
  void moveToPlayArena();

private:
  bool m_Running;
  MainWindow m_Window;
  StateManager m_StateManager;
  MainMenuState *m_MainMenu;
  GameState *m_GameState;
  Logging m_Logger;
	sf::Clock m_DeltaClock;
};
