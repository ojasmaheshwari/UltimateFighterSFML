#pragma once

#include "../BaseState.h"
#include "../utils/Logging.h"

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Audio.hpp>

class Game;

class MainMenuState : public BaseState {
public:
  MainMenuState(sf::RenderWindow *window, Game *game);
  ~MainMenuState();
  void processEvents(sf::Event &event) override;
  void draw() override;
  void update() override;
  void closeState() override;

  void removeChoiceStyling(uint32_t index);
  void addChoiceStyling(uint32_t index);
  void moveChoiceDown();
  void moveChoiceUp();
  void doAction(uint32_t index);

private:
  sf::RenderWindow *m_Window;
  Game* m_Game;
  sf::RectangleShape m_Background;
  sf::Texture m_BackgroundTexture;
  sf::Font m_MenuFont;
  sf::Text m_MenuHeading;
  sf::Music m_MenuBgMusic;
  sf::SoundBuffer m_MenuChoiceChangeSoundBuffer;
  sf::Sound m_MenuChoiceChangeSound;
  Logging m_Logger;
  uint32_t m_SelectedChoiceIndex;
  uint32_t m_ChoiceCount;

  sf::Text m_MenuChoices[3];
};
