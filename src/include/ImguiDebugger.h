#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "utils/Logging.h"

namespace ImguiDebugger {
	static Logging logger;
}

void showDebugWindow(sf::RenderWindow &window, sf::Clock &deltaClock);
