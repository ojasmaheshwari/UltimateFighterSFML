#include "include/States/GameState.h"


GameState::GameState(sf::RenderWindow *window)
  :m_Window(window)
{}
GameState::~GameState() {}

void GameState::draw() {
  m_Window->clear(sf::Color::Blue);
}
void GameState::update() {
}
void GameState::processEvents() {}
