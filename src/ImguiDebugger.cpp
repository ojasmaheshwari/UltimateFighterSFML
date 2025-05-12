
#include "include/ImguiDebugger.h"
#include <imgui-SFML.h>
#include <imgui.h>

void showDebugWindow(sf::RenderWindow &window, sf::Clock &clock) {
#ifdef DEBUG

	if (ImguiDebugger::logger.getClassName() == "Undefined") {
		ImguiDebugger::logger.setClassName("ImguiDebugger.cpp");
	}

  ImGui::SFML::Update(window, clock.restart());

	if (!ImGui::Begin("Debug Menu")) {
		ImguiDebugger::logger.error("Unable to push ImGui window to the stack. ImGui::Begin() failed");
	}

	ImGui::Button("Look at this pretty button");

	ImGui::End();

#endif
}

