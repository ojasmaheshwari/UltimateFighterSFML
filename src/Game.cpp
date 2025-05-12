#include "include/Game.h"
#include "SFML/Window/Window.hpp"
#include "include/ImguiDebugger.h"
#include "include/StateManager.h"
#include "include/States/GameState.h"
#include "include/States/MainMenuState.h"
#include "include/utils/Logging.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <imgui.h>
#include <imgui-SFML.h>

Game::Game()
    : m_Window(1000, 550, "Ultimate Fighter 2024"), m_Running(true),
      m_Logger(LoggingLevel::LogLevelInfo, "Game")
{
	m_Window.setFramerateLimit(60);

  m_Logger.log("Initialized main window");

  m_MainMenu = new MainMenuState(&m_Window, this);
  m_Logger.log("Created main menu state");

  m_StateManager.switchState(m_MainMenu);
  m_Logger.log("State switced to main menu");

	if (ImGui::SFML::Init(m_Window)) {
		m_Logger.info("ImGui SFML successfully initialized!");
	} else {
		m_Logger.error("ImGui SFML initialization failed!");
	}
}

Game::~Game() { m_Logger.log("Destroying Game"); }

bool Game::isRunning() const { return m_Running; }

void Game::quit() {
  if (m_Window.isOpen())
    m_Window.close();
  m_Running = false;

  m_Logger.log("Main window closed.");
}

void Game::update() { m_StateManager.getCurrentState()->update(); }

void Game::draw() {
  m_Window.clear();
  m_StateManager.getCurrentState()->draw();

  m_Window.display();
}

void Game::processEvents() {
  while (const std::optional event = m_Window.pollEvent()) {
		ImGui::SFML::ProcessEvent(m_Window, *event);

    m_StateManager.getCurrentState()->processEvents(*event);

    if (event->is<sf::Event::Closed>()) {
      quit();
    }
  }
}

void Game::moveToPlayArena() {
  m_GameState = new GameState(&m_Window, this);
  m_StateManager.switchState(m_GameState);
  m_Logger.info("Moved to play arena");
}
