#pragma once

#include "../BaseState.h"
#include <SFML/Graphics.hpp>

class MainMenuState : public BaseState {
public:
  MainMenuState(sf::RenderWindow *window);
  ~MainMenuState();
  void processEvents() override;
  void draw() override;
  void update() override;

private:
  sf::RenderWindow *m_Window;
};
