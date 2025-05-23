#pragma once

#include <DebuggerControlledInformation.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <utils/Logging.h>

namespace ImguiDebugger {
	static Logging logger;
}

void showDebugWindow(sf::RenderWindow &window, sf::Clock &deltaClock, DebuggerControlledInformation &DCI);
