#include "AppUI.h"
#include "imgui.h"
#include "raylib.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"
#include "Globals.h"

void AppUI::Shutdown()
{
}

void AppUI::Setup()
{
	SetWindowTitle("App");
	SetWindowMinSize(800, 600);

	// get current monitor resolution
	int screenWidth = GetMonitorWidth(0);
	int screenHeight = GetMonitorHeight(0);

	// set window resolution
	SetWindowSize((screenWidth / 1.5f), (screenHeight / 1.5f));
}

void AppUI::Tick(float DeltaTime)
{
}

void AppUI::Show()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
				_Globals.WantsToQuit = true;
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
	
	ImGui::ShowDemoWindow();
}
