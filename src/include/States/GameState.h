#pragma once

#include "../BaseState.h"
#include "../utils/Logging.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>


class Game;

class GameState : public BaseState {
public:
  GameState(sf::RenderWindow *window, Game *game);
  ~GameState();
  void processEvents(sf::Event &event) override;
  void draw() override;
  void update() override;
  void closeState() override;

private:
  sf::RenderWindow *m_Window;
  Game* m_Game;
  sf::RectangleShape m_ArenaBackground;
  sf::Texture m_ArenaTexture;
  Logging m_Logger;
  sf::Sprite m_Fighter1;
  sf::Texture m_Fighter1Texture;
};
