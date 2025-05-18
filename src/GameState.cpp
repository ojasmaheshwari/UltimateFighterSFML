#include "include/States/GameState.h"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Sleep.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "imgui.h"
#include "include/Game.h"
#include "include/ImguiDebugger.h"
#include "include/utils/Logging.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <format>

#include <imgui-SFML.h>

#include "include/DebuggerControlledInformation.h"

#include <chrono>

static sf::Time dt;

GameState::GameState(sf::RenderWindow *window, Game *game)
    : m_Window(window), m_Game(game),
      m_ArenaBackground((sf::Vector2f)m_Window->getSize()),
      m_ArenaGround({(float)m_Window->getSize().x, 60}),
      m_Logger(LoggingLevel::LogLevelInfo, "GameState"),
			m_Fighter1(m_Fighter1Texture),
			m_ImGuiIO(ImGui::GetIO())
{
	m_Window->setFramerateLimit(60);

	m_dMovement.right = 20.0f;
	m_dMovement.left = 20.0f;
	m_dMovement.up = 0.0f;
	m_dMovement.down = 0.0f;

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

void GameState::processEvents(const sf::Event &event) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		m_Fighter1Pos.x += m_dMovement.right;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		m_Fighter1Pos.x -= m_dMovement.left;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) {
		Attack(m_Fighter1, m_Fighter1Texture, 2, 0, 12, 5);
	}
}

void GameState::Attack(sf::Sprite &player, sf::Texture &textureSheet, int x_index, int y_index, int num_x, int num_y, int duration, int damage) {
	sf::Vector2 TextureSize = textureSheet.getSize();
	TextureSize.x /= num_x;
	TextureSize.x -= 3;

	TextureSize.y /= num_y;
	TextureSize.y -= 12;

  m_Fighter1.setTexture(textureSheet);
	m_Fighter1.setTextureRect(
		sf::IntRect(
			{static_cast<int>(TextureSize.x * x_index), static_cast<int>(TextureSize.y * y_index)},
			{static_cast<int>(player.getLocalBounds().size.x), static_cast<int>(player.getLocalBounds().size.y)}
		)
	);

	dt = m_DeltaClock.getElapsedTime();

	while (m_DeltaClock.getElapsedTime() - dt < sf::Time(sf::milliseconds(1000))) {
	}

  m_Fighter1.setTexture(textureSheet);
	m_Fighter1.setTextureRect(
		sf::IntRect(
			{static_cast<int>(TextureSize.x * 0), static_cast<int>(TextureSize.y * 0)},
			{static_cast<int>(player.getLocalBounds().size.x), static_cast<int>(player.getLocalBounds().size.y)}
		)
	);

}

void GameState::closeState() {}
