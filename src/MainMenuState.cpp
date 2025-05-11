#include "include/States/MainMenuState.h"
#include "include/utils/Logging.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdint>

#include "include/Game.h"

MainMenuState::MainMenuState(sf::RenderWindow *window, Game *game)
    : m_Window(window), m_Game(game),
      m_Background((sf::Vector2f)m_Window->getSize()),
      m_Logger(LoggingLevel::LogLevelInfo, "MainMenuState"),
			m_MenuFont("assets/fonts/roboto-basic.ttf"),
      m_MenuHeading(m_MenuFont, "Main Menu", 100),
			m_MenuChoiceChangeSound(m_MenuChoiceChangeSoundBuffer)
{
	m_MenuChoices = {{
    sf::Text(m_MenuFont, "Play", 60),
    sf::Text(m_MenuFont, "Help", 60),
    sf::Text(m_MenuFont, "Quit", 60),
	}};

  if (!m_BackgroundTexture.loadFromFile("assets/menu_background.jpg")) {
    m_Logger.error("Unable to load resource: assets/menu_background.jpg");
  }

  m_Background.setTexture(&m_BackgroundTexture);
  m_Logger.log("Set menu background");

  if (!m_MenuFont.openFromFile("assets/fonts/roboto-basic.ttf")) {
    m_Logger.error("Unable to load resource: assets/fonts/roboto-basic.ttf");
  }

  m_MenuHeading.setOrigin(m_MenuHeading.getGlobalBounds().size / 2.f);
  m_MenuHeading.setPosition({m_Window->getSize().x / 2.f,
                            (10 / 100.0f) * m_Window->getSize().y});

  uint32_t initialChoiceY = (50 / 100.0f) * m_Window->getSize().y;
  uint32_t gapBetweenChoices = 100;
  m_ChoiceCount = 3;
  m_SelectedChoiceIndex = 0;
  for (uint32_t i = 0; i < m_ChoiceCount; i++) {
  	m_MenuChoices->at(i).setOrigin(m_MenuChoices->at(i).getGlobalBounds().size /
                               2.f);

    m_MenuChoices->at(i).setPosition({
				(20 / 100.0f) * m_Window->getSize().x,
				static_cast<float>(initialChoiceY + i * gapBetweenChoices)
		});
  }

  m_MenuChoices->at(m_SelectedChoiceIndex).setFillColor(sf::Color::Red);

  m_Logger.info("Set menu choices");

  if (!m_MenuBgMusic.openFromFile("assets/menu_bg_music.mp3")) {
    m_Logger.error("Could not load resource: assets/menu_bg_music.mp3");
  }
  m_MenuBgMusic.play();

  if (!m_MenuChoiceChangeSoundBuffer.loadFromFile(
          "assets/menu_choice_change.mp3")) {
    m_Logger.error("Could not load resource: assets/menu_choice_change.mp3");
  }
  m_MenuChoiceChangeSound.setBuffer(m_MenuChoiceChangeSoundBuffer);
}

MainMenuState::~MainMenuState() {}

void MainMenuState::processEvents(const sf::Event &event) {
	if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
		const auto key = keyPressed->scancode;
		using KeyCode = sf::Keyboard::Scancode;

		if (key == KeyCode::Down) {
			moveChoiceDown();
		} else if (key == KeyCode::Up) {
			moveChoiceUp();
		} else if (key == KeyCode::Enter) {
			doAction(m_SelectedChoiceIndex);
		}
	} else {
	}

}

void MainMenuState::draw() {
  m_Window->draw(m_Background);
		m_Window->draw(m_MenuHeading);

  for (auto &menuChoice : *m_MenuChoices) {
    m_Window->draw(menuChoice);
  }
}

void MainMenuState::update() {}

void MainMenuState::removeChoiceStyling(uint32_t index) {
  if (index < 0 || index >= m_ChoiceCount) {
    m_Logger.error("Tried to remove out-of-bounds choice");
    return;
  }

  sf::Text &currentSelectedChoice = m_MenuChoices->at(index);
  currentSelectedChoice.setFillColor(sf::Color::White);
}

void MainMenuState::addChoiceStyling(uint32_t index) {
  if (index < 0 || index >= m_ChoiceCount) {
    m_Logger.error("Tried to remove out-of-bounds choice");
    return;
  }

  sf::Text &currentSelectedChoice = m_MenuChoices->at(index);
  currentSelectedChoice.setFillColor(sf::Color::Red);
}

void MainMenuState::moveChoiceDown() {
  m_MenuChoiceChangeSound.play();
  removeChoiceStyling(m_SelectedChoiceIndex);

  if (m_SelectedChoiceIndex == m_ChoiceCount - 1) {
    m_SelectedChoiceIndex = 0;
  } else {
    m_SelectedChoiceIndex++;
  }

  addChoiceStyling(m_SelectedChoiceIndex);
}

void MainMenuState::moveChoiceUp() {
  m_MenuChoiceChangeSound.play();
  removeChoiceStyling(m_SelectedChoiceIndex);

  if (m_SelectedChoiceIndex == 0) {
    m_SelectedChoiceIndex = m_ChoiceCount - 1;
  } else {
    m_SelectedChoiceIndex--;
  }

  addChoiceStyling(m_SelectedChoiceIndex);
}

void MainMenuState::doAction(uint32_t index) {
  if (index < 0 || index >= m_ChoiceCount) {
    m_Logger.error("Tried to remove out-of-bounds choice");
    return;
  }

  sf::Text &action = m_MenuChoices->at(index);

  if (action.getString() == "Play") {
    m_Game->moveToPlayArena();
  } else if (action.getString() == "Help") {

  } else if (action.getString() == "Quit") {
    m_Game->quit();
  } else {
    m_Logger.error("Action not implemented, skipping");
  }
}

void MainMenuState::closeState() {}
