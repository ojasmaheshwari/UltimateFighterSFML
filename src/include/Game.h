#pragma once

#include "MainWindow.h"
#include "StateManager.h"
#include "States/MainMenuState.h"
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
  private:
    bool m_Running;
    MainWindow m_Window;
    sf::Event m_MainEvent;
    StateManager m_StateManager;
    MainMenuState *m_MainMenu;
};
