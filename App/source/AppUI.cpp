#include "AppUI.h"
#include "imgui.h"
#include "raylib.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"
#include "Globals.h"

void AppUI::Shutdown()
{
	CloseWindow();
}

void AppUI::Setup()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);
	InitWindow(800, 600, "App");
	rlImGuiSetup();
	SetWindowMinSize(800, 600);

	// get current monitor resolution
	int screenWidth = GetMonitorWidth(0);
	int screenHeight = GetMonitorHeight(0);

	// set window resolution
	SetWindowSize((screenWidth / 1.5f), (screenHeight / 1.5f));
}

void AppUI::Tick(float DeltaTime)
{
	if (WindowShouldClose())
	{
		_Globals.WantsToQuit = true;
	}
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
