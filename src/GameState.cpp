#include "include/States/GameState.h"

#include "imgui.h"
#include "include/Game.h"
#include "include/ImguiDebugger.h"
#include "include/utils/Logging.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <format>

#include <imgui-SFML.h>

#include "include/DebuggerControlledInformation.h"

GameState::GameState(sf::RenderWindow *window, Game *game)
    : m_Window(window), m_Game(game),
      m_ArenaBackground((sf::Vector2f)m_Window->getSize()),
      m_ArenaGround({(float)m_Window->getSize().x, 60}),
      m_Logger(LoggingLevel::LogLevelInfo, "GameState"),
			m_Fighter1(m_Fighter1Texture),
			m_ImGuiIO(ImGui::GetIO())
{
	m_Window->setFramerateLimit(60);

  if (!m_ArenaTexture.loadFromFile("assets/arena_background.jpg")) {
    m_Logger.error("Unable to load resource: assets/arena_background.jpg");
  }
  m_ArenaBackground.setTexture(&m_ArenaTexture);

  if (!m_Fighter1Texture.loadFromFile("assets/fighter_1_sprite.png")) {
    m_Logger.error("Unable to load resource: assets/fighter_1_sprite.png");
  }

	m_ArenaGround.setFillColor(sf::Color::Transparent);
  m_ArenaGround.setPosition({0,
                            m_Window->getSize().y - m_ArenaGround.getSize().y});

  sf::Vector2u fighter1TextureSize = m_Fighter1Texture.getSize();
  fighter1TextureSize.x /= 12;
	fighter1TextureSize.x -= 3;

	fighter1TextureSize.y /= 5;
	fighter1TextureSize.y -= 12;

	m_Fighter1.setScale({4.0f, 4.0f});
  m_Fighter1.setTexture(m_Fighter1Texture);
  m_Fighter1.setTextureRect(
      sf::IntRect({static_cast<int>(fighter1TextureSize.x * 0), static_cast<int>(fighter1TextureSize.y * 0)},
									{static_cast<int>(fighter1TextureSize.x), static_cast<int>(fighter1TextureSize.y)}));
	
	m_Fighter1Pos = { 60, m_ArenaGround.getPosition().y - m_Fighter1.getGlobalBounds().size.y };

  m_Fighter1.setPosition(m_Fighter1Pos);

  m_Logger.info(std::format("Global bounds are {}x{}, local bounds are {}x{}",
                            m_Fighter1.getGlobalBounds().size.x,
                            m_Fighter1.getGlobalBounds().size.y,
                            m_Fighter1.getLocalBounds().size.x,
                            m_Fighter1.getLocalBounds().size.y));

	m_DCI.fighter_1_pos = &m_Fighter1Pos;
	m_DCI.io = &m_ImGuiIO;
}

GameState::~GameState() {}

void GameState::draw() {
	showDebugWindow(*m_Window, m_DeltaClock, m_DCI);

	m_Fighter1.setPosition(m_Fighter1Pos);

  m_Window->draw(m_ArenaBackground);
  m_Window->draw(m_Fighter1);
  m_Window->draw(m_ArenaGround);

#ifdef DEBUG
	ImGui::SFML::Render(*m_Window);
#endif
}
void GameState::update() {}
void GameState::processEvents(const sf::Event &event) {}

void GameState::closeState() {}
