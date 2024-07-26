#include "include/States/MainMenuState.h"

#include <SFML/Graphics/RenderWindow.hpp>

MainMenuState::MainMenuState(sf::RenderWindow *window)
  :m_Window(window)
{}
MainMenuState::~MainMenuState() {}

void MainMenuState::processEvents() {
}
void MainMenuState::draw() {
  m_Window->clear(sf::Color::Red);
}
void MainMenuState::update() {
}
