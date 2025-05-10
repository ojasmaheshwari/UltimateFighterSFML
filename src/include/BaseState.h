#pragma once

#include <SFML/Window/Event.hpp>
class BaseState {
public:
  virtual ~BaseState();
  virtual void processEvents(const sf::Event &event) = 0;
  virtual void draw() = 0;
  virtual void update() = 0;
  virtual void closeState() = 0;
};
