#include "include/Game.h"
#include "include/StateManager.h"
#include "include/States/GameState.h"
#include "include/States/MainMenuState.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <iostream>

Game::Game()
  :m_Window(1000, 550, "Ultimate Fighter 2024")
{
  m_MainMenu = new MainMenuState(&m_Window);
  m_StateManager.switchState(m_MainMenu);
}

Game::~Game() {}

bool Game::isRunning() const {
  return m_Running;
}

void Game::quit() {
  if (m_Window.isOpen())
    m_Window.close();
  m_Running = false;
}

void Game::update() {
  m_StateManager.update();
}

void Game::draw() {
  m_Window.clear();
  m_StateManager.draw();
  m_Window.display();
}

void Game::processEvents() {
  while (m_Window.pollEvent(m_MainEvent)) {
    switch(m_MainEvent.type) {
      case sf::Event::Closed:
        quit();
        break;
      default:
        break;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)) {
      GameState *game = new GameState(&m_Window);
      m_StateManager.switchState(game);
    }
  }
}

