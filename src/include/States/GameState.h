#pragma once

#include "../BaseState.h"
#include <SFML/Graphics/RenderWindow.hpp>

class GameState : public BaseState {
public:
  GameState(sf::RenderWindow *window);
  ~GameState();
  void processEvents() override;
  void draw() override;
  void update() override;

private:
  sf::RenderWindow *m_Window;  
};
