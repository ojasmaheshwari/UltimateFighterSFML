#include "include/States/GameState.h"

#include "include/Game.h"
#include "include/utils/Logging.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <cmath>

#include <format>

GameState::GameState(sf::RenderWindow *window, Game *game)
  :m_Window(window), m_Game(game), m_ArenaBackground((sf::Vector2f)m_Window->getSize()), m_ArenaGround({(float)m_Window->getSize().x, 71}), m_Logger(LoggingLevel::LogLevelInfo, "GameState")
{
  if (!m_ArenaTexture.loadFromFile("assets/arena_background.png")) {
    m_Logger.error("Unable to load resource: assets/arena_background.png");
  }
  m_ArenaBackground.setTexture(&m_ArenaTexture);

  if (!m_Fighter1Texture.loadFromFile("assets/fighter_1_sprite.png")) {
    m_Logger.error("Unable to load resource: assets/fighter_1_sprite.png");
  }

  sf::Vector2u fighter1TextureSize = m_Fighter1Texture.getSize();
  fighter1TextureSize.x /= 4;
  
  m_Fighter1.setTexture(m_Fighter1Texture);    
  m_Fighter1.setTextureRect(sf::IntRect(fighter1TextureSize.x * 0, fighter1TextureSize.y * 0, fighter1TextureSize.x, fighter1TextureSize.y));
  // m_Fighter1.setPosition(22, m_Window->getSize().y - 66);
  m_Fighter1.setPosition(0, m_Window->getSize().y - m_ArenaGround.getSize().y - m_Fighter1.getLocalBounds().getSize().y + 10);
  m_Logger.info(std::format("Global bounds are {}x{}, local bounds are {}x{}", m_Fighter1.getGlobalBounds().getSize().x, m_Fighter1.getGlobalBounds().getSize().y, m_Fighter1.getLocalBounds().getSize().x, m_Fighter1.getLocalBounds().getSize().y));

  m_ArenaGroundTexture.loadFromFile("assets/arena_ground.png");
  m_ArenaGround.setTexture(&m_ArenaGroundTexture);
  m_ArenaGround.setPosition(0, m_Window->getSize().y - m_ArenaGround.getSize().y);
}
GameState::~GameState() {}

void GameState::draw() {
  m_Window->draw(m_ArenaBackground);
  m_Window->draw(m_Fighter1);
  m_Window->draw(m_ArenaGround);
}
void GameState::update() {
}
void GameState::processEvents(sf::Event &event) {}

void GameState::closeState() {}
