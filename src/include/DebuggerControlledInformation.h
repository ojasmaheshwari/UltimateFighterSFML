#pragma once

#include "SFML/System/Vector2.hpp"
#include "imgui.h"

struct DebuggerControlledInformation {
	sf::Vector2f* fighter_1_pos;
	ImGuiIO* io;
};
