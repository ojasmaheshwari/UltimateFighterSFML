
#include "include/ImguiDebugger.h"
#include "include/DebuggerControlledInformation.h"
#include <imgui-SFML.h>
#include <imgui.h>

void showDebugWindow(sf::RenderWindow &window, sf::Clock &clock, DebuggerControlledInformation& DCI) {

	if (ImguiDebugger::logger.getClassName() == "Undefined") {
		ImguiDebugger::logger.setClassName("ImguiDebugger.cpp");
	}

  ImGui::SFML::Update(window, clock.restart());

	if (!ImGui::Begin("Debug Menu")) {
		ImguiDebugger::logger.error("Unable to push ImGui window to the stack. ImGui::Begin() failed");
	}

	ImGui::SliderFloat2("Fighter_1 position", &(DCI.fighter_1_pos->x), 0.0f, 500.0f);
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / DCI.io->Framerate, DCI.io->Framerate);

	ImGui::End();

}

