#include "include/MainWindow.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

MainWindow::MainWindow() {}
MainWindow::MainWindow(const uint32_t width, const uint32_t height, const std::string &title)
  : sf::RenderWindow(sf::VideoMode({width, height}), title)
  {}
