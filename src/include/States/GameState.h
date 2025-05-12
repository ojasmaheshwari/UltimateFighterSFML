#pragma once

#include "../BaseState.h"
#include "../utils/Logging.h"
#include "SFML/System/Vector2.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "../DebuggerControlledInformation.h"
#include "imgui.h"

class Game;

class GameState : public BaseState {
public:
  GameState(sf::RenderWindow *window, Game *game);
  ~GameState();
  void processEvents(const sf::Event &event) override;
  void draw() override;
  void update() override;
  void closeState() override;

private:
  sf::RenderWindow *m_Window;
  Game* m_Game;
  sf::RectangleShape m_ArenaBackground;
  sf::RectangleShape m_ArenaGround;
  sf::Texture m_ArenaTexture;
  Logging m_Logger;
  sf::Sprite m_Fighter1;
  sf::Texture m_Fighter1Texture;
  sf::Texture m_ArenaGroundTexture;
	sf::Clock m_DeltaClock;

	sf::Vector2f m_Fighter1Pos;
	DebuggerControlledInformation m_DCI;

	ImGuiIO &m_ImGuiIO;
};
