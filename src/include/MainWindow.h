#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdint>

class MainWindow : public sf::RenderWindow {
public:
  MainWindow();
  MainWindow(const uint32_t width, const uint32_t height, const std::string &title);

};
